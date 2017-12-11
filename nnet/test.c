
#include <stdio.h>
#include <stdlib.h>
#include "nnet_prototype.h"
#include "nnet_init.h"
//#include "../save/save_file.h"

double* generate_input(size_t epochs, size_t* size_begin,double* expected_begin)
{
	
}

char convert_result(double* output)
{
  for()
}

int main()
{
	printf("%zu\n", sizeof(struct Sig_Neuron));
	size_t epochs = 20;
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
	struct Neural_Net* nnet = init(sizes_begin, sizes_end);
	training(nnet, epochs, input_begin, expected_begin, eta);
	free_nnet(nnet);
        //free(sizes_begin);
       // free(expected_begin);
       // free(nnet);
	//savennet(nnet, "saved.txt");
	return 0;
}
