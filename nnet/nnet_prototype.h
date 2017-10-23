/* nnet_prototype.h : header for nnet_prototype.c will be used by main */

#ifndef NNET_PROTOTYPE_H_
#define NNET_PROTOTYPE_H_

#include <stdio.h>
#include <stdlib.h>

/* Structure of a sigmoid neurone of the neural network */

typedef struct {
  /* Initialized by net_init */ // mandatory for weights[] to be last in struct definition
  double bias;
  double* weights_begin;
  double* weights_end;
  
  /* Computed during feedforward */
  double output;
  
  /* Computed during success_and_errors or backpropagation */
  double error;
  
}Sig_Neuron;

/* Structure of the feedforward neural network using a cross-entropy cost function.*/

typedef struct {
  /* given as arguments */
  size_t* sizes_begin;
  size_t* sizes_end;
  
  /* initialized at creation */
  Sig_Neuron* layers_begin;
  Sig_Neuron* layers_end;
  
  /* computed during success_and_errors */
  double tot_error;
}Neural_Net;



/* Initializes a new neural network.
   Inputs : list of layers' sizes and number of hidden layers*/

Neural_Net init(size_t* sizes_begin, size_t* sizes_end);


/* loads the text file containing the neural network */

//void load_net(char *path);


/* Trains a neural network.
   Inputs : training_data = list of inputs converted to double arrays, expect_data  list of correct data also converted and eta=learning rate */ 

void training(Neural_Net nnet, size_t epochs, double* training_data_begin, double* expect_data_begin, int training_size, double eta);


/* saves the neural network into a text file */

//void save_net(char path[], Neural_Net nnet);



# endif
