#include "Enemy.hpp"

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
}
