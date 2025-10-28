#include "Game/Game.h"

#include <iostream>

#include "raylib.h"

#include "Game/Screen/Screen.h"
#include "Game/Ship/Ship.h"
#include "Game/Asteroid/Asteroid.h"
#include "Game/MainMenu/MainMenu.h"
#include "Game/GameScene.h"

namespace game
{
	namespace pause
	{
		enum class Option
		{
			Back,
			Resume
		};

		const int maxButtons = 2;

		const MouseButton selectButton = MOUSE_LEFT_BUTTON;
		const KeyboardKey pauseButton = KEY_P;

		const int optionsFontSize = 45;
		const int optionsHeightPos = 475;

		const button::Button buttonsConst[maxButtons] =
		{
			//button1
			{
				//body
				{
					100.0f,						//width
					optionsFontSize,			//height
					{350,optionsHeightPos}		//pos
				},
			//text
			{
				{},								//pos
				"Back",							//text
				optionsFontSize,				//fontSize
				2,								//spacing
				RED								//color
			},
			//color
			WHITE,
			//isPressed
			false
			},
			//button2
			{
				//body
				{
					149.0f,
					optionsFontSize,
					{550,optionsHeightPos}
				},
			//text
			{
				{},
				"Resume",
				optionsFontSize,
				2,
				RED
			},
			//color
			WHITE,
			//isPressed
			false
			},
		};

		const int pauseHeightPos = 175;

		const text::Text pauseText =
		{
			{425,pauseHeightPos},
			"Pause",
			60,
			2,
			WHITE
		};

		static void initButtons(button::Button pauseButtons[]);
		static void update(button::Button pauseButtons[], gameScene::Scene& currentScene, bool& isPaused, bool& ignoreMouse);
		static void draw(button::Button pauseButtons[], Font gameFont);

		static void initButtons(button::Button pauseButtons[])
		{
			for (int i = 0; i < maxButtons; i++)
			{
				float width = buttonsConst[i].body.width;
				float height = buttonsConst[i].body.height;
				Vector2 pos = buttonsConst[i].body.pos;
				std::string text = buttonsConst[i].text.text;
				float fontSize = buttonsConst[i].text.fontSize;
				float spacing = buttonsConst[i].text.spacing;
				Color textColor = buttonsConst[i].text.color;
				Color bckgColor = buttonsConst[i].color;

				button::init(pauseButtons[i], width, height, pos, text, fontSize, spacing, textColor, bckgColor);
			}
		}

		static void update(button::Button pauseButtons[], gameScene::Scene& currentScene, bool& isPaused, bool& ignoreMouse)
		{
			for (int i = 0; i < maxButtons; i++)
			{
				pauseButtons[i].isPressed = false;
			}

			if (IsKeyPressed(pause::pauseButton))
			{
				pauseButtons[static_cast<int>(Option::Resume)].isPressed = true;
			}

			for (int i = 0; i < maxButtons; i++)
			{
				if (IsMouseButtonPressed(selectButton))
				{
					if (form::isPointCollidingRect(GetMousePosition(), pauseButtons[i].body))
					{
						pauseButtons[i].isPressed = true;
					}
				}

				if (pauseButtons[static_cast<int>(Option::Back)].isPressed)
				{
					currentScene = gameScene::Scene::MainMenu;
					isPaused = false;
					ignoreMouse = true;
				}
				else if (pauseButtons[static_cast<int>(Option::Resume)].isPressed)
				{
					isPaused = false;
					ignoreMouse = true;
				}
			}
		}

		static void draw(button::Button pauseButtons[], Font gameFont)
		{
			BeginDrawing();

			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(pauseButtons[i], gameFont);
			}

			DrawTextEx(gameFont, pauseText.text.c_str(), pauseText.pos, pauseText.fontSize, pauseText.spacing, pauseText.color);

			EndDrawing();
		}
	}

	const float timeBetweenInput = 0.5f;

	static void update(ship::Ship& ship, asteroid::Asteroid asteroids[], float& asteroidSpawnCooldown, float& delta);
	static void drawPoints(int points);
	static void drawHp(int hp);
	static void draw(ship::Ship ship, asteroid::Asteroid asteroids[]);
	static void playing(ship::Ship& ship, asteroid::Asteroid asteroids[], button::Button pauseButtons[], float& asteroidsCooldown, bool& isGamePaused, gameScene::Scene& currentScene, Font gameFont, bool& sceneJustChanged, float delta);
	static void mainMenu(gameScene::Scene& currentScene, mainMenu::SubScene& currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], Font gameFont, bool ignoreMouse);
	static void resetElements(ship::Ship& ship, asteroid::Asteroid asteroids[]);

	static void update(ship::Ship& ship, asteroid::Asteroid asteroids[], float& asteroidSpawnCooldown, float& delta)
	{
		delta = GetFrameTime();

		ship::update(ship, asteroids, delta);
		asteroid::update(asteroids, asteroidSpawnCooldown, delta);
	}

	static void drawPoints(int points)
	{
		std::string text = "Points: " + std::to_string(points);

		DrawText(text.c_str(), 0, screen::screenHeight - 40, 40, WHITE);
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

	static void playing(ship::Ship& ship, asteroid::Asteroid asteroids[], button::Button pauseButtons[], float& asteroidsCooldown, bool& isGamePaused, gameScene::Scene& currentScene, Font gameFont, bool& ignoreMouse, float delta)
	{
		if (!isGamePaused)
		{
			update(ship, asteroids, asteroidsCooldown, delta);

			if (IsKeyPressed(pause::pauseButton))
			{
				isGamePaused = true;
			}
		}
		else
		{
			pause::update(pauseButtons, currentScene, isGamePaused, ignoreMouse);
		}

		if (!isGamePaused)
		{
			draw(ship, asteroids);
		}
		else
		{
			pause::draw(pauseButtons, gameFont);
		}
	}

	static void mainMenu(gameScene::Scene& currentScene, mainMenu::SubScene& currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], Font gameFont, bool ignoreMouse)
	{
		if (!ignoreMouse)
		{
			mainMenu::update(currentScene, currentSubScene, titleScreenButtons, rulesButtons, creditsButtons, ignoreMouse);
		}
		
		mainMenu::draw(currentSubScene, titleScreenButtons, rulesButtons, creditsButtons, gameFont);
	}

	static void resetElements(ship::Ship& ship, asteroid::Asteroid asteroids[])
	{
		ship::init(ship);
		asteroid::init(asteroids);
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

		button::Button pauseButtons[pause::maxButtons];
		pause::initButtons(pauseButtons);

		bool isGamePaused = false;
		bool ignoreMouse = false;
		bool resetGameElements = false;

		float asteroidsCooldown = asteroid::asteroidSpawnCooldown;

		screen::openWindow();

		while (!WindowShouldClose() && currentScene != gameScene::Scene::Exit)
		{
			switch (currentScene)
			{
			case gameScene::Scene::Play:

				if (resetGameElements)
				{
					resetElements(ship,asteroids);
					resetGameElements = false;
				}
				playing(ship, asteroids, pauseButtons, asteroidsCooldown, isGamePaused, currentScene, gameFont, ignoreMouse, delta);
				break;
			case gameScene::Scene::MainMenu:
				mainMenu(currentScene, currentSubScene, titleScreenButtons, rulesButtons, creditsButtons, gameFont, ignoreMouse);
				resetGameElements = true;
				break;
			default:
				break;
			}

			if (ignoreMouse && IsMouseButtonUp(pause::selectButton))
			{
				ignoreMouse = false;
			}
		}

		screen::closeWindow();
	}
}
