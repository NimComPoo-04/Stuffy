#ifndef _GOL_H_
#define _GOL_H_

typedef struct
{
	unsigned w;
	unsigned h;

	unsigned char *scr;
	unsigned char *back;
} gol_t;

void gol_init(gol_t *g);
void gol_randomize(gol_t *g);
void gol_update(gol_t *g);
void gol_draw(gol_t *g);
void gol_dinit(gol_t *g);

#endif
