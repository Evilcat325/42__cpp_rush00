#ifndef FT_PLAYER_HPP
#define FT_PLAYER_HPP

#include "ncurses.h"
#include "NcursesRenderable.hpp"

class Player : virtual public NcursesRenderable
{
private:
public:
	Player(WINDOW &screen);
	~Player();
	Player(Player const &rhs);
	Player &operator=(Player const &rhs);
};

#endif /* FT_Player_HPP */
