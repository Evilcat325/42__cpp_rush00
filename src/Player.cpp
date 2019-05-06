#include "Player.hpp"

Player::Player(WINDOW &screen)
		: NcursesRenderable(screen)
{
	hp = 100;
}

Player::~Player()
{
}

Player::Player(Player const &rhs)
		: NcursesRenderable(rhs.screen)
{
	*this = rhs;
}

Player &Player::operator=(Player const &)
{
	return *this;
}

bool Player::render()
{
	mvwaddstr(&screen, row, col, " * ");
	mvwaddstr(&screen, row + 1, col, "*X*");
	mvwaddstr(&screen, row + 2, col, "-*-");
	return true;
}

void Player::init()
{
	this->row = height - 3;
	this->col = (width - 3) / 2;
}

void Player::detectCollision(int *&map)
{
	for (int r = 0; r < 3 && row + r < height; ++r)
		for (int c = 0; c < 3 && col + c < width; ++c)
			if (map[(row + r) * width + c] == 1)
				hp = 0;
}

int Player::getHP()
{
	return hp;
}
