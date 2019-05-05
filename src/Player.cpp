#include "Player.hpp"

Player::Player(WINDOW &screen)
		: NcursesRenderable(screen)
{
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

void Player::render()
{
	mvwaddstr(&screen, row, col, " * ");
	mvwaddstr(&screen, row + 1, col, "*X*");
	mvwaddstr(&screen, row + 2, col, "-*-");
}

void Player::init()
{
	this->row = height - 3;
	this->col = (width - 3) / 2;
}
