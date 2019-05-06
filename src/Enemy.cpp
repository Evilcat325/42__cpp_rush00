#include "Enemy.hpp"

Enemy::Enemy()
		: NcursesRenderable(*stdscr)
{
	init();
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

bool Enemy::render()
{
	NcursesRenderable::render();
	if (!onScreen)
	{
		if ((frame % 600) == 0)
			init();
		else
			return false;
	}
	if ((frame % 10) == 0)
		verticalScroll();
	if ((frame % 30) == 0)
		randomMove();
	if (movedOffScreen())
		return false;

	attron(COLOR_PAIR(ENEMY_PAIR));
	mvwaddstr(&screen, row, col, "/--\\");
	mvwaddstr(&screen, row + 1, col, "|  |");
	mvwaddstr(&screen, row + 2, col, "\\--/");
	attroff(COLOR_PAIR(ENEMY_PAIR));
	return true;
}
void Enemy::init()
{
	row = 0;
	col = rand() % width;
	frame = 1;
	onScreen = true;
}

void Enemy::randomMove()
{
	static int keyList[] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN};
	int r = rand() % 4;
	moveByChar(keyList[r], false);
}

void Enemy::detectCollision(int *&map)
{
	for (int r = 0; r < 3 && 0 < row + r && row + r < height; ++r)
		for (int c = 0; c < 3 && 0 < col + c && col + c < width; ++c)
			map[(row + r) * width + col + c] = 1;
}
