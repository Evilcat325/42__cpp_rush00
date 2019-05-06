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
	attron(COLOR_PAIR(PLAYER_PAIR));
	mvwaddstr(&screen, row, col, " * ");
	mvwaddstr(&screen, row + 1, col, "*X*");
	mvwaddstr(&screen, row + 2, col, "-*-");
	for (int i = 0; i < 50; ++i)
		if (attacks[i].isOnScreen())
			attacks[i].render();
	attroff(COLOR_PAIR(PLAYER_PAIR));
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
			if (map[(row + r) * width + col + c] == 1)
				hp = (hp - 5) > 0 ? hp - 5 : 0;
	for (int i = 0; i < 50; ++i)
		if (attacks[i].isOnScreen())
			attacks[i].detectCollision(map);
}

int Player::getHP()
{
	return hp;
}

void Player::shoot()
{
	for (int i = 0; i < 25; ++i)
	{
		if (attacks[i].isOnScreen())
			continue;
		attacks[i].setSpeedPower(1, 1);
		attacks[i].setRowCol(row, col);
		break;
	}
}
