/* nnet_prototype.h : header for nnet_prototype.c will be used by main */

#ifndef NNET_PROTOTYPE_H_
#define NNET_PROTOTYPE_H_

#include <stdio.h>
#include <stdlib.h>


/* Initializes a new neural network.
   Inputs : list of layers' sizes and number of hidden layers*/

void init(int sizes[], int hidden);


/* loads the text file containing the neural network */

void load_net(char *path);


/* Trains a neural network.
   Inputs : training_data = list of inputs converted to double arrays, expect_data  list of correct data also converted and eta=learning rate */ 

void training(Neural_Net nnet, int epochs, double training_data[][], double expect_data[][],int training_size, double eta, char *path);


/* saves the neural network into a text file */

void save_net(char path[], Neural_Net nnet);



/* Structure of a sigmoid neurone of the neural network */

typedef struct {
  /* Computed during feedforward */
  double output;
  /* Computed during backpropagation */
  double error;
  /* Initialized by net_init */ // mandatory for weights[] to be last in struct definition.
  double bias;
  double weights[];
}Sig_Neuron;

/* Structure of the feedforward neural network using a cross-entropy cost function.*/

typedef struct {
  /* given as arguments */
  int* sizes_begin;
  int* sizes_end;
  int hidden;
  /* initialized at creation */
  Sig_Neuron* layers_begin;
  Sig_Neuron* layers_end;
  /* computed during success_and_errors */
  double tot_error;
}Neural_Net;

# endif
