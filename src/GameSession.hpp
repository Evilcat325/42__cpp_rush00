#ifndef FT_GAMESESSION_HPP
#define FT_GAMESESSION_HPP

#include "NcursesRenderable.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "ncurses.h"
#include "IRenderable.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>

// enum GameState
// {
// 	RUNNING,
// 	PAUSED,
// 	ENDED
// };

class GameSession : virtual public NcursesRenderable
{
private:
	Player &p1;
	Enemy enemy[25];
	int *map;

public:
	GameSession(WINDOW &screen, Player &p1);
	~GameSession();
	GameSession(GameSession const &rhs);
	GameSession &operator=(GameSession const &rhs);

	bool isPlayerOneMove(int key);
	bool render();
	void renderPerSec();
	void detectCollision(int *&);
	void updateMap();
};

#endif /* FT_GameSession_HPP */
