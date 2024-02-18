#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>

// This will behave like a lookup table.
class Teleports
{
private:
	int moves[100];
	int count;

public:
	Teleports(int count);
	int operator[](int x) const;
	int get_count() const;
};

class Game
{
private:
	int player[10];
	int count;

	Teleports snakes_and_ladders; // the obstacles in the game

public:
	struct Pair
	{
		int x;
		int y;
	};

public:
	Game(int count = 10, int players = 4);

	/*
	 * Changes the internal index of the player to make move.
	 * returns 0 if normal move
	 * returns 1 is ladder
	 * returns -1 if the snake
	 * returns 2 if at the last of the moves
	 * returns -2 if not on board
	 */
	int move(int who);

	// just generates a random number
	int gen_move() const;

	// going from (x,y) coord to linear
	int to_index(int x, int y) const;

	// going from index to (x, y)
	Pair to_coord(int x) const;

	// get the player index
	int get_index(int who) const;

	// get sanakes and daughters
	const Teleports &get_teleports() const;
};

#endif
