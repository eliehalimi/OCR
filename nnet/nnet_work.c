/*
 * nnet_work.c : Functions for the neural network to train and return outputs
 */

#include <stdio.h>
#include <stdlib.h>
#include "nnet_functions.h"
#include "nnet_work.h"

void training(struct Neural_Net *nnet, size_t epochs, double*
                training_data_begin, double* expect_data_begin, double eta)
{
  for(size_t times=0;times<epochs;times++) {
    feedforward(nnet,training_data_begin + times * *(nnet->sizes_begin));
    success_and_errors(nnet,expect_data_begin + times * *(nnet->sizes_end-1));
    backprop(nnet);
    change_weight(nnet,eta);
  }
}

void work(struct Neural_Net *nnet, double *input_begin)
{
  feedforward(nnet, input_begin);
}

char convert_output(struct Neural_Net *nnet)
{
  double max = (nnet->layers_end - *(nnet->sizes_end -1))->output;
  size_t maxval = 0;
  for(size_t i = 1; i < *(nnet->sizes_end - 1);i++)
  {
    if((nnet->layers_end - *(nnet->sizes_end - 1) + i) ->output > max)
    {
      max = (nnet->layers_end - *(nnet->sizes_end - 1) + i)->output;
      maxval = i;
    }
  }
  if(max<0.9)
    return '\0';
  else
    return maxval;
}
