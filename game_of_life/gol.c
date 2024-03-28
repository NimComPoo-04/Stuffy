#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "gol.h"
#include "draw.h"

void gol_init(gol_t *g)
{
	g->w += 6;
	g->h += 6;

	g->scr = calloc(1, g->w * g->h);
	g->back = calloc(1, g->w * g->h);
}

void gol_randomize(gol_t *g)
{
	for(unsigned i = g->h/10; i < g->h * 9/10; i++)
	{
		for(unsigned j = g->w/10; j < g->w * 9/10; j++)
		{
			g->scr[i * g->w + j] = rand() % 10 < 3;
		}
	}
}

void gol_update(gol_t *g)
{
	for(int i = 0; i < (int)g->h; i++)
	{
		for(int j = 0; j < (int)g->w; j++)
		{
			int nei = 0;
			for(int l = -1; l <= 1; l++)
			{
				for(int k = -1; k <= 1; k++)
				{
					if(l == 0 && k == 0) continue;
					else if(i + l < 0 || i + l >= (int)g->h ||
							j + k < 0 || j + k >= (int)g->w)
						continue;

					nei += g->scr[(i + l) * g->w + (j + k)];
				}
			}
		
			if(rand() % 30)
			{
				if(nei < 2)        g->back[i * g->w + j] = 0;
				else if(nei < 3)   g->back[i * g->w + j] = g->scr[i * g->w + j];
				else if(nei == 3)  g->back[i * g->w + j] = 1;
				else if(nei >= 4)  g->back[i * g->w + j] = 0;
			}
			else
			{
				switch(nei)
				{
					/*
					case 3: case 5:
						g->back[i * g->w + j] = !g->scr[i * g->w + j];
						break;
						*/

					case 3: case 5:
					case 7: case 8:
						g->back[i * g->w + j] = 1;
						break;

					case 2: case 4: case 6:
						g->back[i * g->w + j] = g->scr[i * g->w + j];
						break;

					default:
						g->back[i * g->w + j] = 0;
				}
			}
		}
	}

	unsigned char *d = g->scr;
	g->scr = g->back;
	g->back = d;
}

extern int width;
extern int height;

extern double frame_time;
static double interop(double x)
{
	return (1 - x)*(x - 1) + 1;
}

void gol_draw(gol_t *g)
{
	int cw = width / (g->w - 6);
	int ch = height /(g->h - 6);

	for(int i = 3; i < (int)g->w - 3; i++)
	{
		for(int j = 3; j < (int)g->h - 3; j++)
		{
			{
				int des = 0;

				int col = 2;
				int total = (2 * col + 1) * (2 * col + 1);

				for(int l = -col; l <= col; l++)
				{
					for(int k = -col; k <= col; k++)
					{
						if(i + l < 0 || i + l >= (int)g->h ||
								j + k < 0 || j + k >= (int)g->w)
							continue;
						des += g->scr[(i + l) * g->w + (j + k)];
					}
				}

				double t1 = interop(des * 1.0 / total);
				double t2 = interop(t1 * i / g->h);
				double t3 = interop(t1 * j / g->w);

				set_color(255.0 * t1, 255.0 * t2, 255.0 * t3);

				draw_rect((j - 3) * cw, (i - 3) * ch, cw, ch);
			}
		}
	}
}

void gol_dinit(gol_t *g)
{
	free(g->scr);
}
