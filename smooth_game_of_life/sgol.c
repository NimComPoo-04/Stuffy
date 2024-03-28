#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "sgol.h"
#include "draw.h"

void sgol_init(sgol_t *s)
{
	s->f = calloc(sizeof(double), s->w * s->h);
	s->ff = calloc(sizeof(double), s->w * s->h);
	
	s->M = s->ri * s->ri * PI;
	s->N = (s->ra * s->ra - s->ri * s->ri) * PI;
}

void sgol_randomize(sgol_t *s)
{
	srand(time(NULL));

	for(int i = s->h/4; i < s->h * 3/4; i++)
	{
		for(int j = s->w/4; j < s->w * 3/4; j++)
		{
			s->f[i * s->w + j] = (rand() % (long)1E4) * 1.0 / 1E4;
		}
	}
}

double sgol_func(sgol_t *s, double x, double y)
{
	if(x < 0 || y < 0 || x >= s->w || y >= s->h)
		return 0;
	return s->f[(int)y * s->w + (int)x];
}

double calc_area(sgol_t *s, double x, double y, double r)
{
	double area = 0;

	for(int i = -r-s->b/2; i <= r+s->b/2; i++)
	{
		for(int j = -r-s->b/2; j <= r+s->b/2; j++)
		{
			double d = hypot(j, i);

			if(d > r + s->b/2)
				continue;

			else if(d < r - s->b/2)
				area += sgol_func(s, x + j, y + i);
			else
				area += sgol_func(s, x + j, y + i) * (r + s->b/2 - d)/s->b;
		}
	}

	return area;
}

static double sig_1(double x, double a, double alpha)
{
	return 1.0/(1 + exp( (a - x) * 4 / alpha));
}

static double sig_2(double x, double a, double b, double alpha)
{
	return sig_1(x, a, alpha) * (1 - sig_1(x, b, alpha));
}

static double sig_m(double x, double y, double m, double alpha)
{
	return x * (1 - sig_1(m, 0.5, alpha)) + y * sig_1(m, 0.5, alpha);
}

double sgol_slur(sgol_t *s, double x, double y)
{
	double m = calc_area(s, x, y, s->ri);
	double n = calc_area(s, x, y, s->ra) - m;

	m /= s->M;
	n /= s->N;

	return sig_2(n, sig_m(s->birth[0], s->death[0], m, s->alpha_m), sig_m(s->birth[1], s->death[1], m, s->alpha_m), s->alpha_n);
}

void sgol_update(sgol_t *s)
{
	for(int i = 0; i < s->h; i++)
	{
		for(int j = 0; j < s->w; j++)
		{
			s->ff[i * s->w + j] = sgol_slur(s, j, i);
		}
	}

	double *t = s->f;
	s->f = s->ff;
	s->ff = t;
}

void sgol_dinit(sgol_t *s)
{
	free(s->f);
	free(s->ff);
}
