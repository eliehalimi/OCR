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
	//compare sumsizes with sum (sum = layersize + other layer sizes) and if layersize + other = sumsizes then outputlayer

	
	

	FILE *f = fopen(path, "r");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	
	char* read = malloc(sizeof(char)*40);
	int index = 0;
	int status = 0;
	int size_layer;
	int word;
	int c;
	struct Neural_Net *nnet = (struct Neural_Net *) malloc(sizeof(struct Neural_Net));
	nnet->sizes_begin = (size_t*) malloc(sizeof(size_t));
	nnet->layers_begin = (struct Sig_Neuron *) malloc(sizeof(struct Sig_Neuron));
	struct Sig_Neuron* cur;
	int num_layer= 0;
	int sum_sizes = 0;
	int count = 0;
	while ((c = fgetc(f)) != EOF)
	{
		if (status == 0)	//size_layer
		{
			if (c != (int)"\n")
			{
				*(read +index) += c;
				i++;
			}
			else
			{
				size_layer = stoi(read, NULL);
				status = 1;
				index = 0;
				nnet->sizes_begin[num_layer] = size_layer;
				num_layer++;
				count = 0;
				sum_sizes += size_layer;
				nnet->sizes_begin = realloc(sizeof(size_t) * num_layer);
				nnet->layers_begin = realloc(sizeof(struct Sig_Neuron) * sum_sizes);
			}
		}
		else if (status == 1)	//bias
		{
			cur++;
			
			if (c != "\n")
			{
				*(read + index) += c;
				index++;
			}
			else
			{
				index = 0;
				status = 2;
				nnet->layers_begin[cur]->bias = strtod(read, NULL);

			}
		}
		else
		{
			if (c != "," || c != "\n")
			{
				*(read + index) += c;
				index++;
			}
			else
			{
				index = 0;
				nnet->layers_begin[cur]->weights_begin = 
					malloc(sizeof(double) * nnet->sizes_begin[num_layer - 1];
				nnet->layers_begin[cur]->weights_begin[count] = strtod(read, NULL);
				if(c == "\n")
				{
					if(idx == layer_size)
						status = 0;
					else
						status = 1;
				}
				count++;
			}
		}
/*

			else if (c == ",")
			{
				size = read;
   				index = 0;
				//nnet->weight				
			}
			else 
			{
				size = read;
				index = 0;
				//nnet->weight
				if (idx == layer_size)
					status = 0;
				else
					status = 1;
			}

		}
		
*/		
	}


}
	/*
	char * read = malloc(sizeof(char));
	//char *line = read;
 	char c = fgetc(f);
	while (c != '\n' || c != EOF)
	{
		c = fgetc(f);
		*read = c;
		read++;
	}
	free(read);
//	printf("%c", *line);	
	
	
		

	//int c;
	//while(1)
	//{
	//	c = fgetc(f);
	//	if(feof(f))
	  //     	{
	//	       break;
	//	}
	//	printf("%c", c);
	//}*/
	//fclose(f);







void savennet(struct Neural_Net* nnet, char* path)
{
	assert(nnet != NULL);
	FILE *f = fopen(path, "w+");
	if (f== NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	//fprintf(f, "{\n");

	int k = 0;
        struct Sig_Neuron* y = nnet->layers_begin;
        while(k < nnet->sizes_end - nnet->sizes_begin)
        {
          printf("size of layer: %zu\n",*(nnet->sizes_begin + k));
         fprintf(f, "%zu\n",*(nnet->sizes_begin + k));
          for(size_t i = 0; i < *(nnet->sizes_begin + k); i++)
          {
	    printf("bias = %f\n", (y + i)->bias);
           fprintf(f, "%f\n", (y + i)->bias);
	   //fprintf(f, "\n");
            if(k == 0)
            {
              printf("weights: %f\n",(*(y + i)->weights_begin));
             fprintf(f, "%f,",(*(y + i)->weights_begin));
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
	  fprintf(f, "--\n");
        }
	fprintf(f, "\n");
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
