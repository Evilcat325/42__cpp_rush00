#ifndef FT_PLAYER_HPP
#define FT_PLAYER_HPP

#include "ncurses.h"
#include "NcursesRenderable.hpp"

class Player : virtual public NcursesRenderable
{
private:
	int hp;

public:
	Player(WINDOW &screen);
	~Player();
	Player(Player const &rhs);
	Player &operator=(Player const &rhs);

	bool render();
	void init();
	void detectCollision(int *&map);
	int getHP();
};

#endif /* FT_Player_HPP */
