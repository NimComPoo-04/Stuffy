#include <stdio.h>

#include "draw.h"
#include "gasket.h"

int main(void)
{
	draw_start(1024, 1024);

	set_color(255, 255, 255);


	// 2 : 3    2/5
	/*
	circle_t c1 = {.x = 0, .y = 0, .rad = -1};
	circle_t c2 = {.x = 2.0/5.0, .y = 0, .rad = 3.0/5.0};
	circle_t c3 = {.x = -3.0/5.0, .y = 0, .rad = 2.0/5.0};
	*/

	circle_t c1 = {.x = 0, .y = 0, .rad = -1};
	circle_t c2 = {.x = 0.51, .y = 0, .rad = 0.49};
	circle_t c3 = {.x = -0.49, .y = 0, .rad = 0.51};

	init_gasket(&c1, &c2, &c3);

	//draw_gasket_r(c1, c2, c3, 1);
	for(int i = 0; i < 20; i++)
		next_generation();
	draw_gasket();

	dinit_gasket();

	draw_end();

	return 0;
}
