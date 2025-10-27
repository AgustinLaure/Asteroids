#include "Screen.h"

#include <iostream>

#include "raylib.h"

#include "Game/Math/Vector/Vector.h"

namespace screen
{
	static const std::string screenName = "Asteroids";

	void openWindow()
	{
		InitWindow(screenWidth, screenHeight, screenName.c_str());
	}

	void closeWindow()
	{
		CloseWindow();
	}

	bool isOutScreen(Vector2 pos)
	{
		return pos.x < 0 || pos.x > screenWidth || pos.y < 0 || pos.y > screenHeight;
	}
}