#include "GameSession.hpp"

GameSession::GameSession(WINDOW &screen, Player &p1, Background &back)
	: NcursesRenderable(screen), p1(p1), back(back)
{
	p1.init();
	updateMap();
}

GameSession::~GameSession()
{
}

GameSession::GameSession(GameSession const &rhs)
	: NcursesRenderable(rhs.screen), p1(rhs.p1), back(rhs.back)
{
	*this = rhs;
}

GameSession &GameSession::operator=(GameSession const &)
{
	return *this;
}

bool GameSession::render()
{
	int key;
	if (p1.getHP() == 0)
	{
		while ((key = getch()) != ERR)
			;
		mvwaddstr(&screen, height / 2 - 1, width / 2 - 5, "Defeated");
		return true;
	}
	while ((key = getch()) != ERR)
	{
		if (isPlayerOneMove(key))
			p1.moveByChar(key, true);
		else if (key == ' ')
			p1.shoot();
	}

	wclear(&screen);
	back.draw_star();
	back.draw_hp(p1);
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

void GameSession::updateMap()
{
	map = new int[height * width];
	memset(map, 0, height * width * sizeof(*map));
}

void GameSession::detectCollision(int *&)
{
	memset(map, 0, height * width * sizeof(*map));
	// set projectile to 42
	p1.detectCollision(map);

	// set emeny to 1
	for (int i = 0; i < 10; ++i)
		enemy[i].detectCollision(map);

	// check if player die;
	p1.detectCollision(map);
}
