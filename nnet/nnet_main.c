/*
 * nnet_main.c : main neural network function which takes the 
 * images of the characters as input and returns the text as a char*
 */

#include <stdio.h>
#include <stdlib.h>
#include "nnet_prototype.h"
#include "nnet_work.h"
#include "../save/save_file.h"

char* nnet_main(char* path, struct images* raw_input)
{
  struct Neural_Net* nnet = loadnnet(path);
  char* cur = malloc(sizeof(char) * size);
  double* input_begin;
  for(; raw_imput->next; raw_input = raw_imput->next)
  {
    
    work(nnet,input_begin);
    *cur = convert_output(nnet);
    cur++;
  }
  return cur;
}
