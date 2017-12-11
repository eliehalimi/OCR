// save_file.c
//
//
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "save_file.h"
/*

 / / SEE DECLARATION IN HEADER
void open_file(char *path, char *type)
{
	if (*type == "w" || *type == "r")
	{
		FILE *f = fopen(*path, "w");
       	 	if (f == NULL)
        	{
        	printf("Error opening file!\n");
        	exit(1);
        	}
		return *f;
	}
	printf("Error opening file! open with r or w parameter\n")
	exit(1);
}
*/

void savennet(struct Neural_Net* nnet, char* path)
{
	assert(nnet != NULL);
	FILE *f = fopen(path, "w+");
	if (f== NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	fprintf(f, "{\n");

	int k = 1;
        struct Sig_Neuron* x;
        struct Sig_Neuron* y = nnet->layers_begin;
        struct Sig_Neuron* z = nnet->layers_begin + *(nnet->sizes_begin);
        while(k < nnet->sizes_end - nnet->sizes_begin)
        {
          printf("size of layer: %zu\n",*(nnet->sizes_begin+ k -1));
          x = y;
          y = y + *(nnet->sizes_begin + k - 1);
          z = z + *(nnet->sizes_begin + k);
          for(int i = 0; i < z - y; i++)
          {
            printf("bias = %f\n", (y + i)->bias);
            for(int j = 0; j < (y - x); j++)
            {
              printf("weights: %f\n",((y + i)->weights_begin[j]));
            }
          }
        }
}

/*
//SEE DECLARATION IN HEADER
void write_to_file(FILE *f)
{

	* print some text * /
	const char *text = "Write this to the file";
	fprintf(f, "Some text: %s\n", text);

	 print integers and floats * /
	int i = 1;
	float py = 3.1415927;
	fprintf(f, "Integer: %d, float: %f\n", i, py);

	/ * printing single chatacters * /
/ *	char c = 'A';
	fprintf(f, "A character: %c\n", c);

	fclose(f);
}
*/
//SEE DECLERATION IN HEADER
/*void read_file(FILE *f)
{
	while ((c = getc(file)) != EOF)
        	putchar(c);
}*/
