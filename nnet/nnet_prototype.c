/* nnet_prototype.c : This is the prototype for our neural network.To be clear, this is where the base struct is saved not where the whole network. */

#include <stdio.h>
#include <stdlib.h>
#include "nnet_functions.h"
#include "nnet_prototype.h"


/* Initializes a new neural network.
   Inputs : list of layers' sizes and number of hidden layers*/

Neural_Net init(size_t* sizes_begin, size_t* sizes_end) {
  Neural_Net nnet;
  nnet.sizes_begin=sizes_begin;
  nnet.sizes_end=sizes_end;
  size_t sum_sizes=0;
  for(size_t i=0;i<sizes_end-sizes_begin,i++) {
    sum_sizes += *(sizes_begin+i);
  }
  // Allocates the memory for the whole network by allocating the size of neuron * the total number of neuron in the network */
  nnet.layers_begin = (Sig_Neuron*) malloc(sizeof(Sig_Neuron)*sum_sizes);
  nnet.layers_end = layers_begin+sum_sizes;
  net_init(nnet);
  return nnet;
}

/* loads the text file containing the neural network Neural_Net load_net(char *path) {
  FILE *f = fopen(path, "r");
  if (f == NULL) {
    printf("Error opening file! (File not found)\n");
    exit(1);
  }
  char *c;
  size_t;
  while(fscanf(f, "%c", &c) != EOF) {
    
  }
  fclose(f);
}

   Trains a neural network.
   Inputs : training_data = list of inputs converted to double arrays, expect_data  list of correct data also converted and eta=learning rate */ 

void training(Neural_Net nnet, size_t epochs, double* training_data_begin, double* expect_data_begin, double eta) {
  for(int times=0;times<epochs;times++) {
    feedforward(nnet,training_data_begin + times * *(nnet.sizes_begin));
    success_and_errors(nnet,expect_data_begin + times * *(nnet.sizes_end-1));
    backprop(nnet);
    change_weight(nnet,eta);
  }
}


/* saves the neural network into a text file 
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
*/

