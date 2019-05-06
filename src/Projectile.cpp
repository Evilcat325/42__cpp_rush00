#include "Projectile.hpp"

Projectile::Projectile()
{
	speed = 1;
	power = 1;
	onScreen = false;
}

Projectile::Projectile(int speed, int power) : speed(speed), power(power)
{
	onScreen = true;
}

Projectile::~Projectile()
{
}

Projectile::Projectile(Projectile const &rhs) : NcursesRenderable(rhs)
{
	*this = rhs;
}

Projectile &Projectile::operator=(Projectile const &rhs)
{
	speed = rhs.speed;
	power = rhs.power;
	return *this;
}

void Projectile::setSpeedPower(int sp, int po)
{
	speed = sp;
	power = po;
	onScreen = true;
}

bool Projectile::render()
{
	NcursesRenderable::render();
	if (frame % 30 == 0)
		--row;
	if (row < 0)
	{
		onScreen = false;
		return false;
	}
	mvwaddstr(&screen, row, col, "o");
	return true;
}

void Projectile::detectCollision(int *&map)
{
	map[row * width + col] = 42;
}
