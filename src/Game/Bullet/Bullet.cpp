#include "Game/Bullet/Bullet.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Screen/Screen.h"

namespace bullet
{
	static void move(Bullet& bullet, float delta)
	{
		bullet.pos = vector::getVectorSum(bullet.body.pos, vector::getVectorMult(vector::getVectorMult(bullet.dir, bullet.speed), delta));
		bullet.body.pos = bullet.pos;
	}

	void initBullets(Bullet bullets[], int bulletAmount)
	{
		for (int i = 0; i < bulletAmount; i++)
		{
			bullets[i].pos = { 0,0 };
			bullets[i].body.pos = bullets[i].pos;
			bullets[i].body.radius = bulletInitialRadius;
			bullets[i].dmg = bulletInitialDmg;
			bullets[i].speed = bulletInitialSpeed;
			bullets[i].dir = { 0,0 };
			bullets[i].isOn = false;
		}
	}

	void update(Bullet bullets[], int bulletAmount, float delta)
	{
		for (int i = 0; i < bulletAmount; i++)
		{
			if (bullets[i].isOn)
			{
				move(bullets[i], delta);
				outBounds(bullets[i]);
			}
		}
	}

	void draw(Bullet bullets[], int bulletAmount)
	{
		for (int i = 0; i < bulletAmount; i++)
		{
			if (bullets[i].isOn)
			{
				DrawCircleV(bullets[i].body.pos, bullets[i].body.radius, bullets[i].color);
			}
		}
	}

	void shoot(Bullet& bullet, Vector2 pos, Vector2 dir)
	{
		bullet.body.pos = pos;
		bullet.dir = dir;
		bullet.isOn = true;
	}

	void outBounds(Bullet& bullet)
	{
		if (screen::isOutScreen(bullet.pos))
		{
			resetBullet(bullet);
		}
	}

	void resetBullet(Bullet& bullet)
	{
		bullet.isOn = false;
		bullet.pos = { 0,0 };
		bullet.body.pos = bullet.pos;
		bullet.dir = { 1,0 };
	}
}