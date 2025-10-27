#pragma once

#include "Game/Math/Vector/Vector.h"

namespace screen
{
	const int screenHeight = 1024;
	const int screenWidth = 768;
	
	void openWindow();
	void closeWindow();
	bool isOutScreen(Vector2 pos);
}

