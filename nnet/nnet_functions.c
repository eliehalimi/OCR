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

/*-------------------------- Network functions-------------------------- */

/* Initializes the weights between the layer and prev_layer layers (each neuron of a layer is connected to all the neurons of the next layer).
This uses the norm_dist function to increase the training speed as it limits the number of saturated neurons at the start of the training*/

void layer_init(int* layer_begin,int* layer_end,Sig_Neuron* prev_layer_end){
  for(int i=0;i<layer_end-layer_begin;i++){
    for(int j=0;j<prev_layer_end-(layer_end+1);j++) {
      *(layer_end+1+i).*(weights_begin+j)= norm_dist(); 
    }
    *(layer_end+1+i).biases= norm_dist();
  }
}

/* Initializes the network by iterating over the layer_init function*/

void net_init(Neural_Net nnet){
  for(int i=0;i<sizes_end-sizes_begin;i++){
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

void fflayer(int layer_size; int prev_layer_size,Sig_Neuron layer[] ,Sig_Neuron prev_layer[]) {
  for(int i=0;i<layer_size;i++) {
    layer[i].output=0;
    for(int j=0;j<prev_layer_size;j++) {
      layer[i].output += prev_layer[j].weights[i] * prev_layer[j].output[i];
    }
    layer[i].output= sigmoid(layer[i].output+layer[i].bias);
  }
}

/* Applies the Feedforward algorithm to the network by iterating over the fflayer function. Takes a result array of size [hidden+1].*/

void feedforward(Neural_Net nnet, int input[]) {
  for(int a=0;a<nnet.sizes[0];a++) {
  nnet.input_layer[i].output=input[i];  
  }
  fflayer(nnet.sizes[1],nnet.sizes[0],nnet.hidden_layers[0],nnet.input_layer);
  for(int k=1;k<nnet.hidden;k++){
    fflayer(nnet.sizes[k+1],nnet.sizes[k],nnet.hidden_layers[k],nnet.hidden_layers[k-1]);
  }
  fflayer(nnet.sizes[hidden+1],nnet.sizes[hidden],nnet.output_layer,nnet.hidden_layer[hidden-1]);
}

/* Computes the total cost, the errors of the neuron of the last layers and the total error of the network */

void success_and_errors(Neural_Net nnet, double expect[]) {
  double errors[nnet.sizes[hidden+2]];
  double output[nnet.sizes[hidden+2]];
  int correct =0;
  double cost =0;
  nnet.tot_error=0;
  for(int i=0; i<nnet.sizes[hidden+2];i++) {
    output[i]=nnet.output_layer[i].output;
  }
  matrix_sub(output, expect, 1, nnet.sizes[hidden+2], errors);
  for(int i=0; i<nnet.sizes[hidden+2];i++) {
    nnet.output_layer[i].errors= errors[i];
    nnet.tot_error += errors[i];
    if(nnet.output_layer[i].output!=0 || expect[i]!=0) {
      cost += (-nnet.output_layer[i].output*log(nnet.output_layer[i].output)-(1-nnet.output_layer[i].output)*log(1-a));
      correct+=1;
    }
  }
  printf(%s,"The network had ");
  printf(%d,correct);
  printf(%c,'/');
  printf(%d,nnet.sizes[hidden+1]);
  printf(%s,"correct outputs so its total cost is ");
  printf(%.5f,cost);
}

/* Computes and changes the error of all neurons in a layer */

void backprop_layer( Sig_Neuron layer[], int layer_size, Sig_Neuron next_layer, int next_layer_size)
{
  for (int i=0;i< layer_size;i++) {
    for (int j=0;j<layer[0].next_layer_size; j++) {
      layer[i].error = next_layer[j].error * layer[i].weights[j];
    }
  }
}

/* Computes and changes error of all neurons in the network by iterating over backprop_layer */

void backprop(Neural_net nnet)
{
  backprop_layer(nnet, nnet.hidden_layers[hidden],nnet.sizes[hidden+1], nnet.output_layer[],nnet.sizes[hidden+2])
  for (int i = nnet.hidden; i>0; i--) {
    backprop_layer(nnet, nnet.hidden_layers[i-1],nnet.hidden_layers[i], nnet.sizes[i],nnetsizes[i+1]);
  }
  backprop_layer(nnet,input_layer,nnet.hidden_layers[0],nnet.sizes[0],nnet.sizes[1]);
}

/* Computes the new weights of all neurons in a layer and updates their weights */

void change_weight_layer(double eta, Sig_Neuron layer[], int layer_size, Sig_Neuron next_layer, int next_layer_size)
{
  for (int i = 0; i< layer_size; i++) {
    for (int j =0; j< next_layer_size; j++) {
      layer[i].weights[j] = layer[i].weights[j] - eta * (-next_layer[j].error * layer[i].output);
    }
  }
}

/* Computes the new weights of all neurons in the network and updates their weights by iterating over change_weight_layer */

void change_weight(Neural_net nnet, double eta)
{
  change_weight_layer(eta,input_layer,sizes[0],hidden_layers[0],sizes[1])
  for (int i= 0;i<hidden; i++) {
    change_weight_layer(eta,hidden_layers[i],sizes[i],hidden_layers[i+1],sizes[i+1]);
  }
  change_weight_layer(eta,hidden_layers[hidden],sizes[hidden+1],output_layer,sizes[hidden+2]);
}
