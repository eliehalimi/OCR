/* nnet_prototype.h : header for nnet_prototype.c will be used by main */

#ifndef NNET_PROTOTYPE_H_
#define NNET_PROTOTYPE_H_

#include <stdio.h>
#include <stdlib.h>

typeof struct {
  double bias;
  double weight;
}Sig_Neuron;
/* Base structure of the feedforward neural network using a cross-entropy cost function.*/
typeof struct {
  int[] l_sizes;
  Sig_Neuron[] input_layer;
  Sig_Neuron[] output_layer
  Sig_Neuron[] hidden_layers;
}Neural_Net;

# endif
