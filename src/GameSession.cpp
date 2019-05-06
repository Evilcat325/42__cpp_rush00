#include "GameSession.hpp"

GameSession::GameSession(WINDOW &screen, Player &p1)
		: NcursesRenderable(screen), p1(p1)
{
	p1.init();
	updateMap();
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

bool GameSession::render()
{
	if (p1.getHP() == 0)
	{
		wclear(&screen);
		mvwaddstr(&screen, 0, 0, "Defeated");
		return false;
	}
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

	detectCollision(map);
	return true;
}

bool GameSession::isPlayerOneMove(int key)
{
	return key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT;
}

void GameSession::renderPerSec()
{
	for (unsigned long i = 0; i < (sizeof(enemy) / sizeof(Enemy)); ++i)
		enemy[i].verticalScroll();
}

void GameSession::updateMap()
{
	map = new int[height * width];
	memset(map, 0, height * width * sizeof(*map));
}

void GameSession::detectCollision(int *&)
{
	memset(map, 0, height * width * sizeof(*map));
	for (int i = 0; i < 10; ++i)
		enemy[i].detectCollision(map);
	p1.detectCollision(map);
}
