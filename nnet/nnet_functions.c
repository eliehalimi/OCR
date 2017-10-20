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

net_initialization(Neural_Net nnet){
  for(int i=0;i<nnet.sizes[0];i++){
    nnet.input_layer[i].weight= norm_dist();
    nnet.input_layer[i].biases= norm_dist();
    nnet.input_layer[i].linked= nnet.hidden_layers[0];
  }
  for(int k=0;k<hidden-1;k++){
    for(int i=0;i<nnet.sizes[k];i++){
      nnet.hidden_layers[k][i].weight= norm_dist();
      nnet.hidden_layers[k][i].bias =norm_dist();
      nnet.hidden_layers[k][i].linked=nnet.hidden_layers[k+1];
    }
  }

  for(int i=0;i<nnet.sizes[hidden];i++){
    nnet.hidden_layers[hidden-1][i].weight=norm_dist();
    nnet.hidden_layers[hidden-1][i].bias =norm_dist();
    nnet.hidden_layers[hidden-1][i].linked=nnet.output_layers;
  }
  
  for(int i=0;i<nnet.sizes[hidden+1];i++){
    nnet.output_layer[i].weight= norm_dist();
    nnet.output_layer[i].bias =norm_dist();
  }
}

forward(Neural_Net nnet,input a) {

}


