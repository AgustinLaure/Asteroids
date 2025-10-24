#include "Game/Game.h"

#include "raylib.h"

#include "Game/Screen/Screen.h"
#include "Game/Ship/Ship.h"

namespace game
{
	
	static void update(ship::Ship& ship, float& delta);
	static void draw(ship::Ship ship);
	static void game();
	void runGame()
	{
		game();
	}

	static void game()
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

	static void update(ship::Ship& ship, float& delta)
	{
		delta = GetFrameTime();
		ship::update(ship, delta);
	}

	static void draw(ship::Ship ship)
	{
		BeginDrawing();

		ship::draw(ship);

		ClearBackground(BLACK);

		EndDrawing();
	}
}
