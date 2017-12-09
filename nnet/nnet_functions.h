/* nnet_functions.h : header for nnet_functions.c will be called by nnet_prototype.c*/

#ifndef NNET_FUNCTIONS_H_
#define NNET_FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nnet_prototype.h"

/*-------------------------------Support functions-------------------------- */

/* Generates a double following normal distrubution with mean 0 and standard 
 * deviation 1. 
 * This allows the generation of random nunbers better suited for initial 
 * weights as they arefewer values very close to 1 0r 0.*/

double norm_dist();


/*Applies the sigmoid function σ on a value */
 
double sigmoid(double val);


/* Applies the derivative of the sigmoid function σ' on a value*/
/*
double sigmoid_prime(double val);
*/


/*-------------------------- Network functions-------------------------- */

/* Initializes the weights between the layer and prev_layer layers 
 * (each neuron of a layer is connected to all the neurons of the next layer).
 * This uses the norm_dist function to increase the training speed as it limits
 * the number of saturated neurons at the start of the training*/

void layer_init(struct Sig_Neuron* layer_begin, struct Sig_Neuron* 
		layer_end, struct Sig_Neuron* prev_layer_begin);


/* Initializes the network by iterating over the layer_init function*/

void net_init(struct Neural_Net *nnet);


/* Applies the Feedforward algorithm to a layer : Computes the output of 
 * each neuron in the layer using the sigmoid function, the bias of the 
 * neuron, the output of the neurones of the previous layer and the 
 * weights between the layer and prev_layer layers*/

void fflayer(struct Sig_Neuron* layer_begin, struct Sig_Neuron* 
		layer_end, struct Sig_Neuron* prev_layer_begin);


/* Applies the Feedforward algorithm to the network by iterating over 
 * the fflayer function. Takes a result array of size [hidden+1].*/

void feedforward(struct Neural_Net *nnet, double* input_begin);

/* Computes the total cost, the errors of the neuron of the last 
 * layers and the total error of the network */

/*double*/ void success_and_errors(struct Neural_Net *nnet, double* except_begin);


/* Computes and changes the error of all neurons in a layer */

void backprop_layer(struct Sig_Neuron* layer_begin, struct Sig_Neuron*
	       	layer_end, struct Sig_Neuron* next_layer_end, struct Sig_Neuron* next_layer_begin);
//added next layer_begin in function declaration

/* Computes and changes error of all neurons in the network 
 * by iterating over backprop_layer */

void backprop(struct Neural_Net *nnet);


/* Computes the new weights of all neurons in a layer and 
 * updates their weights */

void change_weight_layer(double eta,struct Sig_Neuron* layer_begin,
		struct Sig_Neuron* layer_end, struct Sig_Neuron* 
		next_layer_end);



/* Computes the new weights of all neurons in the network and updates their 
 * weights by iterating over change_weight_layer */

void change_weight(struct Neural_Net *nnet, double eta);

#endif
