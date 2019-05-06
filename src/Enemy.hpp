#ifndef FT_ENEMY_HPP
#define FT_ENEMY_HPP

#include "ncurses.h"
#include "NcursesRenderable.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

class Enemy : virtual public NcursesRenderable
{
private:
public:
	Enemy();
	Enemy(WINDOW &screen);
	~Enemy();
	Enemy(Enemy const &rhs);
	Enemy &operator=(Enemy const &rhs);

	void randomMove();
	void render();
};

#endif /* FT_ENEMY_HPP */
