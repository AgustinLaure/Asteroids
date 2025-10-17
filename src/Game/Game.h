#pragma once

#include "Ship.h"

namespace game
{
	void game();
	void update(ship::Ship& ship, float& delta);
	void draw(ship::Ship ship);
}

