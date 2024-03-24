#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

#include "gasket.h"
#include "draw.h"

typedef struct
{
	circle_t cur;
	circle_t sib[3];
} node_t;

node_t *current = 0;
int current_count = 0;

node_t *next = 0;
int next_count = 0;

static void insert_next(node_t *n)
{
	if(next_count % 16 == 0)
		next = realloc(next, sizeof(node_t) * (next_count + 16));
	next[next_count++] = *n;
}

void init_gasket(circle_t *c1, circle_t *c2, circle_t *c3)
{
	circle_t weird;
	weird.rad = 0.0;

	node_t nx = {*c1, {*c2, *c3, weird}};
	insert_next(&nx);

	nx = (node_t){*c2, {*c1, *c3, weird}};
	insert_next(&nx);

	nx = (node_t){*c3, {*c1, *c2, weird}};
	insert_next(&nx);

	next_generation();
}

static int validate(double complex a, double r, circle_t *c1, circle_t *c2, circle_t *c3)
{
	double x = creal(a);
	double y = cimag(a);

	r = fabs(r);

	for(int i = 0; i < next_count; i++)
	{
		if(fabs(x - next[i].cur.x) <= 0.0000001 && fabs(y - next[i].cur.y) <= 0.0000001)
			return 0;
	}

	int b1 = fabs(hypot(x - c1->x, y - c1->y) - (r + fabs(c1->rad))) <= 0.00000001;
	int b2 = fabs(hypot(x - c2->x, y - c2->y) - (r + fabs(c2->rad))) <= 0.00000001;
	int b3 = fabs(hypot(x - c3->x, y - c3->y) - (r + fabs(c3->rad))) <= 0.00000001;

	return b1 || b2 || b3;
}

void compute_decart(circle_t *n1, circle_t *n2, circle_t *n3)
{
	double k1 = 1.0 / n1->rad;
	double k2 = 1.0 / n2->rad;
	double k3 = 1.0 / n3->rad;

	double disc = k1 * k2 + k1 * k3 + k2 * k3;

	if((int)(disc * 1000000) < 0) return;

	double pk4 = k1 + k2 + k3 + 2 * creal(csqrt(disc));
	double nk4 = k1 + k2 + k3 - 2 * creal(csqrt(disc));

	double complex z1 = n1->x + n1->y * I;
	double complex z2 = n2->x + n2->y * I;
	double complex z3 = n3->x + n3->y * I;

	double complex cdisc = k1 * k2 * z1 * z2 + k1 * k3 * z1 * z3 + k2 * k3 * z2 * z3;
	double complex sum = k1 * z1 + k2 * z2 + k3 * z3;

	node_t nx = {{0, 0, 0}, {*n1, *n2, *n3}};

	if(pk4 > 0)
	{
		double complex ppz4 = (sum + 2 * csqrt(cdisc)) / pk4;
		double complex pnz4 = (sum - 2 * csqrt(cdisc)) / pk4;

		if(validate(ppz4, 1.0/pk4, n1, n2, n3))
		{
			nx.cur = (circle_t){creal(ppz4), cimag(ppz4), 1.0/pk4};
			insert_next(&nx);
		}

		if(validate(pnz4, 1.0/pk4, n1, n2, n3))
		{
			nx.cur = (circle_t){creal(pnz4), cimag(pnz4), 1.0/pk4};
			insert_next(&nx);
		}
	}
	if(nk4 > 0)
	{
		double complex npz4 = (sum + 2 * csqrt(cdisc)) / nk4;
		double complex nnz4 = (sum - 2 * csqrt(cdisc)) / nk4;

		if(validate(npz4, 1.0/nk4, n1, n2, n3))
		{
			nx.cur = (circle_t){creal(npz4), cimag(npz4), 1.0/nk4};
			insert_next(&nx);
		}

		if(validate(nnz4, 1.0/nk4, n1, n2, n3))
		{
			nx.cur = (circle_t){creal(nnz4), cimag(nnz4), 1.0/nk4};
			insert_next(&nx);
		}
	}
}

void next_generation()
{
	draw_gasket();

	for(int i = 0; i < current_count; i++)
	{
		compute_decart(&current[i].cur, &current[i].sib[0], &current[i].sib[1]);
		compute_decart(&current[i].cur, &current[i].sib[0], &current[i].sib[2]);
		compute_decart(&current[i].cur, &current[i].sib[1], &current[i].sib[2]);
	}

	free(current);

	current = next;
	current_count = next_count;

	next = NULL;
	next_count = 0;
}

void draw_gasket()
{
	for(int i = 0; i < current_count; i++)
	{
		// printf("%lf %lf %lf\n", current[i].cur.x, current[i].cur.y, current[i].cur.rad);
		set_color(255, 255, 255);
		draw_circle(current[i].cur.x, current[i].cur.y, current[i].cur.rad);
	}
}

void dinit_gasket()
{
	free(current);
}
