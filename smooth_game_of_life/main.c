#include <stdio.h>

#include "draw.h"
#include "sgol.h"

#define WIDTH 512
#define HEIGHT 512

#define FRAMES 360

unsigned int interpolate(double t)
{
	unsigned char r = 0xFF * t;
	unsigned char b = 0x88 * t;
	return (r << 16) | b;
}

int main(void)
{
	draw_start(WIDTH, HEIGHT);

	set_color(255, 255, 255);

	sgol_t s = {
		.w = 256,
		.h = 256,
		.b = 1,
		.ri = 2,
		.ra = 6,
		.birth = {0.278, 0.365},
		.death = {0.267, 0.445},
		.alpha_m = 0.147,
		.alpha_n = 0.028
	};

	sgol_init(&s);

	sgol_randomize(&s);

	double dx = 1.0 / WIDTH;
	double dy = 1.0 / HEIGHT;

	for(int i = 0; i < FRAMES; i++)
	{
		sgol_update(&s);

		for(double y = 0; y < 1.0; y += dy)
		{
			for(double x = 0; x < 1.0; x += dx)
			{
				unsigned int b =  interpolate(sgol_func(&s, x * s.w, y * s.h));

				extern unsigned int color;
				color = b;
				draw_point(x, y);
			}
		}

		draw_frame();
	}

	sgol_dinit(&s);

	draw_end();

	return 0;
}
