/* nnet_functions.c : This is where the functions used by the neural networks will be stored*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nnet_prototype.h"
#include "../lib/matrix.h"

/*-------------------------------Support functions------------------------------ */

/* Generates a double following normal distrubution with mean 0 and standard deviation 1. This allows the generation of random nunbers better suited for initial weights as they arefewer values very close to 1 0r 0.*/

double norm_dist() {
  double r,val1,val2,fac;
  r=2;
  while(r>=1) {
    val1=(2*(double)rand()/(double)RAND_MAX)-1;
    val2=(2*(double)rand()/(double)RAND_MAX)-1;
    r=val1*val1+val2*val2;
  }
  fac=sqrt(-2*log(r)/r);
  return (val2*fac);
}

/*Applies the sigmoid function σ on a value */
 
double sigmoid(double val) {
  return 1/(1+exp(-val));
}

/* Applies the derivative of the sigmoid function σ' on a value*/

double sigmoid_prime(double val) {
  return sigmoid(val)*1-sigmoid(val);
}

/* Computes the cost associated with an output and its expected value using the cross-entropy cost function Cce */

double cross_entropy(int size, double output[], double expect[]) {
  double cost =0;
  for(int i=0; i<size;i++) {
    if(output[i]!=0 || expect[i]!=0) {
      cost += (-expect[i]*log(output[i])-(1-expect[i])*log(1-a));
    }
  }
  return cost;
}

/* Computes the error associated with the cost function by subtracting the two matrices. */

void error(int size,double output[], double expect[], double res[]) 
{	
  matrix_sub(output, expect, 1, size, res[]); 
}

/* Computes the total error of the network */

double error_tot(int size, double error[]) {
  double error_t=0;
  for(int i=0;i<size;i++) {
    error_t += error[i];
  }
  return error_t;
}

/* Prints the number of correct guesses of the neural network for a test*/
void accuracy(int size,double output[], double expect[]) {
  int correct =0;
  for(int i=0;i<size;i++) {
    if(output[i]==hidden[i]) {
      correct+=1;
    }
  }
  printf(%s,"The network had ");
  printf(%d,correct);
  printf(%c,'/');
  printf(%d,size);
  printf(%s,"correct outputs.");
}

/*-------------------------- Network functions-------------------------- */

/* Initializes the weights between the layer and prev_layer layers (each neuron of a layer is connected to all the neurons of the next layer).
This uses the norm_dist function to increase the training speed as it limits the number of saturated neurons at the start of the training*/

void layer_init(int layer_size,int prev_layer_size,Sig_Neuron layer[],Sig_Neuron prev_layer[]){
  for(int i=0;i<layer_size;i++){
    double layer[i].weights[prev_layer_size];
    for(int j=0;j<prev_layer_size;j++) {
      layer[i].weights[j]= norm_dist();
    }
    layer[i].biases= norm_dist();
    layer[i].linked= prev;
  }
}
/* Initializes the network by iterating over the layer_init function*/
void net_init(Neural_Net nnet){
  for(int i=0;i<sizes[0];i++){
    double input_layer[i].weights[1];
    input_layer[i].weights[1]={1};
    input_layer[i].bias=0;
  }
  layer_init(sizes[1],sizes[0],hidden_layers[0],input_layer);
  for(int k=1;k<hidden;k++){
    layer_init(sizes[k+1],sizes[k],hidden_layers[k],hidden_layers[k-1]);
  }
  layer_init(sizes[hidden+1],sizes[hidden],output_layer,hidden_layer[hidden-1]);
}

/* Applies the Feedforward algorithm to a layer : Computes the output of each neuron in the layer using the sigmoid function, the bias of the neuron, the output of the neurones of the previous layer and the weights between the layer and prev_layer layers*/

void fflayer(int layer_size; int prev_layer_size;Sig_Neuron layer[],Sig_Neuron prev_layer[]) {
  for(int i=0;i<layer_size;i++) {
    layer[i].output=0;
    for(int j=0;j<prev_layer_size;j++) {
      layer[i].output += layer[i].weights[j]*prev_layer[i].output;
    }
    layer[i].output= sigmoid(layer[i].output+layer[i].bias);
  }
}

/* Applies the Feedforward algorithm to the network by iterating over the fflayer function. Takes an result array of size [hidden+1].*/

void feedforward(Neural_Net nnet, double input[], double output[]) {
  for(int a=0;a<sizes[0];a++) {
    input_layer[i]=input[i];
  }
  fflayer(sizes[1],sizes[0],hidden_layers[0],input_layer);
  for(int k=1;k<hidden;k++){
    fflayer(sizes[k+1],sizes[k],hidden_layers[k],hidden_layers[k-1]);
  }
  fflayer(sizes[hidden+1],sizes[hidden],output_layer,hidden_layer[hidden-1]);
  for(int b=0;b<sizes[hidden+1];b++) {
    output[b]=output_layer[b].output;
  }
}

void backpropagation(Neural_network nnet, double error[], double total_error, int lines, double backpropres[])
{
	for (int i = 0; i < lines; i++)
	{
		backpropres[i] = -error[i] * nnet[i].output_layer[i];							
	}	
}

double new_weight_prop(Neural_network nnet, double backprop[], double eta)
{
	double error = 0;
	for (int i = 0; i < nnet.size; i++)
	{
		error += nnet.
	}


}




