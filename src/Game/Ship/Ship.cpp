#include "Ship.h"

#include <iostream>

#include "raylib.h"

namespace ship
{
	void init(Ship& ship)
	{
		ship.pos = shipInitialPos;
		ship.dir = shipInitialDir;
		ship.rotation = shipInitialRotation;
	}

	void update(Ship& ship, float& delta)
	{
		move(ship, delta);
	}

	void draw(Ship ship)
	{
		DrawPolyLines(ship.pos, shipSides,shipRadius,ship.rotation, WHITE);
	}

	void move(Ship& ship, float delta)
	{
		Vector2 shipMove = {};
		shipMove = vector::getVectorMult(ship.dir, ship.speed);
		shipMove = vector::getVectorMult(shipMove, ship.accel);
		shipMove = vector::getVectorMult(shipMove, delta);
		ship.accel += shipAccelPerFrame;

		std::cout << delta;
		ship.pos = vector::getVectorSum(ship.pos, shipMove);
	}
}