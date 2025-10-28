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
		ship.collision.pos = ship.pos;
		ship.collision.radius = shipRadius;
		bullet::initBullets(ship.bullets, maxBullets);
		ship.shootCooldown = timeBetweenShots;
		ship.hp = initialHp;
	}

	void update(Ship& ship, asteroid::Asteroid asteroids[], float& delta)
	{
		shoot(ship, delta);
		updateLookDir(ship);
		updateRotation(ship);
		bullet::update(ship.bullets, ship::maxBullets, asteroids, delta);

		outOfScreen(ship);
		move(ship, delta);
	}

	void draw(Ship ship)
	{
		DrawPolyLines(ship.pos, shipSides, shipRadius, ship.rotation, WHITE);

		bullet::draw(ship.bullets, ship::maxBullets);
	}

	void move(Ship& ship, float delta)
	{
		if (IsMouseButtonDown(moveShipButton))
		{
			ship.velocity = vector::getVectorSum(ship.velocity, vector::getVectorMult(vector::getVectorMult(ship.lookDir, shipAccelPerFrame), delta));
		}

		ship.pos = vector::getVectorSum(ship.pos, ship.velocity);
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

					return;
				}
			}
		}
	}
}