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

void layer_init(Sig_Neuron* layer_begin, Sig_Neuron* layer_end, Sig_Neuron* prev_layer_begin){
  for(int i=0;i<layer_end-layer_begin;i++){
    /* Allocates memory for the list of weights associated to this neurons (weights of the links going to this neuron). 
       Each weight is a double and there are the same number of weights as neuron in the previous layer which is prev_layer_end - prev_layer_begin.
       One can remark that prev_layer_end = layer_begin-1 which gives us the following expression.*/
    *(layer_begin+i).weights_begin = malloc((layer_begin-1-prev_layer_begin)*sizeof(double));
    *(layer_begin+i).weights_end = weights_begin+(layer_begin-1-prev_layer_begin);
    for(int j=0;j<(layer_begin-1-prev_layer_begin);j++) {
      *(layer_end+1+i).*(weights_begin+j)= norm_dist(); 
    }
    *(layer_end+1+i).biases= norm_dist();
  }
}

/* Initializes the network by iterating over the layer_init function*/

void net_init(Neural_Net nnet){
  for(size_t i=0;i<*(nnet.sizes_begin);i++) {
    *(nnet.layers_begin+i).weights_begin = malloc(sizeof(double));
    *(nnet.layers_begin+i).weights_end = *(nnet.layers_begin+i).weights_begin+1;
    *(nnet.layers_begin+i).*weights_begin = 1;
    *(nnet.layers_begin+i).bias = 0;
  }
  size_t k=1;
  Sig_Neuron* x;
  Sig_Neuron* y= nnet.layers_begin+*(nnet.sizes_begin);
  Sig_Neuron* z;
  while(k<nnet.sizes_end-nnet.sizes_begin) {
    x=y;
    y=nnet.layers_begin+*(nnet.sizes_begin+k);
    z=nnet.layers_begin+*(nnet.sizes_begin+k+1)-1;
    layer_init(y,z,x);
    k++;
  }
}

/* Applies the Feedforward algorithm to a layer : Computes the output of each neuron in the layer using the sigmoid function, the bias of the neuron, the output of the neurones of the previous layer and the weights between the layer and prev_layer layers*/

void fflayer(Sig_Neuron* layer_begin, Sig_Neuron* layer_end, Sig_Neuron* prev_layer_begin) {
  for(size_t i=0;i<layer_end-layer_begin;i++) {
    *(layer_begin+i).output=0;
    for(size_t j=0;j<(layer_begin-1-prev_layer_begin);j++) {
      *(layer_begin+i).output += *(prev_layer_begin+j).output * (prev_layer_begin+j).*(weights_begin+i);
    }
    *(layer_begin+i).output= sigmoid(*(layer_begin+i).output+*(layer_begin+i).bias);
  }
}

/* Applies the Feedforward algorithm to the network by iterating over the fflayer function. Takes a result array of size [hidden+1].*/

void feedforward(Neural_Net nnet, int* input_begin) {
  for(size_t i=0;i<*(nnet.sizes);i++) {
    *(nnet.layers_begin+i).output=*(input_begin+i);  
  }
  size_t k=1;
  Sig_Neuron* x;
  Sig_Neuron* y= nnet.layers_begin+*(nnet.sizes_begin);
  Sig_Neuron* z;
  while(k<nnet.sizes_end-nnet.sizes_begin) {
    x=y;
    y=nnet.layers_begin+*(nnet.sizes_begin+k);
    z=nnet.layers_begin+*(nnet.sizes_begin+k+1)-1;
    fflayer(y,z,x);
    k++;
  }
}

/* Computes the accuracy,the total error and the total cost of the network. It also sets the errors of the neurons of the output layer.*/

void success_and_errors(Neural_Net nnet, double* expect_begin) {
  int correct =0;
  double cost =0;
  Sig_Neuron* actual=layers_end-*(nnet.sizes_end-1);
  nnet.tot_error=0;
  
  matrix_sub(output, expect, 1, nnet.sizes[hidden+2], errors);
  for(int i=0; i<*(nnet.sizes_end-1);i++) {
    *(actual+i).error = *(actual+i).output-*(expect_begin+1);
    nnet.tot_error += *(actual+i).error;
    if(*(actual+i).output!=0 || expect[i]!=0) {
      cost += (-*(actual+i).error*log(*(actual+i).output)-(1-*(actual+i).error)*log(1-*(actual+i).output);
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

void backprop_layer(Sig_Neuron* layer_begin, Sig_Neuron* layer_end, Sig_Neuron* next_layer_end) {
  for(size_t i=0;i<layer_end-layer_begin;i++) {
    for(size_t j=0;j<(next_layer_end-layer_end+1);j++) {
      *(layer_begin+i).error = *(next_layer_begin+j).error* *(layer_begin+i).*(weights_begin+j);
    }
  }
}

/* Computes and changes error of all neurons in the network by iterating over backprop_layer */

void backprop(Neural_net nnet)
{
  size_t k=0;
  Sig_Neuron* x;
  Sig_Neuron* y= nnet.layers_begin;
  Sig_Neuron* z;
  while(k<nnet.sizes_end-nnet.sizes_begin) {
    x=y;
    y=nnet.layers_begin+*(nnet.sizes_begin+k)-1;
    z=nnet.layers_begin+*(nnet.sizes_begin+k+1);
    backprop(x,y,z);
    k++;
  }
}

/* Computes the new weights of all neurons in a layer and updates their weights */

void change_weight_layer(double eta,Sig_Neuron* layer_begin, Sig_Neuron* layer_end, Sig_Neuron* next_layer_end) ) {
  {
   for(size_t i=0;i<layer_end-layer_begin;i++) {
    for(size_t j=0;j<(next_layer_end-layer_end+1);j++) {
      *(layer_begin+i).*(weights_begin+j) = *(layer_begin+i).*(weights_begin+j)- eta * (- *(next_layer_begin+j).error * *(layer_begin+i).output);
    }
  } 
}
/* Computes the new weights of all neurons in the network and updates their weights by iterating over change_weight_layer */

void change_weight(Neural_net nnet, double eta)
{
  size_t k=0;
  Sig_Neuron* x;
  Sig_Neuron* y= nnet.layers_begin;
  Sig_Neuron* z;
  while(k<nnet.sizes_end-nnet.sizes_begin) {
    x=y;
    y=nnet.layers_begin+*(nnet.sizes_begin+k)-1;
    z=nnet.layers_begin+*(nnet.sizes_begin+k+1);
    backprop(x,y,z);
    k++;
  }
}
