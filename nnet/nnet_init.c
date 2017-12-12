/* 
 * nnet_init.c : Funtions for initializing and freeing the neural network
 */

#include <stdio.h>
#include <stdlib.h>
#include "nnet_init.h"
#include "nnet_functions.h"

// Initializes a new neural network.

struct Neural_Net* init(size_t* sizes_begin, size_t* sizes_end) {
  struct Neural_Net *nnet = (struct Neural_Net*) malloc(sizeof(struct Neural_Net));
  nnet->sizes_begin = sizes_begin;
  nnet->sizes_end = sizes_end;
  size_t sum_sizes=0;
  for(int i = 0;i < sizes_end - sizes_begin; i++) {
    sum_sizes += *(sizes_begin+i);
  }
  // Allocates the memory for the whole network by allocating the size of
  // neuron * the total number of neuron in the network */
  nnet->layers_begin = (struct Sig_Neuron*)
	  malloc(sizeof(struct Sig_Neuron) * sum_sizes);
  nnet->layers_end = nnet->layers_begin + sum_sizes;
  net_init(nnet);
  return nnet;
}

void free_nnet(struct Neural_Net *nnet)
{
  for(struct Sig_Neuron* lb = nnet->layers_begin; lb < nnet->layers_end; lb++)
    free(lb->weights_begin);
  free(nnet->layers_begin);
}
