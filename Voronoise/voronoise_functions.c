#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nbsites 150

double site[nbsites][2];
unsigned char char rgb[nbsites][3];
int size_x = 640;
int size_y = 480;

int nearest_site(double x, double y)
{
	int k, res = 0;
	double d, dist = 0;
	for (; k < nbsites; k++)
	{
		d = ((x - site[k][0]) * (x - site[k][0])) + ((y - site[k][1]) * (y - site[k][1]));
		if (!k || d < dist)
		{
			dist = d;
			res = k;
		}
	}
	return res;
}

int is_different(int *color, int y, int x)
{
	int i, j, c = color[y * size_x + x];
	for (i = y - 1; i <= y + 1; i++)
	{
		if (i < 0 || i >= size_y)
		{
			continue;
		}
		for (j = x - 1; j <= x + 1; j++)
		{
			if (j < 0 || j >= size_x)
			{
				continue;
			}
			if (color[i * size_x + j] != c)
			{
				return 1;
			}
		}
	}
	return 0;
}
