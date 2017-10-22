/* nnet_prototype.c : This is the prototype for our neural network.To be clear, this is where the base struct is saved not where the whole network. */

#include <stdio.h>
#include <stdlib.h>
#include "nnet_functions.h"

void init(int sizes[], int hidden) {
  Neural_Net nnet;
  nnet.sizes=sizes;
  nnet.hidden=hidden;
  net_init(nnet);
}

void training(Neural_Net nnet, int epochs, int data_size, double training_data[][], double expect_data[][],int training_size, double eta, double lambda = 0.0) {
  double cost;
  for(int times=0;times<epochs;times++) {
    double output[nnet.sizes[nnet.hidden+1]];
    feedforward(nnet,training_data[times]);
    success_and_errors(nnet,expect_data[times]);
    backprop(nnet);
    
  }
}
  
  
