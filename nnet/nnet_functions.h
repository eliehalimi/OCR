/* nnet_functions.h : header for nnet_functions.c will be called by nnet_prototype.c*/

#ifndef NNET_FUNCTIONS_H_
#define NNET_FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>

/* Generates a double following normal distrubution with mean 0 and standard deviation 1. This allows the generation of random nunbers better suited for initial weights as they arefewer values very close to 1 0r 0.*/

double norm_dist();


/*Applies the sigmoid function σ on a value */
 
double sigmoid(double val);


/* Applies the derivative of the sigmoid function σ' on a value*/

double sigmoid_prime(double val)


/* Computes the cost associated with an output and its expected value using the cross-entropy cost function Cce */

double cross_entropy(int size,double output[], double expect[]);


/* Computes the error associated with the cost function by subtracting the to matrices.*/

void error(int size,double output[], double expect[], double res[]);



/* Initializes the weights between the layer and prev_layer layers (each neuron of a layer is connected to all the neurons of the next layer).
This uses the norm_dist function to increase the training speed as it limits the number of saturated neurons at the start of the training*/

void layer_init(int layer_size,int prev_layer_size,Sig_Neuron layer[],Sig_Neuron prev_layer[]);


/* Initializes the network by iterating over the layer_init function*/
void net_init(Neural_Net nnet);


/* Applies the Feedforward algorithm to a layer : Computes the output of each neuron in the layer using the sigmoid function, the bias of the neuron, the output of the neurones of the previous layer and the weights between the layer and prev_layer layers*/

void fflayer(int layer_size; int prev_layer_size;Sig_Neuron layer[],Sig_Neuron prev_layer[])


/* Applies the Feedforward algorithm to the network by iterating over the fflayer function. Takes an result array of size [hidden+1].*/

void feedforward(Neural_Net nnet, double input[], double output[]);




/* Computes the backprop for the cross entropy cost function by subtracting the output and the expected result */ 
double backprop_cross_entropy(double output[], int Layer, double expected[], int sample_r);





#endif
