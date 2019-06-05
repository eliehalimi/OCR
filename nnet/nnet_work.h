/*
 * nnet_work.h : header file for nnet_work.c included in nnet_main
 */

#include "nnet_prototype.h"

void training(struct Neural_Net* nnet, size_t epochs, double*
                training_data_begin, double* expect_data_begin, double eta);

void work(struct Neural_Net *nnet, double *input_begin);

char convert_output(struct Neural_Net *nnet);
