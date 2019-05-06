#include "EnemyProjectile.hpp"

EnemyProjectile::EnemyProjectile()
{
}

EnemyProjectile::~EnemyProjectile()
{
}

EnemyProjectile::EnemyProjectile(EnemyProjectile const &rhs)
{
	*this = rhs;
}

EnemyProjectile &EnemyProjectile::operator=(EnemyProjectile const &)
{
	return *this;
}

bool EnemyProjectile::render()
{
	NcursesRenderable::render();
	if (frame % 10 == 0)
		++row;
	if (row < height)
	{
		onScreen = false;
		return false;
	}
	mvwaddstr(&screen, row, col, "x");
	return true;
}
