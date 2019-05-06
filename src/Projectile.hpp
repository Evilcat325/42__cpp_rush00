#ifndef FT_PROJECTILE_HPP
#define FT_PROJECTILE_HPP

#include "NcursesRenderable.hpp"

class Projectile : virtual public NcursesRenderable
{
private:
	int speed;
	int power;

	/* data */
public:
	Projectile();
	Projectile(int speed, int power);
	~Projectile();
	Projectile(Projectile const &rhs);
	Projectile &operator=(Projectile const &rhs);

	void setSpeedPower(int sp, int po);
	bool render();
	int detectCollision(int *&map);
};

#endif /* FT_Projectile_HPP */
