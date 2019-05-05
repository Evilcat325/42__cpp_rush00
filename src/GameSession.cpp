#include "GameSession.hpp"

GameSession::GameSession(WINDOW &screen, Player &p1)
		: screen(screen), p1(p1)
{
	p1.init();
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
	int key;
	while ((key = getch()) != ERR)
	{
		if (isPlayerOneMove(key))
			p1.moveByChar(key);
	}
	wclear(&screen);
	p1.render();
	state = ENDED;
}

bool GameSession::isPlayerOneMove(int key)
{
	return key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT;
}
