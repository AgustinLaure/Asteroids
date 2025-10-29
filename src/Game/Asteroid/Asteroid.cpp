#include "Game/Asteroid/Asteroid.h"

#include "Game/Screen/Screen.h"

namespace asteroid
{
	const int asteroidSpawnPercentage = 50;
	const float piecesShatterDistance = 10.0f;
	const int maxShatter = 2;

	const float asteroidsRadius[maxAsteroidTypes] =
	{
		25.0f,
		15.0f,
		5.0f
	};

	const float asteroidsSpeed[maxAsteroidTypes] =
	{
		40.0f,
		80.0f,
		120.0f
	};

	const float asteroidsRotationSpeed[maxAsteroidTypes] =
	{
		50.0f,
		100.0f,
		150.0f
	};

	const int asteroidsHp[maxAsteroidTypes] =
	{
		1,
		1,
		1
	};

	const AsteroidTypes asteroidPiecesType[maxAsteroidTypes] =
	{
		AsteroidTypes::Medium,
		AsteroidTypes::Small,
		AsteroidTypes::None
	};

	const int maxAsteroidSpawnPoints = 4;
	enum class AsteroidSpawnPoint
	{
		Top,
		Left,
		Right,
		Bottom
	};

	Texture2D Asteroid::bigAsteroidSprite;
	Texture2D Asteroid::medAsteroidSprite;
	Texture2D Asteroid::smallAsteroidSprite;

	static void move(Asteroid& asteroid, float delta);
	static void spawnAsteroid(Asteroid asteroids[]);
	static void setRandomSpawn(Asteroid& asteroid);
	static void outBounds(Asteroid& asteroid);
	static void rotate(Asteroid& asteroid, float delta);
	static void shatter(Asteroid asteroids[], int toShatter);

	static void move(Asteroid& asteroid, float delta)
	{
		asteroid.pos = vector::getVectorSum(asteroid.pos, vector::getVectorMult(asteroid.dir, asteroid.speed * delta));
		asteroid.hitBox.pos = asteroid.pos;
	}

	static void spawnAsteroid(Asteroid asteroids[])
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

	static void setRandomSpawn(Asteroid& asteroid)
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

	static void outBounds(Asteroid& asteroid)
	{
		if (screen::isOutScreen(asteroid.pos))
		{
			if (asteroid.pos.x < 0)
			{
				asteroid.pos.x = screen::screenWidth;
			}
			else if (asteroid.pos.x > screen::screenWidth)
			{
				asteroid.pos.x = 0;
			}
			else if (asteroid.pos.y < 0)
			{
				asteroid.pos.y = screen::screenHeight;
			}
			else if (asteroid.pos.y > screen::screenHeight)
			{
				asteroid.pos.y = 0;
			}
		}
	}

	static void rotate(Asteroid& asteroid, float delta)
	{
		asteroid.rotation += asteroidsRotationSpeed[static_cast<int>(asteroid.type)] * delta;
	}

	static void shatter(Asteroid asteroids[], int toShatter)
	{
		AsteroidTypes piecesType = asteroidPiecesType[static_cast<int>(asteroids[toShatter].type)];

		asteroids[toShatter].isOn = false;

		Vector2 randomDir = vector::getDir(static_cast<float>(GetRandomValue(0, 360)));
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
						randomDir = vector::getVectorMult(randomDir, -1);
					}

					asteroids[i].dir = randomDir;

					asteroids[i].pos = vector::getVectorSum(asteroids[toShatter].pos, vector::getVectorMult(asteroids[toShatter].dir, piecesShatterDistance));
					asteroids[i].radius = asteroidsRadius[static_cast<int>(piecesType)];
					asteroids[i].hitBox.radius = asteroids[i].radius;
					asteroids[i].speed = asteroidsSpeed[static_cast<int>(piecesType)];
					asteroids[i].dmg = asteroidsDamage[static_cast<int>(piecesType)];
					asteroids[i].isOn = true;
					shatterCount++;
				}

				i++;
			}
		}
		else if (piecesType == AsteroidTypes::Small)
		{
			reset(asteroids[i]);
		}
	}

	void init(Asteroid asteroids[])
	{
		Asteroid::bigAsteroidSprite = LoadTexture("res/sprite/asteroid/bigAsteroid.png");
		Asteroid::medAsteroidSprite = LoadTexture("res/sprite/asteroid/mediumAsteroid.png");
		Asteroid::smallAsteroidSprite = LoadTexture("res/sprite/asteroid/smallAsteroid.png");

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
			asteroids[i].dmg = asteroidsDamage[static_cast<int>(asteroids[i].type)];
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
		Texture2D sprite = {};

		for (int i = 0; i < maxAsteroids; i++)
		{
			if (asteroids[i].isOn)
			{	
				switch (asteroids[i].type)
				{
				case asteroid::AsteroidTypes::Big:
					sprite = Asteroid::bigAsteroidSprite;
					break;
				case asteroid::AsteroidTypes::Medium:
					sprite = Asteroid::medAsteroidSprite;
					break;
				case asteroid::AsteroidTypes::Small:
					sprite = Asteroid::smallAsteroidSprite;
					break;
				
				default:
					break;
				}

				DrawTexturePro(sprite, { 0,0,static_cast<float>(sprite.width),static_cast<float>(sprite.height) }, { asteroids[i].pos.x, asteroids[i].pos.y, asteroids[i].radius*2, asteroids[i].radius*2 }, {asteroids[i].radius, asteroids[i].radius},asteroids[i].rotation, asteroids[i].color);
			}
		}
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
}