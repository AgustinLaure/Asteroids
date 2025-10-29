#pragma once

#include <string>

#include "raylib.h"

namespace text
{
	struct Text
	{
		Vector2 pos = { 0,0 };
		std::string text = " ";
		float fontSize = 0.0f;
		float spacing = 0.0f;
		Color color = WHITE;
	};
}

