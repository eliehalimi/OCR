#include <stdio.h>
#include <stdlib.h>
#include "nnet_prototype.h"
#include "nnet_init.h"

double* generate_input(size_t epochs, size_t* size_begin,double* expected_begin)
{
	int j;
 	double* input_begin= malloc(sizeof(double)* epochs * *(size_begin)); 
  	for(size_t i=0;i<epochs;i++)
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



int main()
{
	printf("%zu\n", sizeof(struct Sig_Neuron));
	size_t epochs = 15;
	double eta = 10.0;
	size_t* sizes_begin = malloc(sizeof(size_t)*5);
	size_t* sizes_end = sizes_begin+5;
	*(sizes_begin) = 3;
  	*(sizes_begin+1) = 5;
  	*(sizes_begin+2) = 10;
  	*(sizes_begin+3) = 10;
  	*(sizes_begin+4) = 3;
  	double* expected_begin = malloc(sizeof(double) * epochs * *(sizes_end - 1));
	printf("%p\n", expected_begin);
	printf("%f\n", eta);
  	double* input_begin = generate_input(epochs,sizes_begin,expected_begin);
	printf("%p\n", input_begin);
	printf("%zu\n%zu\n", *sizes_begin, *sizes_end);
	printf("%zu\n", sizeof(struct Neural_Net));
	struct Neural_Net nnet = init(sizes_begin,sizes_end);
	printf("%zu\n", sizeof(nnet));
	
	return 0;
}

