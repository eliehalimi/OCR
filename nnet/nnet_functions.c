/* nnet_functions.c : This is where the functions used by the neural networks will be stored*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nnet_prototype.h"
#include "lib/matrix.h"

/* Misc functions */

/* Genrates doubles following normal distrubution with mean 0 and standard deviation 1*/

double norm_dist() {
  double r,val1,val2,fac;
  r=2;
  while(r>=1) {
    val1=(2*(double)rand()/(double)RAND_MAX)-1;
    val2=(2*(double)rand()/(double)RAND_MAX)-1;
    r=val1*val1+val2*val2;
  }
  fac=sqrt(-2*log(r)/r);
  return (v2*fac);
}

/*sigmoid function for the neurons*/

double sigmoid(double val) {
  return 1/(1+exp(-val));
}

/* Devirative of the sigmoid function */

double sigmoid_prime(double val) {
  return sigmoid(val)*1-sigmoid(val);
}

/* Network functions */

/* Initialize the weights using the norm_dist function, this allows an increase in training speed by limiting the number of saturated neurons at the start of the training*/

layer_init(int layer_size,int prev_layer_size,Sig_Neuron layer[],Sig_Neuron prev_layer[]){
  for(int i=0;i<layer_size;i++){
    double layer[i].weights[prev_layer_size];
    for(int j=0;j<prev_layer_size;j++) {
      layer[i].weights[j]= norm_dist();
    }
    layer[i].biases= norm_dist();
    layer[i].linked= prev;
  }
}
net_init(Neural_Net nnet,int input[]){
  for(int i=0;i<sizes[0];i++){
    double input_layer[i].weights[1];
    input_layer[i].weights[1]={1};
    input_layer[i].bias=0;
    input_layer[i].output=input[i];
  }
  layer_init(sizes[1],sizes[0],hidden_layers[0],input_layer);
  for(int k=1;k<hidden;k++){
    layer_init(sizes[k+1],sizes[k],hidden_layers[k],hidden_layers[k-1]);
  }
  layer_init(sizes[hidden+1],sizes[hidden],output_layer,hidden_layer[hidden-1]);
}

fflayer() {

}
feedforward(Neural_Net nnet,int a) {
  
}


