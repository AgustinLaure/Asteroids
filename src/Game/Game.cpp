#include "Game/Game.h"

#include "raylib.h"

#include "Game/Screen/Screen.h"
#include "Game/Ship/Ship.h"
#include "Game/Asteroid/Asteroid.h"

namespace game
{
	static void update(ship::Ship& ship, float& delta);
	static void draw(ship::Ship ship);
	
	static void update(ship::Ship& ship, asteroid::Asteroid asteroids[], float& asteroidSpawnCooldown, float& delta)
	{
		delta = GetFrameTime();
		ship::update(ship, asteroids, delta);
		asteroid::update(asteroids, asteroidSpawnCooldown, delta);
	}

	static void draw(ship::Ship ship, asteroid::Asteroid asteroids[])
	{
		BeginDrawing();

		ship::draw(ship);
		asteroid::draw(asteroids);

		ClearBackground(BLACK);

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
			game::update(ship, asteroids, asteroidsCooldown, delta);
			game::draw(ship, asteroids);
		}

		screen::closeWindow();
	}	
}
