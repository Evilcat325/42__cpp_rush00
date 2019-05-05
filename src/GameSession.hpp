#ifndef FT_GAMESESSION_HPP
#define FT_GAMESESSION_HPP

#include "NcursesRenderable.hpp"
#include "Player.hpp"

enum GameState
{
	RUNNING,
	PAUSED,
	ENDED
};

class GameSession : public virtual NcursesRenderable
{
private:
	GameState state;
	Player p1;

public:
	GameSession(WINDOW &screen, Player const &p1);
	~GameSession();
	GameSession(GameSession const &rhs);
	GameSession &operator=(GameSession const &rhs);

	void start();
	void end();
};

#endif /* FT_GameSession_HPP */
