/* nnet_prototype.c : This is the prototype for our neural network.To be clear, this is where the base struct is saved not where the whole network. */

#include <stdio.h>
#include <stdlib.h>
#include "nnet_functions.h"

/* Initializes a new neural network.
   Inputs : list of layers' sizes and number of hidden layers*/

void init(int sizes[], int hidden) {
  Neural_Net nnet;
  nnet.sizes=sizes;
  nnet.hidden=hidden;
  net_init(nnet);
}

load_net(char path[]) {

}

/* Trains a neural network.
   Inputs : training_data = list of inputs converted to double arrays, expect_data  list of correct data also converted and eta=learning rate */ 

void training(Neural_Net nnet, int epochs, double training_data[][], double expect_data[][],int training_size, double eta) {
  double cost;
  for(int times=0;times<epochs;times++) {
    double output[nnet.sizes[nnet.hidden+1]];
    feedforward(nnet,training_data[times]);
    success_and_errors(nnet,expect_data[times]);
    backprop(nnet);
    change_weight(nnet,eta);
  }
}

void save_net(Neural_Net nnet, char path[]) {


}
