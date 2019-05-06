#include "EnemyProjectile.hpp"

EnemyProjectile::EnemyProjectile()
{
	speed = 1;
	power = 1;
	onScreen = false;
	mark = 10;
}

EnemyProjectile::~EnemyProjectile()
{
}

EnemyProjectile::EnemyProjectile(EnemyProjectile const &rhs)
{
	mark = 10;
	*this = rhs;
}

EnemyProjectile &EnemyProjectile::operator=(EnemyProjectile const &)
{
	mark = 10;
	return *this;
}

bool EnemyProjectile::render()
{
	NcursesRenderable::render();
	if (frame % 10 == 0)
	{
		//int diff = target_col - col + target_row - row;
		++row;
		++col;
	}
	if (movedOffScreen())
	{
		onScreen = false;
		return false;
	}
	mvwaddstr(&screen, row, col, "x");
	return true;
}

void EnemyProjectile::setTarget()
{
	target_row = 0;
	target_col = 0;
}
