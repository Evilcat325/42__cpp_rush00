#include "GameSession.hpp"

GameSession::GameSession(WINDOW &screen, Player &p1)
		: screen(screen), p1(p1)
{
	p1.init();
	for (int i = 0, e = sizeof(enemy); i < e; ++i)
	{
	}
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
	for (unsigned long i = 0; i < (sizeof(enemy) / sizeof(Enemy)); ++i)
		enemy[i].randomMove();

	wclear(&screen);
	p1.render();
	for (unsigned long i = 0; i < (sizeof(enemy) / sizeof(Enemy)); ++i)
		enemy[i].render();
	state = ENDED;
}

bool GameSession::isPlayerOneMove(int key)
{
	return key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT;
}
