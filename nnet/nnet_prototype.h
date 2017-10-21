/* nnet_prototype.h : header for nnet_prototype.c will be used by main */

#ifndef NNET_PROTOTYPE_H_
#define NNET_PROTOTYPE_H_

#include <stdio.h>
#include <stdlib.h>

typeof struct {
  double bias;
 
  double pre_weights[];
  Sig_Neuron pre_linked[];
  double size_pre_w;
  
  double back_weights[];
  Sig_Neuron back_linked[];
  double size_back_w;

  double new_weight;
  double output;
  double error[];
}Sig_Neuron;
/* Base structure of the feedforward neural network using a cross-entropy cost function.*/

typeof struct {
  int sizes[];
  int hidden;

  Sig_Neuron input_layer[sizes[0]];
  Sig_Neuron hidden_layers[hidden][];
  for(i=0;i<hidden;i++) {
    hidden_layers[i]=Sig_Neuron[sizes[i+1]];
  }
  
  Sig_Neuron output_layer[sizes[hidden+1]];
}Neural_Net;

# endif
