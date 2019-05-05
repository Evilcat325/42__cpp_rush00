#include "GameSession.hpp"

GameSession::GameSession(WINDOW &screen, Player &p1)
<<<<<<< HEAD
	: NcursesRenderable(screen), p1(p1)
=======
		: screen(screen), p1(p1)
>>>>>>> 0a0eec4c99791ab0006bae18c73320d1f627a5b1
{
}

GameSession::~GameSession()
{
}

GameSession::GameSession(GameSession const &rhs)
<<<<<<< HEAD
	: NcursesRenderable(rhs.screen), p1(rhs.p1)
=======
		: screen(rhs.screen), p1(rhs.p1)
>>>>>>> 0a0eec4c99791ab0006bae18c73320d1f627a5b1
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
		{
			p1.moveByChar(ch);
		}

		wclear(&screen);
		render();
	}
	state = ENDED;
}

void GameSession::render()
{
	p1.render();
}
