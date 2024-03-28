#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "draw.h"

int width;
int height;
unsigned int *buffer;

unsigned int color;

void star_draw(int w, int h)
{
	width = w;
	height = h;
	buffer = calloc(sizeof(unsigned), w * h);
}

void set_color(int r, int g, int b)
{
	color = (r << 16) | (g << 8) | b;
}

void draw_rect(int x, int y, int w, int h)
{
	for(int i = y; i <= y + h; i++)
	{
		for(int j = x; j <= x + w; j++)
		{
			if(x < 0 || y < 0 || x >= width || y >= height)
				continue;

			buffer[i * width + j] = color;
		}
	}
}

void draw_point(int x, int y)
{
	if(x < 0 || y < 0 || x >= width || y >= height)
		return;
	buffer[y * width + x] = color;
}

void update_screen()
{
	fwrite(buffer, sizeof(unsigned), width * height, stdout);
	fflush(stdout);

	memset(buffer, 0, width * height * sizeof(unsigned));
}

void end_draw()
{
	free(buffer);
}
