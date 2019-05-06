#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

class Player;
#include "ncurses.h"
#include <iostream>
#include "Player.hpp"
#include <sstream>

enum ColorPair
{
	PLAYER_PAIR = 1,
	ENEMY_PAIR,
	STAR_PAIR,
	HP_PAIR,
	REST_HP_PAIR
};

class Background
{
private:
	WINDOW &screen;
	int height;
	int width;
	typedef struct s_loc t_loc;
	t_loc *star_loc;

public:
	Background(WINDOW &screen);
	~Background();
	Background(Background const &rhs);
	Background &operator=(Background const &other);

	void init();
	void draw_star();
	void draw_hp(Player &p);
};

#endif
