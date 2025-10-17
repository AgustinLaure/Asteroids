#include "Screen.h"

#include <iostream>

#include "raylib.h"

namespace screen
{
	static const std::string screenName = "Asteroids";

	void openWindow()
	{
		InitWindow(screenHeight, screenWidth, screenName.c_str());
	}

	void closeWindow()
	{
		CloseWindow();
	}
}