#pragma once

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"

namespace ship
{
	const int shipSides = 3;
	const int shipRadius = 20;
	const Vector2 shipInitialPos = {500, 500};
	const Vector2 shipInitialDir = {0,-1};
	const Vector2 shipInitialVelocity = { 0,0 };
	const float shipInitialRotation = 270.0f;
	const float shipAccelPerFrame = 0.1f;

	const MouseButton moveShipButton = MOUSE_RIGHT_BUTTON;

	struct Ship
	{
		Vector2 pos = {};
		Vector2 lookDir = {};
		Vector2 velocity = {};
		float rotation = 0.0f;
	};

	void init(Ship& ship);
	void update(Ship& ship, float& delta);
	void draw(Ship ship);
	void move(Ship& ship, float delta);
	void updateLookDir(Ship& ship);
	void updateRotation(Ship& ship);
	void outOfScreen(Ship& ship);
}

