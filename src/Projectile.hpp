#ifndef FT_PROJECTILE_HPP
#define FT_PROJECTILE_HPP

#include "NcursesRenderable.hpp"

class Projectile : public NcursesRenderable
{
private:
	int speed;
	int power;
	bool onScreen;
	/* data */
public:
	Projectile();
	Projectile(int speed, int power);
	~Projectile();
	Projectile(Projectile const &rhs);
	Projectile &operator=(Projectile const &rhs);

	bool isOnScreen();
	void setSpeedPower(int sp, int po);
	bool render();
	void detectCollision(int *&map);
};

#endif /* FT_Projectile_HPP */
