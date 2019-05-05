#include "GameSession.hpp"

GameSession::GameSession(WINDOW &screen, Player &p1)
		: screen(screen), p1(p1)
{
}

GameSession::~GameSession()
{
}

GameSession::GameSession(GameSession const &rhs)
		: screen(rhs.screen), p1(rhs.p1)
{
	*this = rhs;
}

GameSession &GameSession::operator=(GameSession const &)
{
	return *this;
}

void GameSession::render()
{
	std::cout << "rendering" << std::endl;
	// int ch;
	// state = RUNNING;
	// while (state == RUNNING || state == PAUSED)
	// {
	// 	if ((ch = getch()) != ERR)
	// 	{
	// 		p1.moveByChar(ch);
	// 	}

	// 	wclear(&screen);
	// 	render();
	// }
	state = ENDED;
}
