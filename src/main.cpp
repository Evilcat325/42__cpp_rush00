#include <ncurses.h>
#include <iostream>
#include "GameSession.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Timer.hpp"

int Enemy::randomInterval;

void initialization()
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
	Enemy::randomInterval = 30;
}

void end()
{
	endwin();
}

void print()
{
	std::cout << "probably works" << std::endl;
}

int main()
{
	initialization();
	if (stdscr == NULL)
	{
		std::cout << "Error reading default window" << std::endl;
		return 0;
	}

	Player p1(*stdscr);
	Background back(*stdscr);
	GameSession game(*stdscr, p1, back);
	Timer t(game);
	t.start();
	end();
	return 0;
}
