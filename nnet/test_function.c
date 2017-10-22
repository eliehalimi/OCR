/* test_function.c : this contains the function that the neural network is compared to and the conversion function for the input and output */

# include <stdio.h>
# include <stdlib.h>
# include "nnet_prototype.h"
# include "nnet_functions.h"

/*
void convert_input(char value,int input[]) {
  input[6];
  switch(value) {
  case '0':
    input = {0,0,0,0,0,0};
    break;
  case '1':
    input = {0,0,0,0,0,1};
    break;
  case '0':
    input = {0,0,0,0,0,0};
    break;
  case '1':
    input = {0,0,0,0,0,1};
    break;
  case '0':
    input = {0,0,0,0,0,0};
    break;
  case '1':
    input = {0,0,0,0,0,1};
  }
}
*/



int main(int argc, char *argv[])
{	
	if (argc == 2)
	{
		load_net(argv[1]); //will need to add things here like initialize according to what is read.
	}
	else
	{
		init([8,5,3,8], 2);
	}

	

}
