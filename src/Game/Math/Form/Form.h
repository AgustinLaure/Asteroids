#pragma once

#include "raylib.h"

namespace Form
{
	struct Circle
	{
		float radius = 0.0f;
		Vector2 pos = {0,0};
	};

	bool isCircleCollidingCircle(Circle c1, Circle c2);
}

