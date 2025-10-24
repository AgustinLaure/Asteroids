#include "Game/Bullet/Bullet.h"

#include "Game/Math/Vector/Vector.h"

namespace bullet
{
	static void move(Bullet& bullet);


	static void move(Bullet& bullet)
	{
		bullet.body.pos = vector::getVectorSum(bullet.body.pos, vector::getVectorMult(bullet.dir, bullet.speed));
	}

	void initBullets(Bullet bullets[])
	{
		for (int i = 0; i < maxBullets; i++)
		{
			bullets[i].body.pos = { 0,0 };
			bullets[i].body.radius = bulletInitialRadius;
			bullets[i].dmg = bulletInitialDmg;
			bullets[i].speed = bulletInitialSpeed;
			bullets[i].dir = { 0,0 };
			bullets[i].isOn = false;
		}
	}

	void update(Bullet bullets[])
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullets[i].isOn)
			{
				move(bullets[i]);
			}
		}
	}
}