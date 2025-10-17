#include "Ship.h"

#include "raylib.h"

namespace ship
{
	void init(Ship& ship)
	{
		ship.pos = shipInitialPos;
		ship.dir = shipInitialDir;
		ship.rotation = shipInitialRotation;
	}

	void update(Ship& ship)
	{

	}

	void draw(Ship ship)
	{
		DrawPolyLines(ship.pos, shipSides,shipRadius,ship.rotation, WHITE);
	}
}