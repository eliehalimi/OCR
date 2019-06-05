/* nnet_init.h : header file for nnet_init.c used by nnet_training*/

#ifndef NNET_INIT_H_
#define NNET_INIT_H_

#include <stdio.h>
#include <stdlib.h>
#include "nnet_prototype.h"

/* Initializes a new neural network.
   Inputs : list of layers' sizes and number of hidden layers*/

struct Neural_Net* init(size_t* sizes_begin, size_t* sizes_end);


// Frees the neural network pointed by nnet

void free_nnet(struct Neural_Net *nnet);

#endif
