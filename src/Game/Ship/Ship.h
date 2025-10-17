#pragma once

#include "Vector.h"

namespace Ship
{
	struct Ship
	{
		vector::Vector2f pos = {};
		vector::Vector2f dir = {};

	};
	void update();
	void draw();
}

