#include "Game/Game.h"

#include <string>

#include "raylib.h"

#include "Game/Screen/Screen.h"
#include "Game/Ship/Ship.h"
#include "Game/Asteroid/Asteroid.h"

namespace game
{
	static void update(ship::Ship& ship, asteroid::Asteroid asteroids[], float& asteroidSpawnCooldown, float& delta);
	static void draw(ship::Ship ship, asteroid::Asteroid asteroids[]);
	static void drawHp(int hp);

	static void update(ship::Ship& ship, asteroid::Asteroid asteroids[], float& asteroidSpawnCooldown, float& delta)
	{
		delta = GetFrameTime();
		ship::update(ship, asteroids, delta);
		asteroid::update(asteroids, asteroidSpawnCooldown, delta);
	}

	static void drawPoints(int points)
	{
		std::string text = "Points: " + std::to_string(points);

		DrawText(text.c_str(), 0, screen::screenHeight-40, 40, WHITE);
	}

	static void drawHp(int hp)
	{
		for (int i = 0; i < hp; i++)
		{
			DrawText("<3", 0 + (100 * i), 0, 40, RED);
		}
	}

	static void draw(ship::Ship ship, asteroid::Asteroid asteroids[])
	{
		BeginDrawing();
		ClearBackground(BLACK);

		ship::draw(ship);
		asteroid::draw(asteroids);
		drawHp(ship.hp);
		drawPoints(ship.points);

		EndDrawing();
	}

	void runGame()
	{
		float delta = 0.0f;

		ship::Ship ship;
		ship::init(ship);
		asteroid::Asteroid asteroids[asteroid::maxAsteroids];
		asteroid::init(asteroids);

		float asteroidsCooldown = asteroid::asteroidSpawnCooldown;

		screen::openWindow();

		while (!WindowShouldClose())
		{
			update(ship, asteroids, asteroidsCooldown, delta);
			draw(ship, asteroids);
		}

		screen::closeWindow();
	}
}
