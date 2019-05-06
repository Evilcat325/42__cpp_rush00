#include <ncurses.h>
#include <iostream>
#include "GameSession.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Timer.hpp"

void initialization()
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
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
	Player p2(*stdscr);
	Background back(*stdscr);
	GameSession game(*stdscr, p1, p2, back);
	Timer t(game);
	t.start();
	end();
	return 0;
}
