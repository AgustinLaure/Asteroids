#include "Game/Bullet/Bullet.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Screen/Screen.h"

namespace bullet
{
	Sound Bullet::onLandHit;
	Texture2D Bullet::sprite;

	static void move(Bullet& bullet, float delta)
	{
		bullet.pos = vector::getVectorSum(bullet.hitBox.pos, vector::getVectorMult(bullet.dir, bullet.speed * delta));
		bullet.hitBox.pos = bullet.pos;
	}

	void initBullets(Bullet bullets[], int bulletAmount)
	{
		Bullet::onLandHit = LoadSound("res/sound/sfx/bullet/bulletHit.wav");
		Bullet::sprite = LoadTexture("res/sprite/bullet/bullet.png");

		for (int i = 0; i < bulletAmount; i++)
		{
			bullets[i].pos = { 0,0 };
			bullets[i].hitBox.pos = bullets[i].pos;
			bullets[i].hitBox.radius = bulletInitialRadius;
			bullets[i].dmg = bulletInitialDmg;
			bullets[i].speed = bulletInitialSpeed;
			bullets[i].dir = { 0,0 };
			bullets[i].isOn = false;
		}
	}

	void update(Bullet bullets[], int bulletAmount, asteroid::Asteroid asteroids[], int& shipPoints, float delta)
	{
		for (int i = 0; i < bulletAmount; i++)
		{
			if (bullets[i].isOn)
			{
				move(bullets[i], delta);
				outBounds(bullets[i]);
				hitAsteroid(bullets[i], asteroids, shipPoints);
			}
		}
	}

	void draw(Bullet bullets[], int bulletAmount)
	{
		for (int i = 0; i < bulletAmount; i++)
		{
			if (bullets[i].isOn)
			{
				DrawTexturePro(Bullet::sprite, { 0,0,static_cast<float>(Bullet::sprite.width), static_cast<float>(Bullet::sprite.height) }, { bullets[i].hitBox.pos.x, bullets[i].hitBox.pos.y, bullets[i].hitBox.radius * 2, bullets[i].hitBox.radius * 2 }, {bullets[i].hitBox.radius, bullets[i].hitBox.radius}, 0, bullets[i].color);
			}
		}
	}

	void shoot(Bullet& bullet, Vector2 pos, Vector2 dir)
	{
		bullet.hitBox.pos = pos;
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
		bullet.hitBox.pos = bullet.pos;
		bullet.dir = { 1,0 };
	}

	void hitAsteroid(Bullet& bullet, asteroid::Asteroid asteroids[], int& shipPoints)
	{
		for (int i = 0; i < asteroid::maxAsteroids; i++)
		{
			if (asteroids[i].isOn)
			{
				if (form::isCircleCollidingCircle(bullet.hitBox, asteroids[i].hitBox)) 
				{
					asteroid::takeDamage(asteroids, i, bullet.dmg);
					resetBullet(bullet);

					shipPoints += pointsPerHit;
					if (asteroids[i].hp<= 0)
					{
						shipPoints += asteroid::asteroidsShatterPoints[static_cast<int>(asteroids[i].type)];
					}

					PlaySound(bullet.onLandHit);

					return;
				}
			}
		}
	}
}