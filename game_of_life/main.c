#include <stdio.h>
#include <string.h>

#include "gol.h"
#include "draw.h"

#define FRAMES 720
#define DIM 200

double frame_time = 0;

int main(void)
{
	gol_t g = {.w = DIM, .h = DIM, .scr = 0};

	star_draw(800, 800);

	set_color(255, 255, 255);

	gol_init(&g);

	gol_randomize(&g);

	for(int i = 0; i < FRAMES; i++)
	{
		frame_time = 1.0 * i / FRAMES;

		gol_update(&g);
		gol_draw(&g);

		update_screen();
	}

	gol_dinit(&g);

	end_draw();

	return 0;
}
