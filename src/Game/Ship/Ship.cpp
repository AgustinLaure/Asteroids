#include "Game/Ship/Ship.h"

#include <iostream>

#include "raylib.h"

#include "Game/Screen/Screen.h"

namespace ship
{
	void init(Ship& ship)
	{
		ship.pos = shipInitialPos;
		ship.lookDir = shipInitialDir;
		ship.velocity = shipInitialVelocity;
		ship.rotation = shipInitialRotation;
		ship.hitBox.pos = ship.pos;
		ship.hitBox.radius = shipRadius;
		bullet::initBullets(ship.bullets, maxBullets);
		ship.shootCooldown = timeBetweenShots;
		ship.takeDamageCooldown = timeBetweenTakingDamage;
		ship.hp = initialHp;
		ship.isAlive = true;
		ship.points = initialPoints;
		ship.onDie = LoadSound("res/sound/sfx/ship/destroy.ogg");
		ship.onTakeDamage = LoadSound("res/sound/sfx/ship/receiveHit.ogg");
		ship.onShoot = LoadSound("res/sound/sfx/ship/shoot.wav");
		ship.sprite = LoadTexture("res/sprite/ship/spaceShip.png");
	}

	void update(Ship& ship, asteroid::Asteroid asteroids[], float& delta)
	{
		shoot(ship, delta);
		updateLookDir(ship);
		updateRotation(ship);
		bullet::update(ship.bullets, ship::maxBullets, asteroids, ship.points, delta);
		hitAsteroid(ship, asteroids, delta);

		outOfScreen(ship);
		move(ship, delta);
	}

	void draw(Ship ship)
	{
		if (ship.isAlive)
		{
			DrawTexturePro(ship.sprite, { 0,0,static_cast<float>(ship.sprite.width), static_cast<float>(ship.sprite.height) }, { ship.hitBox.pos.x, ship.hitBox.pos.y, ship.hitBox.radius * 2,ship.hitBox.radius * 2 }, {ship.hitBox.radius, ship.hitBox.radius}, ship.rotation, ship.color);

			bullet::draw(ship.bullets, ship::maxBullets);
		}
	}

	void move(Ship& ship, float delta)
	{
		if (IsMouseButtonDown(moveShipButton))
		{
			ship.velocity = vector::getVectorSum(ship.velocity, vector::getVectorMult(vector::getVectorMult(ship.lookDir, shipAccelPerFrame), delta));
		}

		ship.pos = vector::getVectorSum(ship.pos, ship.velocity);
		ship.hitBox.pos = ship.pos;
	}

	void updateLookDir(Ship& ship)
	{
		ship.lookDir = vector::getNormalized(vector::getVectorSub(GetMousePosition(), ship.pos));
	}

	void updateRotation(Ship& ship)
	{
		ship.rotation = vector::getDegree(ship.pos, GetMousePosition());
	}

	void outOfScreen(Ship& ship)
	{
		float screenWidth = static_cast<float>(GetScreenWidth());
		float screenHeight = static_cast<float>(GetScreenHeight());

		if (ship.pos.x >= screenWidth)
		{
			ship.pos.x = 0;
		}
		else if (ship.pos.x <= 0)
		{
			ship.pos.x = screenWidth;
		}

		if (ship.pos.y >= screenHeight)
		{
			ship.pos.y = 0;
		}
		else if (ship.pos.y <= 0)
		{
			ship.pos.y = screenHeight;
		}
	}

	void shoot(Ship& ship, float delta)
	{
		Vector2 bulletStartPos = vector::getVectorSum(ship.pos, vector::getVectorMult(ship.lookDir, distanceBetweenBullet));

		ship.shootCooldown -= 1 * delta;

		if (IsMouseButtonPressed(shootShipButton) && ship.shootCooldown <= 0)
		{
			for (int i = 0; i < maxBullets; i++)
			{
				if (!ship.bullets[i].isOn)
				{
					bullet::shoot(ship.bullets[i], bulletStartPos, ship.lookDir);
					ship.shootCooldown = timeBetweenShots;

					PlaySound(ship.onShoot);

					return;
				}
			}
		}
	}

	void hitAsteroid(Ship& ship, asteroid::Asteroid asteroids[], float delta)
	{
		ship.takeDamageCooldown -= 1 * delta;

		if (ship.takeDamageCooldown <= 0)
		{
			for (int i = 0; i < asteroid::maxAsteroids; i++)
			{
				if (asteroids[i].isOn)
				{
					if (form::isCircleCollidingCircle(asteroids[i].hitBox, ship.hitBox))
					{

						ship.hp -= asteroids[i].dmg;

						if (ship.hp <= 0)
						{
							ship.hp = 0;
							ship.isAlive = false;
							PlaySound(ship.onDie);
						}
						else
						{
							PlaySound(ship.onTakeDamage);
						}

						ship.takeDamageCooldown = timeBetweenTakingDamage;

						return;
					}
				}
			}
		}
	}
}