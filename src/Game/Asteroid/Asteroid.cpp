#include "Game/Asteroid/Asteroid.h"

#include "Game/Screen/Screen.h"

namespace asteroid
{
	void init(Asteroid asteroids[])
	{
		for (int i = 0; i < maxAsteroids; i++)
		{
			asteroids[i].type = AsteroidTypes::Big;
			asteroids[i].pos = { 0,0 };
			asteroids[i].dir = { 1,0 };
			asteroids[i].isOn = false;
			asteroids[i].radius = asteroidsRadius[static_cast<int>(asteroids[i].type)];
			asteroids[i].rotation = 0.0f;
			asteroids[i].speed = asteroidsSpeed[static_cast<int>(asteroids[i].type)];
			asteroids[i].hp = asteroidsHp[static_cast<int>(asteroids[i].type)];
			asteroids[i].hitBox.pos = asteroids[i].pos;
			asteroids[i].hitBox.radius = asteroids[i].radius;
		}
	}

	void update(Asteroid asteroids[], float& spawnCooldown, float delta)
	{
		spawnCooldown -= 1 * delta;

		if (spawnCooldown <= 0)
		{
			if (GetRandomValue(0, 100) <= asteroidSpawnPercentage)
			{
				spawnAsteroid(asteroids);
			}
			spawnCooldown = asteroidSpawnCooldown;
		}
		
		for (int i = 0; i < maxAsteroids; i++)
		{
			if (asteroids[i].isOn)
			{
				move(asteroids[i], delta);
				outBounds(asteroids[i]);
				rotate(asteroids[i], delta);
			}
		}
	}

	void draw(Asteroid asteroids[])
	{
		for (int i = 0; i < maxAsteroids; i++)
		{
			if (asteroids[i].isOn)
			{
				DrawPolyLines(asteroids[i].pos, 5, asteroids[i].radius, asteroids[i].rotation, asteroids[i].color);
				DrawCircleV(asteroids[i].hitBox.pos, asteroids[i].hitBox.radius, WHITE);
			}
		}
	}

	void move(Asteroid& asteroid, float delta)
	{
		asteroid.pos = vector::getVectorSum(asteroid.pos, vector::getVectorMult(asteroid.dir, asteroid.speed * delta));
		asteroid.hitBox.pos = asteroid.pos;
	}

	void spawnAsteroid(Asteroid asteroids[])
	{
		for (int i = 0; i < maxAsteroids; i++)
		{
			if (!asteroids[i].isOn)
			{
				setRandomSpawn(asteroids[i]);
				asteroids[i].isOn = true;

				return;
			}
		}
	}

	void setRandomSpawn(Asteroid& asteroid)
	{
		AsteroidSpawnPoint spawnPoint = static_cast<AsteroidSpawnPoint>(GetRandomValue(0, maxAsteroidSpawnPoints));
		Vector2 pos = {};
		Vector2 dir = {};
		float randomAngle = static_cast<float>(GetRandomValue(0, 180));

		switch (spawnPoint)
		{
		case asteroid::AsteroidSpawnPoint::Top:
			pos.x = static_cast<float>(GetRandomValue(0, screen::screenWidth));
			pos.y = 0;
			break;

		case asteroid::AsteroidSpawnPoint::Left:
			pos.x = 0;
			pos.y = static_cast<float>(GetRandomValue(0, screen::screenHeight));
			randomAngle += randomAngle;
			if (randomAngle >= 360)
			{
				randomAngle -= 360;
			}
			break;

		case asteroid::AsteroidSpawnPoint::Right:
			pos.x = screen::screenWidth;
			pos.y = static_cast<float>(GetRandomValue(0, screen::screenHeight));
			randomAngle += 90;
			break;

		case asteroid::AsteroidSpawnPoint::Bottom:
			pos.x = static_cast<float>(GetRandomValue(0, screen::screenWidth));
			pos.y = screen::screenHeight;
			randomAngle += 180;
			break;

		default:
			break;
		}

		asteroid.pos = pos;
		dir = vector::getDir(randomAngle);
		asteroid.dir = dir;
	}

	void outBounds(Asteroid& asteroid)
	{
		if (screen::isOutScreen(asteroid.pos))
		{
			reset(asteroid);
		}
	}

	void rotate(Asteroid& asteroid, float delta)
	{
		asteroid.rotation += asteroidsRotationSpeed[static_cast<int>(asteroid.type)] * delta;
	}

	void reset(Asteroid& asteroid)
	{
		asteroid.isOn = false;
		asteroid.type = AsteroidTypes::Big;
		asteroid.radius = asteroidsRadius[static_cast<int>(asteroid.type)];
		asteroid.hitBox.radius = asteroid.radius;
		asteroid.hp = asteroidsHp[static_cast<int>(asteroid.type)];
	}

	void takeDamage(Asteroid asteroids[], int currentAsteroid, int damage)
	{
		asteroids[currentAsteroid].hp -= damage;

		if (asteroids[currentAsteroid].hp <= 0)
		{
			asteroids[currentAsteroid].hp = 0;
			shatter(asteroids, currentAsteroid);
		}
	}

	void shatter(Asteroid asteroids[], int toShatter)
	{
		//float points = asteroidsShatterPoints[static_cast<int>(asteroids[toShatter].type)];

		AsteroidTypes piecesType = asteroidPiecesType[static_cast<int>(asteroids[toShatter].type)];

		asteroids[toShatter].isOn = false;

		Vector2 randomDir = vector::getDir(static_cast<float>(GetRandomValue(0,360)));
		int shatterCount = 0;

		int i = 0;
		if (piecesType <= AsteroidTypes::Small)
		{
			while (shatterCount < maxShatter && i < maxAsteroids)
			{
				if (!asteroids[i].isOn)
				{
					asteroids[i].type = piecesType;

					if (shatterCount % 2 != 0)
					{
						randomDir= vector::getVectorMult(randomDir, -1);
					}

					asteroids[i].dir = randomDir;

					asteroids[i].pos = vector::getVectorSum(asteroids[toShatter].pos, vector::getVectorMult(asteroids[toShatter].dir,piecesShatterDistance));
					asteroids[i].radius = asteroidsRadius[static_cast<int>(piecesType)];
					asteroids[i].hitBox.radius = asteroids[i].radius;
					asteroids[i].speed = asteroidsSpeed[static_cast<int>(piecesType)];
					asteroids[i].isOn = true;
					shatterCount++;
				}

				i++;
			}
		}
	}
}