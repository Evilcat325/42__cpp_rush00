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
	mvwaddch(&screen, row, col, 'X');
}
