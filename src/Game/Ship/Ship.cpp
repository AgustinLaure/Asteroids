#include "Game/Ship/Ship.h"

#include <iostream>

#include "raylib.h"

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
		move(ship, delta);
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
		if (ship.lookDir.x == 0)
		{

		}
	}
}