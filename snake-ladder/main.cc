#include <iostream>
#include <iomanip>

#include <raylib.h>
#include <ctime>

#include "game.hh"

using namespace std;

// Playing Field Dimention
static const int width = 600;
static const int height = 600;

void test_matrix_to_index_converters(const Game &g)
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cout << setw(3) << g.to_index(j, i) << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= 100; i++)
	{
		Game::Pair p = g.to_coord(i);
		cout << '('<< p.x << ", " << p.y << ") ";

		if(i % 10 == 0)
			cout << endl;
	}
	cout << endl;
}

void draw_game_board(const Game &g)
{
	const int cell_width = width / 10;
	const int cell_height = height / 10;

	Color CELL_EVEN = BEIGE;
	Color CELL_ODD = BROWN;

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			int index = g.to_index(j, i);

			const int x = j * cell_width;
			const int y = GetScreenHeight() - i * cell_height - cell_height;

			DrawRectangle(x, y,
					cell_width, cell_height,
					index % 2 == 0 ? CELL_EVEN : CELL_ODD);

			string s = to_string(index);
			DrawText(s.c_str(), x + 3, y + 3,
					cell_width/4, index % 2 == 0 ? CELL_ODD : CELL_EVEN);

			s = to_string(g.get_teleports()[index]);
			DrawText(s.c_str(), x + cell_width/2 - 3,
					y + cell_height/2 - 3, cell_width/4,
					index % 2 == 0 ? CELL_ODD : CELL_EVEN);
		}
	}
}

static int player_count = 4;
static int snake_ladder_count = 20;

static Color player_colors[] = {
	RED, ORANGE, BLUE, PURPLE
};

static const int info_height = 50;

void draw_ui(const Game &g)
{
	int offset_x = 20;
	int offset_y = 10;

	for(int i = 0; i < player_count; i++)
	{
		Game::Pair p = g.to_coord(g.get_index(i));
		string s = to_string(g.get_index(i)) + " : ( "+to_string(p.x)+", "+to_string(p.y)+" )";
		DrawText(s.c_str(), offset_x, offset_y, 24, player_colors[i]);
		offset_x += MeasureText(s.c_str(), 24) + 30;
	}
}

void draw_player(const Game &g)
{
	const int cell_width = width / 10;
	const int cell_height = height / 10;

	for(int i = 0; i < player_count; i++)
	{
		Game::Pair p = g.to_coord(g.get_index(i));
		DrawCircle(cell_width * p.x + cell_width/2,
				height - (cell_height * (p.y - 1) + cell_height/2),
				cell_width/4,
				player_colors[i]);
	}
}

int main(void)
{
	SetRandomSeed(std::time(NULL));
	Game g(snake_ladder_count, player_count);

	test_matrix_to_index_converters(g);

	InitWindow(width, height + info_height, "Joe Mum");

	int who = 0;

	while(!WindowShouldClose())
	{
		if(IsKeyPressed(' '))
		{
			g.move(who % player_count);
			who++;
		}

		BeginDrawing();
		ClearBackground(BLACK);

		draw_ui(g);
		draw_game_board(g);
		draw_player(g);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
