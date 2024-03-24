#ifndef _DRAW_H_
#define _DRAW_H_

#define PI 3.14159

void draw_start(int width, int height);

void set_color(int r, int g, int b);

void draw_circle(double x, double y, double r);
void draw_point(double x, double y);

void draw_end();

#endif
