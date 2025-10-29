#pragma once

#include "raylib.h"

namespace screen
{
	const int screenWidth = 1024;
	const int screenHeight = 768;
	
	void openWindow();
	void closeWindow();
	bool isOutScreen(Vector2 pos);
}

