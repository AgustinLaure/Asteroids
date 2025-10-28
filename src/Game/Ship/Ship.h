#pragma once

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Math/Form/Form.h"
#include "Game/Bullet/Bullet.h"
#include "Game/Asteroid/Asteroid.h"

namespace ship
{
	const int shipSides = 3;
	const int shipRadius = 20;
	const Vector2 shipInitialPos = {500, 500};
	const Vector2 shipInitialDir = {0,-1};
	const Vector2 shipInitialVelocity = { 0,0 };
	const float shipInitialRotation = 270.0f;
	const float shipAccelPerFrame = 0.1f;
	const int maxBullets = 5;
	const float distanceBetweenBullet = 30.0f;
	const float timeBetweenShots = 0.25f;
	const float timeBetweenTakingDamage = 1.0f;
	const int initialHp = 3;
	const int initialPoints = 0;

	const MouseButton moveShipButton = MOUSE_RIGHT_BUTTON;
	const MouseButton shootShipButton = MOUSE_LEFT_BUTTON;

	struct Ship
	{
		Vector2 pos = {};
		Vector2 lookDir = {};
		Vector2 velocity = {};
		float rotation = 0.0f;
		form::Circle hitBox;
		Color color = WHITE;
		bullet::Bullet bullets[maxBullets];
		float shootCooldown = 0.0f;
		float takeDamageCooldown = 0.0f;
		int hp = 0;
		bool isAlive = true;
		int points = 0;
		Sound onDie;
		Sound onTakeDamage;
		Sound onShoot;
	};

	void init(Ship& ship);
	void update(Ship& ship, asteroid::Asteroid asteroids[], float& delta);
	void draw(Ship ship);
	void move(Ship& ship, float delta);
	void updateLookDir(Ship& ship);
	void updateRotation(Ship& ship);
	void outOfScreen(Ship& ship);
	void shoot(Ship& ship, float delta);
	void hitAsteroid(Ship& ship, asteroid::Asteroid asteroids[], float delta);
}

