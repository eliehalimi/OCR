/* nnet_prototype.h : header for nnet_prototype.c will be used by main */

#ifndef NNET_INIT_H_
#define NNET_INIT_H_
//#ifndef NNET_PROTOTYPE_H_			NNET_PROTOTYPE is already initialized hence never initializes init not training 
//#define NNET_PROTOTYPE_H_		


#include <stdio.h>
#include <stdlib.h>
#include "nnet_prototype.h"

/* Structure of a sigmoid neurone of the neural network */

/* Initializes a new neural network.
   Inputs : list of layers' sizes and number of hidden layers*/

struct Neural_Net* init(size_t* sizes_begin, size_t* sizes_end);


// Frees the neural network pointed by nnet

void free_nnet(struct Neural_Net *nnet);

#endif

