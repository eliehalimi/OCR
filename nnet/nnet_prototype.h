/* nnet_prototype.h : header for nnet_prototype.c will be used by main */

#ifndef NNET_PROTOTYPE_H_
#define NNET_PROTOTYPE_H_

#include <stdio.h>
#include <stdlib.h>

/* Structure of a sigmoid neurone of the neural network */

typeof struct {
  /* Initialized by net_init */
  double bias; 
  double weights[];
  /* Computed during feedforward */
  double output;
  /* Computed during backpropagation */
  double error;
}Sig_Neuron;

/* Structure of the feedforward neural network using a cross-entropy cost function.*/

typeof struct {
  /* given as arguments */
  int sizes[];
  int hidden;
  /* initialized at creation */
  Sig_Neuron input_layer[sizes[0]];
  Sig_Neuron hidden_layers[hidden][];
  for(i=0;i<hidden;i++) {
    hidden_layers[i]=Sig_Neuron[sizes[i+1]];
  }
  Sig_Neuron output_layer[sizes[hidden+1]];
  /* computed during success_and_errors */
  double tot_error;
}Neural_Net;

# endif
