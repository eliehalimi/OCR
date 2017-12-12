/* 
 * nnet_prototype.h : header containing both basic structures 
 * of the neural network will be used by main
*/

#ifndef NNET_PROTOTYPE_H_
#define NNET_PROTOTYPE_H_

#include <stdio.h>
#include <stdlib.h>

/* Structure of a sigmoid neurone of the neural network */

struct Sig_Neuron
{
  /* Initialized by net_init */ 
	// mandatory for weights[] to be last in struct definition
  double bias;
  double* weights_begin;
  double* weights_end;
  
  /* Computed during feedforward */
  double output;
  
  /* Computed during success_and_errors or backpropagation */
  double error;
  
};

/* Structure of the feedforward neural network using a cross-entropy
 * cost function.*/

struct Neural_Net
{
  /* given as arguments */
  size_t* sizes_begin;
  size_t* sizes_end;
  
  /* initialized at creation */
  struct Sig_Neuron* layers_begin;
  struct Sig_Neuron* layers_end;
  
  /* computed during success_and_errors */
  double tot_error;
};

#endif
