#include "Enemy.hpp"

Enemy::Enemy()
		: NcursesRenderable(*stdscr)
{
	row = 0;
	col = width / 2;
}

Enemy::Enemy(WINDOW &screen)
		: NcursesRenderable(screen)
{
}

Enemy::~Enemy()
{
}

Enemy::Enemy(Enemy const &rhs)
		: NcursesRenderable(rhs.screen)
{
	*this = rhs;
}

Enemy &Enemy::operator=(Enemy const &)
{
	return *this;
}

void Enemy::render()
{
	mvwaddstr(&screen, row, col, "/--\\");
	mvwaddstr(&screen, row + 1, col, "|  |");
	mvwaddstr(&screen, row + 2, col, "\\--/");
}

void Enemy::randomMove()
{
	static int keyList[] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN};
	if (frame == 60)
	{
		int r = rand() % 4;
		moveByChar(keyList[r]);
		frame = 0;
	}
	else
		frame++;
}
