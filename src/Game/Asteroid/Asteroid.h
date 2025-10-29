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

	const int maxAsteroidTypes = 3;

	const int asteroidsShatterPoints[maxAsteroidTypes] =
	{
		10,
		12,
		15
	};

	const int asteroidsDamage[maxAsteroidTypes] =
	{
		2,
		1,
		1
	};

	const int maxAsteroids = 150;
	const float asteroidSpawnCooldown = 0.25f;

	struct Asteroid
	{
		static Texture2D bigAsteroidSprite;
		static Texture2D medAsteroidSprite;
		static Texture2D smallAsteroidSprite;

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
		int dmg = 0;
	};

	void init(Asteroid asteroids[]);
	void update(Asteroid asteroids[], float& spawnCooldown, float delta);
	void draw(Asteroid asteroids[]);
	void reset(Asteroid& asteroid);
	void takeDamage(Asteroid asteroids[], int currentAsteroid, int damage);
}

