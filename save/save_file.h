// pixel_operations.h
 
# ifndef SAVE_FILE_H_
# define SAVE_FILE_H_

#include <stdlib.h>
# include "../nnet/nnet_prototype.h"

/* open a file with a parameter describing either read or write */ 
//void open_file(char *path, char *type);


void savennet(struct Neural_Net * nnet, char* path);

/* write to a file some text. Here predefined text.*/
//void write_to_file(FILE *f);
//TODO add parameter (int *input) to add that value to the file


/* reads content of a file */ 
//void read_file(FILE *f);


# endif
