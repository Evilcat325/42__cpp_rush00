#ifndef FT_ENEMYPROJECTILE_HPP
#define FT_ENEMYPROJECTILE_HPP

#include "Projectile.hpp"

class EnemyProjectile : virtual public Projectile
{
private:
	/* data */
public:
	EnemyProjectile();
	~EnemyProjectile();
	EnemyProjectile(EnemyProjectile const &rhs);
	EnemyProjectile &operator=(EnemyProjectile const &rhs);

	bool render();
};

#endif /* FT_EnemyProjectile_HPP */
