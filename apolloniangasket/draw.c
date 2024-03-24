#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "draw.h"

static int width = 0;
static int height = 0;

static unsigned color = 0;

unsigned *buffer = 0;

void draw_start(int w, int h)
{
	width = w;
	height = h;

	buffer = calloc(sizeof(unsigned), w * h);
}

void set_color(int r, int g, int b)
{
	color = (r << 16) | (g << 8) | b;
}

void draw_circle(double x, double y, double r)
{
	int offset_x = (x + 1) / 2 * width;
	int offset_y = (y + 1) / 2 * height;

	r = fabs(r);

	int rx = r * width / 2;
	int ry = r * height / 2;
	int r0 = rx > ry ? rx : ry;

	for(double a = 0; a <= 2 * PI; a += 1.0 / r0)
	{
		int x0 = offset_x + rx * cos(a);
		int y0 = offset_y + ry * sin(a);

		if(y0 < 0 || x0 < 0 || y0 >= height || x0 >= width)
			continue;

		buffer[y0 * width + x0] = color;
	}
}

void draw_point(double x, double y)
{
	int x0 = (x + 1) / 2 * width;
	int y0 = (y + 1) / 2 * height;

	if(y0 < 0 || x0 < 0 || y0 >= height || x0 >= width)
		return;

	buffer[y0 * width + x0] = color;
}

void draw_end()
{
	FILE *f = fopen("image.ppm", "wb+");
	fprintf(f, "P3 %d %d 255\n", width, height);
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			const int b = buffer[i * width + j] & 0xFF;
			const int g = (buffer[i * width + j] >> 8) & 0xFF;
			const int r = (buffer[i * width + j] >> 16) & 0xFF;

			fprintf(f, "%d %d %d ", r, g, b);
		}
		fprintf(f, "\n");
	}
	fclose(f);

	free(buffer);
}
