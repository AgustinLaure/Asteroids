#pragma once

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"
#include "Game/Math/Form/Form.h"
#include "Game/Bullet/Bullet.h"

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

	const MouseButton moveShipButton = MOUSE_RIGHT_BUTTON;
	const MouseButton shootShipButton = MOUSE_LEFT_BUTTON;

	struct Ship
	{
		Vector2 pos = {};
		Vector2 lookDir = {};
		Vector2 velocity = {};
		float rotation = 0.0f;
		form::Circle collision;
		Color color = WHITE;
		bullet::Bullet bullets[maxBullets];
		float shootCooldown;
	};

	void init(Ship& ship);
	void update(Ship& ship, float& delta);
	void draw(Ship ship);
	void move(Ship& ship, float delta);
	void updateLookDir(Ship& ship);
	void updateRotation(Ship& ship);
	void outOfScreen(Ship& ship);
	void shoot(Ship& ship, float delta);
}

