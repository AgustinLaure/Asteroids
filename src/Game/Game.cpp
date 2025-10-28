#include "Game/Game.h"

#include <string>

#include "raylib.h"

#include "Game/Screen/Screen.h"
#include "Game/Ship/Ship.h"
#include "Game/Asteroid/Asteroid.h"
#include "Game/MainMenu/MainMenu.h"
#include "Game/GameScene.h"

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

	static void playing(ship::Ship& ship, asteroid::Asteroid asteroids[], float& asteroidsCooldown, float delta)
	{
		update(ship, asteroids, asteroidsCooldown, delta);
		draw(ship, asteroids);
	}

	static void mainMenu(gameScene::Scene& currentScene, mainMenu::SubScene& currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], Font gameFont)
	{
		mainMenu::update(currentScene, currentSubScene, titleScreenButtons, rulesButtons, creditsButtons);
		mainMenu::draw(currentSubScene, titleScreenButtons, rulesButtons, creditsButtons, gameFont);
	}

	void runGame()
	{
		float delta = 0.0f;
		
		ship::Ship ship;
		ship::init(ship);
		asteroid::Asteroid asteroids[asteroid::maxAsteroids];
		asteroid::init(asteroids);
		gameScene::Scene currentScene = gameScene::Scene::MainMenu;
		mainMenu::SubScene currentSubScene = mainMenu::SubScene::titleScreen;
		Font gameFont = LoadFont("res/Font/ARCADE_I.TTF");

		button::Button titleScreenButtons[mainMenu::titleScreen::maxButtons];
		mainMenu::titleScreen::initButtons(titleScreenButtons);

		button::Button rulesButtons[mainMenu::rules::maxButtons];
		mainMenu::rules::initButtons(rulesButtons);

		button::Button creditsButtons[mainMenu::credits::maxButtons];
		mainMenu::credits::initButtons(creditsButtons);

		float asteroidsCooldown = asteroid::asteroidSpawnCooldown;

		screen::openWindow();

		while (!WindowShouldClose() && currentScene != gameScene::Scene::Exit)
		{
			switch (currentScene)
			{
			case gameScene::Scene::Play:
				playing(ship, asteroids, asteroidsCooldown, delta);
				break;
			case gameScene::Scene::MainMenu:
				mainMenu(currentScene, currentSubScene, titleScreenButtons, rulesButtons, creditsButtons, gameFont);
				break;
			default:
				break;
			}
		}

		screen::closeWindow();
	}
}
