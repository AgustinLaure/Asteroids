#include "Game.h"

#include "raylib.h"

#include "Screen.h"

namespace game
{
	void game()
	{
		float delta = 0.0f;

		ship::Ship ship;
		ship::init(ship);

		screen::openWindow();

		while (!WindowShouldClose())
		{
			game::update(ship, delta);
			game::draw(ship);
		}

		screen::closeWindow();
	}

	void update(ship::Ship& ship, float& delta)
	{
		delta = GetFrameTime();
		ship::update(ship, delta);
	}

	void draw(ship::Ship ship)
	{
		BeginDrawing();

		ship::draw(ship);

		ClearBackground(BLACK);

		EndDrawing();
	}
}
