#ifndef FT_GAMESESSION_HPP
#define FT_GAMESESSION_HPP

#include "NcursesRenderable.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "ncurses.h"

enum GameState
{
	RUNNING,
	PAUSED,
	ENDED
};

class GameSession
{
private:
	GameState state;
	WINDOW &screen;
	Player &p1;

public:
	GameSession(WINDOW &screen, Player &p1);
	~GameSession();
	GameSession(GameSession const &rhs);
	GameSession &operator=(GameSession const &rhs);

	void start();
	void render();
};

#endif /* FT_GameSession_HPP */
