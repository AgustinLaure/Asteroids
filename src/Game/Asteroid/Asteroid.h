#pragma once

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Math/Form/Form.h"

namespace asteroid
{
	enum class AsteroidTypes
	{
		Big,
		Medium,
		Small,
		None
	};

	const int maxAsteroids = 100;
	const int maxAsteroidTypes = 3;
	const int asteroidSpawnPercentage = 50;
	const float asteroidSpawnCooldown = 0.25f;
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

	const float asteroidsShatterPoints[maxAsteroidTypes] =
	{
		10.0f,
		12.0f,
		15.0f
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

	struct Asteroid
	{
		AsteroidTypes type = AsteroidTypes::Big;
		Vector2 pos = { 0,0 };
		Vector2 dir = { 1,0 };
		bool isOn = false;
		form::Circle hitBox;
		Color color = WHITE;
		float radius = 0.0f;
		float rotation = 0.0f;
		float speed = 0.0f;
		int hp = 0;
	};

	void init(Asteroid asteroids[]);
	void update(Asteroid asteroids[], float& spawnCooldown, float delta);
	void draw(Asteroid asteroids[]);
	void move(Asteroid& asteroid, float delta);
	void spawnAsteroid(Asteroid asteroids[]);
	void setRandomSpawn(Asteroid& asteroid);
	void outBounds(Asteroid& asteroid);
	void rotate(Asteroid& asteroid, float delta);
	void reset(Asteroid& asteroid);
	void takeDamage(Asteroid asteroids[], int currentAsteroid, int damage);
	void shatter(Asteroid asteroids[], int toShatter);
}

