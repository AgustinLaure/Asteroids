#pragma once

#include "Vector.h"

namespace Ship
{
	const int shipSides = 3;
	const int shipRadius = 10;

	const Vector2 shipInitialPos = {500, 500};
	const Vector2 shipInitialDir = {0,1};
	const float shipInitialRotation = 0.0f;

	struct Ship
	{
		Vector2 pos = {};
		Vector2 dir = {};
		float rotation = 0.0f;
		float speed = 10.0f;
	};

	void init(Ship& ship);
	void update(Ship& ship);
	void draw(Ship ship);
}

