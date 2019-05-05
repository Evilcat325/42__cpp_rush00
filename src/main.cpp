#include <ncurses.h>
#include <iostream>
#include "GameSession.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

void initialization()
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(2);
}

void end()
{
	endwin();
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
	GameSession game(*stdscr, p1);
	game.start();
	end();
	return 0;
}
