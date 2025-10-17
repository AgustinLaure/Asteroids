#pragma once

#include "Vector.h"

namespace ship
{
	const int shipSides = 3;
	const int shipRadius = 20;
	const Vector2 shipInitialPos = {500, 500};
	const Vector2 shipInitialDir = {0,-1};
	const float shipInitialRotation = 0.0f;
	const float shipAccelPerFrame = 0.01f;

	struct Ship
	{
		Vector2 pos = {};
		Vector2 dir = {};
		float rotation = 0.0f;
		float speed = 10.0f;
		float accel = 0.0f;
	};

	void init(Ship& ship);
	void update(Ship& ship, float& delta);
	void draw(Ship ship);
	void move(Ship& ship, float delta);
}

