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
		row++;
		if (rand() % 2 == 0)
			col++;
		else
			col--;
		// if (target_row >= row - 1)
		// 	row++;
		// else
		// {
		// 	int coldiff = target_col - col > 0 ? target_col - col : col - target_col;
		// 	int rowdiff = target_row - row > 0 ? target_row - row : row - target_row;
		// 	// int diff = coldiff + rowdiff + 1;
		// 	// int rdm = rand() % diff + 1;
		// 	if (coldiff > 0)
		// 		col += target_col >= col ? 1 : -1;
		// 	if (rowdiff > 0)
		// 		row += target_row >= row ? 1 : -1;
		// }
	}
	if (movedOffScreen())
	{
		onScreen = false;
		return false;
	}
	mvwaddstr(&screen, row, col, "x");
	return true;
}

void EnemyProjectile::setTarget(int r, int c)
{
	target_row = r;
	target_col = c;
}
