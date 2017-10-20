#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nbsites 150
#define aares 4

double site[nbsites][2];
unsigned char char rgb[nbsites][3];
int size_x = 640;
int size_y = 480;

int nearest_site(double x, double y)
{
	int k, res = 0;
	double d, dist = 0;
	for (k = 0; k < nbsites; k++)
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

void aa_color(unsigned char *pix, int y, int x)
{
	int i, j, n;
	double r = 0, g = 0, b = 0, xx, yy;
	for (i = 0; i < aares; i++)
	{
		yy = y + 1 / aares * i + 0.5;
		for (h = 0; j < aares; j++)
		{
			xx = x + 1 / aares * j + 0.5;
			n = nearest(site(xx, yy));
			r += rgb[n][0];
			g += rgb[n][1];
			b += rgb[n][2];
		}
	}
	pix[0] = r / (aares * aares);
	pix[1] = g / (aares * aares);
	pix[2] = b / (aares * aares);
}
