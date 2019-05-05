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
	mvwaddstr(&screen, row, col, "XXX");
	mvwaddstr(&screen, row + 1, col, "XXX");
	mvwaddstr(&screen, row + 2, col, "XXX");
}
