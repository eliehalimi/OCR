
#include <stdio.h>
#include <stdlib.h>
#include "nnet_prototype.h"
#include "nnet_init.h"
#include "../save/save_file.h"

double* generate_input(size_t epochs, size_t* size_begin,double* expected_begin)
{
	int j;
 	double* input_begin = (double*) malloc(sizeof(double)* epochs * *(size_begin)); 
  	for(size_t i = 0; i < epochs; i++)
       	{
		j=rand() % 8;
    		switch(j)
	       	{
			case (0):
      				*(input_begin+i*3)=1;
      				*(input_begin+i*3+1)=0;
      				*(input_begin+i*3+2)=1;
      				*(expected_begin+i*3)=0;
      				*(expected_begin+i*3+1)=0;
      				*(expected_begin+i*3+2)=0;
      				break;
      
    			case (1):
      				*(input_begin+i*3)=0;
      				*(input_begin+i*3+1)=0;
      				*(input_begin+i*3+2)=1;
      				*(expected_begin+i*3)=0;
      				*(expected_begin+i*3+1)=0;
      				*(expected_begin+i*3+2)=1;
      				break;
      
    			case (2):
      				*(input_begin+i*3)=1;
      				*(input_begin+i*3+1)=0;
      				*(input_begin+i*3+2)=0;
      				*(expected_begin+i*3)=0;
      				*(expected_begin+i*3+1)=1;
      				*(expected_begin+i*3+2)=0;
      				break;
      
    			case (3):
      				*(input_begin+i*3)=0;
      				*(input_begin+i*3+1)=1;
      				*(input_begin+i*3+2)=0;
      				*(expected_begin+i*3)=0;
      				*(expected_begin+i*3+1)=1;
      				*(expected_begin+i*3+2)=1;
      				break;

    			case (4):
      				*(input_begin+i*3)=0;
      				*(input_begin+i*3+1)=0;
      				*(input_begin+i*3+2)=0;
      				*(expected_begin+i*3)=1;
      				*(expected_begin+i*3+1)=0;
      				*(expected_begin+i*3+2)=0;
      				break;

    			case (5):
      				*(input_begin+i*3)=1;
      				*(input_begin+i*3+1)=1;
      				*(input_begin+i*3+2)=1;
      				*(expected_begin+i*3)=1;
      				*(expected_begin+i*3+1)=0;
      				*(expected_begin+i*3+2)=1;
      				break;

    			case (6):
      				*(input_begin+i*3)=0;
      				*(input_begin+i*3+1)=1;
      				*(input_begin+i*3+2)=1;
      				*(expected_begin+i*3)=1;
      				*(expected_begin+i*3+1)=1;
      				*(expected_begin+i*3+2)=0;
      				break;

    			case (7):
      				*(input_begin+i*3)=1;
      				*(input_begin+i*3+1)=1;
      				*(input_begin+i*3+2)=0;
      				*(expected_begin+i*3)=1;
      				*(expected_begin+i*3+1)=1;
      				*(expected_begin+i*3+2)=1;
      				break;
    		}
  	}
  	return input_begin;
}

char convert_output()
{
  return '\0';
}

int main(int argc, char* argv)
{
	printf("%zu\n", sizeof(struct Sig_Neuron));
	size_t epochs = ;
	double eta = 1.5;
	size_t* sizes_begin = (size_t*) malloc(sizeof(size_t)*5);
	size_t* sizes_end = sizes_begin+5;
	*(sizes_begin) = 3;
  	*(sizes_begin+1) = 5;
  	*(sizes_begin+2) = 10;
  	*(sizes_begin+3) = 10;
  	*(sizes_begin+4) = 3;
  	double* expected_begin = (double*) malloc(sizeof(double) * epochs * *(sizes_end - 1));
  	double* input_begin = generate_input(epochs, sizes_begin, expected_begin);
        if(argv[0] == '1')
        {
          struct Neural_Net* = loadnnet(nnet,argv[1]);
        }
        else
        {
          struct Neural_Net* nnet = init(sizes_begin, sizes_end);
        }
	training(nnet, epochs, input_begin, expected_begin, eta);
        if(argv[0] == '1'
	savennet(nnet, "saved.txt");
	free_nnet(nnet);
        free(sizes_begin);
        free(expected_begin);
        free(input_begin);
        free(nnet);
	return 0;
}
