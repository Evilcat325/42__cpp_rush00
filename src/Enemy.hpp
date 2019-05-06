#ifndef FT_ENEMY_HPP
#define FT_ENEMY_HPP

#include "ncurses.h"
#include "NcursesRenderable.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

// enum EnemyState
// {
// 	ONSCREEN,
// 	OFFSCREEN
// };

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
	bool render();
	void detectCollision(int *&);
};

#endif /* FT_ENEMY_HPP */
