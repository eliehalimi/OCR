/*
 * matrix.c: standard matrix operations, very quick tests
 *
 * 2017 EPITA
 */
 
#include <stdio.h>
#include <stdlib.h>
 
#include "matrix.h"

#include <assert.h>


int matrix_get(int m[], size_t lines, size_t cols, size_t i, size_t j)
{
	assert(i < lines);
	assert(j < cols);
	return m[j + i * cols];
}




void transpose(double mat[], size_t lines, size_t cols, double res[])
{
	
	for (size_t i = 0; i<lines; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			res[i+j * lines] = mat[j + i * cols];
		}
	}	
}


void add(double mat1[], double mat2[], size_t lines, size_t cols, double res[])
{
	for (size_t index = 0; index < lines; index++)
	{
		for (size_t index2 = 0; index2 < cols; index2++)
		{
			res[index2 + index * cols] = mat1[index2 + index * cols] 
						+ mat2[index2 + index * cols];
			
		}
	}
}


void mul(double m1[], double m2[], size_t n, size_t m, size_t p, double res[])
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < p; j++)
		{
			for (size_t k = 0; k < m; k++)
			{
				res[j + i * p] += m1[k + i* m] * m2[j +k *p];
			}
		}
	}
}


void print_matrix(double mat[], size_t lines, size_t cols)
{
	for (size_t i = 0; i < lines; i++)
	{
		for (size_t j =0; j < cols; j++)
		{
			printf("%4g", mat[j + i *cols]);
		}
		printf("%s", "\n");
	}
	printf("%s","\n");
}

void hadamard_product(double mat[], double mat2[], size_t lines, size_t cols, double res[])
{
	for (size_t i = 0; i< lines; i++)
	{
		for (size_t j = 0; j <cols; j++)
		{
			res[j + i *cols] = mat[j + i * cols] * mat2[j + i *cols];
		}
	}	
}


void matrix_sub(double output[], double expected[],size_t lines, size_t cols, double res[])
{
	/* assuming that both matrices have the same number of lines and columns */

	for (size_t i = 0; i < lines; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			res[j + i * cols] = output[j + i * cols] - expected[j + i *cols];
		}
	}
}

