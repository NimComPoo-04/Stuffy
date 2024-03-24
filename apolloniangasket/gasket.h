#ifndef _GASKET_H_
#define _GASKET_H_

#include <complex.h>

typedef struct
{
	double x;
	double y;
	double rad;
} circle_t;

void init_gasket(circle_t *c1, circle_t *c2, circle_t *c3);
void next_generation();
void draw_gasket();
void dinit_gasket();

void draw_gasket_r(circle_t c1, circle_t c2, circle_t c3, int depth);

#endif
