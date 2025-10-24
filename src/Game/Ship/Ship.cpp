#include "Game/Ship/Ship.h"

#include <iostream>

#include "raylib.h"

#include "Game/Math/Degree/Degree.h"
#include "Game/Screen/Screen.h"

namespace ship
{
	void init(Ship& ship)
	{
		ship.pos = shipInitialPos;
		ship.lookDir = shipInitialDir;
		ship.velocity = shipInitialVelocity;
		ship.rotation = shipInitialRotation;
	}

	void update(Ship& ship, float& delta)
	{
		updateLookDir(ship);
		updateRotation(ship);
		move(ship, delta);
		outOfScreen(ship);
	}

	void draw(Ship ship)
	{
		DrawPolyLines(ship.pos, shipSides,shipRadius,ship.rotation, WHITE);
	}

	void move(Ship& ship, float delta)
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
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
		ship.rotation = degree::getDegree(ship.pos, GetMousePosition());
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
}