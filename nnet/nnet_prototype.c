/* nnet_prototype.c : This is the prototype for our neural network.To be clear, this is where the base struct is saved not where the whole network. */

#include <stdio.h>
#include <stdlib.h>
#include "nnet_functions.h"

/* Initializes a new neural network.
   Inputs : list of layers' sizes and number of hidden layers*/

void init(size_t* sizes_begin, size_t* sizes_end, Sig_Neuron* layers_begin,int hidden) {
  Neural_Net nnet;
  nnet.sizes_begin=sizes_begin;
  nnet.sizes_end=sizes_end;
  size_t sum_sizes=0;
  for(size_t i=0;i<sizes_end-sizes_begin,i++) {
    sum_sizes += *sizes_begin+1;
  }
  nnet.layers_begin=layers_begin;
  nnet.layers_end=layers_begin+sum_sizes*sizeof(Sig_Neuron);
  net_init(nnet);
}

/* loads the text file containing the neural network */
void load_net(char *path) {
	
	FILE *f = fopen(path, "r");
	if (f == NULL)
	{
		printf("Error opening file! (File not found)\n");
		exit(1);
	}
	char *c;
	int counter = 0;
	int hidden = 0;
	int sizes[];
	int *size; 
	size = sizes;
	while(fscanf(f, "%s", &c) != EOF)
	{
		if (counter == 0)
			hidden = (int)c;
			counter +=1;
		if (hidden != 0)
		{
			*(size +counter-1) = (int)c;		
		}
	}
	fclose(f);
	init(sizes, hidden);
}

/* Trains a neural network.
   Inputs : training_data = list of inputs converted to double arrays, expect_data  list of correct data also converted and eta=learning rate */ 

void training(Neural_Net nnet, int epochs, double training_data[][], double expect_data[][],int training_size, double eta, char *path) {
  double cost;
  for(int times=0;times<epochs;times++) {
    double output[nnet.sizes[nnet.hidden+1]];
    feedforward(nnet,training_data[times]);
    success_and_errors(nnet,expect_data[times]);
    backprop(nnet);
    change_weight(nnet,eta);
  }
}


/* saves the neural network into a text file */
void save_net(char path[], Neural_Net nnet) 
{
	FILE *f = fopen(path, "w+");
	if (f == NULL)
	{
		printf("Error opening file! (file not found)\n"); //should never happen since I am using w+
		exit();
	}
	for (int i =0; i< nnet.sizes;++i)
		fprintf(f,"%s", nnet.size[i]);
	fprintf(f, "%s", nnet.hidden);
	fclose(f);
}

