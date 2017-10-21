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
  }
}

/* Initializes the network by iterating over the layer_init function*/

void net_init(Neural_Net nnet,double input[]){
  for(int i=0;i<nnet.sizes[0];i++){
    double nnet.input_layer[i].weights[1];
    nnet.input_layer[i].weights={1};
    nnet.input_layer[i].bias=0;
  }
  layer_init(nnet.sizes[1],nnet.sizes[0],nnet.hidden_layers[0],nnet.input_layer);
  for(int k=1;k<nnet.hidden;k++){
    layer_init(nnet.sizes[k+1],nnet.sizes[k],nnet.hidden_layers[k],nnet.hidden_layers[k-1]);
  }
  layer_init(nnet.sizes[hidden+1],nnet.sizes[hidden],nnet.output_layer,nnet.hidden_layer[hidden-1]);
}

/* Applies the Feedforward algorithm to a layer : Computes the output of each neuron in the layer using the sigmoid function, the bias of the neuron, the output of the neurones of the previous layer and the weights between the layer and prev_layer layers*/

void fflayer(int layer_size; int prev_layer_size;Sig_Neuron layer[],Sig_Neuron prev_layer[]) {
  for(int i=0;i<layer_size;i++) {
    layer[i].output=0;
    for(int j=0;j<prev_layer_size;j++) {
      layer[i].output += prev_layer[j].weights[i] * prev_layer[j].output[i];
    }
    layer[i].output= sigmoid(layer[i].output+layer[i].bias);
  }
}

/* Applies the Feedforward algorithm to the network by iterating over the fflayer function. Takes an result array of size [hidden+1].*/

void feedforward(Neural_Net nnet, int input[]) {
  for(int a=0;a<nnet.sizes[0];a++) {
  nnet.input_layer[i].output=input[i];  
  }
  fflayer(nnet.sizes[1],nnet.sizes[0],nnet.hidden_layers[0],nnet.input_layer);
  for(int k=1;k<nnet.hidden;k++){
    fflayer(nnet.sizes[k+1],nnet.sizes[k],nnet.hidden_layers[k],nnet.hidden_layers[k-1]);
  }
  fflayer(nnet.sizes[hidden+1],nnet.sizes[hidden],nnet.output_layer,nnet.hidden_layer[hidden-1]);
  for(int b=0;b<sizes[hidden+1];b++) {
    output_layer[b].output;
  }
}

/* changes error of all neurons in a layer */

void backprop_layer(Neural_net nnet, Sig_Neuron layer[], int layer_size)
{
    for (int i = layer_size; i > 0; i--)
    {
        for (int j = 0; j < layer[0].size_w; j++)
        {
            layer[i].error = layer[i].error * layer[i].weights[j];
        }
    }
}

/* changes error of all layers of neurons */

void backprop(Neural_net nnet)
{
    for (int i = nnet.hidden; i>0; i--)
    {
        backprop_layer(nnet, layer, layer.sizes[i]);
    }
}



/* change weight */

void weight_neuron_layer(Neural_net nnet, double eta, Sig_Neuron layer[], int layer_size, Sig_Neuron next_layer, int next_layer_size)
{
    for (int i = 0; i< layer_size; i++)
    {
        for (int j =0; j< layer[i].size_w; j++)
        {
            layer[i].weights[j] = layer[i].weights[j] - eta * (-next_layer[j].error * 
                                           layer[i].output);
        }

    }
}

void change_weight(Neural_net nnet, double eta, Sig_Neuron layer[], int layer_size)
{
    for (int i =1; i< layer_size-1; i++)
    {
        weight_neuron_layer(nnet, eta, layer, layer_size, 
                //TODO add second neuron (next layer) with size)
    }
}
