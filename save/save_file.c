// save_file.c
//
//
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "save_file.h"
#include <unistd.h>
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


void loadnnet(char* path)
{
	FILE *f = fopen(path, "r");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	char * line = NULL;
	size_t len = 0;
	char read;

	while ((read = getline(&line, &len, f)) != -1)
	{
		printf("%s\n", &read);
		printf("%s", line);
	}
	if (line)
		free(line);
	

	//int c;
	//while(1)
	//{
	//	c = fgetc(f);
	//	if(feof(f))
	  //     	{
	//	       break;
	//	}
	//	printf("%c", c);
	//}
	//fclose(f);



}





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

	int k = 0;
        struct Sig_Neuron* y = nnet->layers_begin;
        while(k < nnet->sizes_end - nnet->sizes_begin)
        {
          printf("size of layer: %zu\n",*(nnet->sizes_begin + k));
         fprintf(f, "%zu\n, ",*(nnet->sizes_begin + k));
          for(size_t i = 0; i < *(nnet->sizes_begin + k); i++)
          {
	    printf("bias = %f\n", (y + i)->bias);
           fprintf(f, " %f, ", (y + i)->bias);
	   fprintf(f, "\n");
            if(k == 0)
            {
              printf("weights: %f\n",(*(y + i)->weights_begin));
             fprintf(f, "%f, ",(*(y + i)->weights_begin));
            }
            else
            {
              for(size_t j = 0; j < *(nnet->sizes_begin + k - 1); j++)
                {
                  printf("weights: %f\n",((y + i)->weights_begin[j]));
                 fprintf(f, "%f, ",((y + i)->weights_begin[j]));
                }
            }
            fprintf(f, "\n");
          }
          y = y + *(nnet->sizes_begin + k);
          k++;
        }
	fprintf(f, "\n}");
	fclose(f);
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
