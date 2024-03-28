#ifndef _SGOL_H_
#define _SGOL_H_

typedef struct
{
	int w;
	int h;

	double ri;
	double ra;

	double M;
	double N;

	double b;

	double alpha_m;
	double alpha_n;

	double birth[2];
	double death[2];

	double *f; // state function 
	double *ff; // state function 
} sgol_t;

void   sgol_init(sgol_t *);
void   sgol_randomize(sgol_t *);

double sgol_func(sgol_t *, double x, double y);
double sgol_slur(sgol_t *, double x, double y);

void sgol_update(sgol_t *);

void   sgol_dinit(sgol_t *);


#endif
