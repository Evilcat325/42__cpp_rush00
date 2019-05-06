#ifndef FT_ENEMYPROJECTILE_HPP
#define FT_ENEMYPROJECTILE_HPP

#include "Projectile.hpp"
// #include "GameSession.hpp"

class EnemyProjectile : virtual public Projectile
{
private:
	int target_row;
	int target_col;

public:
	EnemyProjectile();
	~EnemyProjectile();
	EnemyProjectile(EnemyProjectile const &rhs);
	EnemyProjectile &operator=(EnemyProjectile const &rhs);

	bool render();
	void setTarget();
};

#endif /* FT_EnemyProjectile_HPP */
