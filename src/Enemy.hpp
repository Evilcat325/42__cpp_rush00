#ifndef FT_ENEMY_HPP
#define FT_ENEMY_HPP

#include "ncurses.h"
#include "NcursesRenderable.hpp"
#include <string>

class Enemy : virtual public NcursesRenderable
{
private:
public:
	Enemy(WINDOW &screen);
	~Enemy();
	Enemy(Enemy const &rhs);
	Enemy &operator=(Enemy const &rhs);
};

#endif /* FT_ENEMY_HPP */
