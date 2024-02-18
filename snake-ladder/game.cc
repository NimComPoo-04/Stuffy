#include <cstdlib>
#include <cstdio>
#include <cmath>

#include <raylib.h>

#include "game.hh"

Teleports::Teleports(int count)
	:moves{}
{
	Teleports::count = count;

	/*
	 * Random Generation Algorithm:
	 * We spread out the things equidistantly
	 */

	int c = 0;

	int start = 0;
	int end = 0;

	int dt = 100 / count;

	for(int i = 0; i < count; i++)
	{
		start += dt;

		while(moves[start])
			start = (start + 1) % 100;

		int t = GetRandomValue(0, 1);

		if(start <= 10 || t)
		{
			end = GetRandomValue(start + 10, 100);;
		}
		else if(start >= 90 || !t)
		{
			end = GetRandomValue(1, start - 10);;
		}

		while(moves[end])
			end = (end + 1) % 100;

		moves[start] = end + 1;
	}

	std::printf("Moves: %d\n", c);
}

int Teleports::operator[](int x) const
{
	if(x <= 0 || x > 100)
		throw std::string("Out of Bounds Access in hashmap");

	return moves[x - 1];
}

Game::Game(int count, int index)
	:snakes_and_ladders(count)
{
	for(int i = 0; i < index; i++)
		player[i] = 0;
	count = index;
}

int Game::gen_move() const
{
	return GetRandomValue(1, 6);
}

int Game::move(int who)
{
	int &player_index = player[who];

	if(player_index == 0)
	{
		int mv = Game::gen_move();
		if(mv == 1)
		{
			player_index = 1;
			return 0;
		}
		else
			return -2;
	}
	else if(snakes_and_ladders[player_index] > 0)
	{
		int k = snakes_and_ladders[player_index] > player_index;
		player_index = snakes_and_ladders[player_index];

		return k ? 1 : -1;
	}
	else if(player_index >= 100)
	{
		return 2;
	}
	else
	{
		int t = GetRandomValue(1, 6);
		player_index += player_index + t > 100 ? 0 : t;
		return 0;
	}
}

int Game::to_index(int x, int y) const
{
	return (y % 2 != 0 ? 9 - x : x) + y * 10 + 1;
}

Game::Pair Game::to_coord(int x) const
{
	int ny = (x - 1) / 10;
	int nx = (x - 1) % 10;
	return Game::Pair{ny % 2 == 0 ? nx : 9 - nx, ny};
}

int Game::get_index(int who) const
{
	return player[who];
}

int Teleports::get_count() const
{
	return count;
}

const Teleports &Game::get_teleports() const
{
	return snakes_and_ladders;
}
