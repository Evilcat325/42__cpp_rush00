#include "GameSession.hpp"

GameSession::GameSession(WINDOW &screen, Player const &p1)
		: NcursesRenderable(screen), p1(p1)
{
}

GameSession::~GameSession()
{
}

GameSession::GameSession(GameSession const &rhs)
		: NcursesRenderable(rhs.screen), p1(rhs.p1)
{
	*this = rhs;
}

GameSession &GameSession::operator=(GameSession const &)
{
	return *this;
}

void GameSession::start()
{
	state = RUNNING;
	int ch;
	while (state == RUNNING || state == PAUSED)
	{
		if ((ch = getch()) != ERR)
			p1.moveByChar(ch);
		wrefresh(stdscr);
	}
	state = ENDED;
}

void GameSession::end()
{
	endwin();
}
