#ifndef _DRAW_H_
#define _DRAW_H_

void star_draw(int width, int heigh);

void set_color(int r, int g, int b);
void draw_rect(int x, int y, int w, int h);
void draw_point(int x, int y);

void update_screen();

void end_draw();

#endif
