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
				WHITE								//color
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
				WHITE
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
		static void draw(button::Button rulesButtons[]);

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
				button::update(pauseButtons[i]);

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

		static void draw(button::Button pauseButtons[])
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(pauseButtons[i]);
			}

			DrawTextEx(GetFontDefault(), pauseText.text.c_str(), pauseText.pos, pauseText.fontSize, pauseText.spacing, pauseText.color);
		}
	}

	namespace lost
	{
		enum class Option
		{
			Back,
			Restart
		};

		const int maxButtons = 2;

		const MouseButton selectButton = MOUSE_LEFT_BUTTON;

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
					165.0f,
					optionsFontSize,
					{550,optionsHeightPos}
				},
			//text
			{
				{},
				"Restart",
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

		const int lostHeightPos = 175;

		const text::Text lostText =
		{
			{425,lostHeightPos},
			"You lost",
			60,
			2,
			WHITE
		};

		static void initButtons(button::Button loseButtons[]);
		static void update(button::Button loseButtons[], gameScene::Scene& currentScene, bool& ignoreMouse, bool& resetElements);
		static void draw(button::Button loseButtons[]);

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

		static void update(button::Button loseButtons[], gameScene::Scene& currentScene, bool& ignoreMouse, bool& resetElements)
		{
			for (int i = 0; i < maxButtons; i++)
			{
				loseButtons[i].isPressed = false;
			}

			for (int i = 0; i < maxButtons; i++)
			{
				button::update(loseButtons[i]);

				if (loseButtons[static_cast<int>(Option::Back)].isPressed)
				{
					currentScene = gameScene::Scene::MainMenu;
					ignoreMouse = true;
				}
				else if (loseButtons[static_cast<int>(Option::Restart)].isPressed)
				{
					resetElements = true;
					ignoreMouse = true;
				}
			}
		}

		static void draw(button::Button loseButtons[])
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(loseButtons[i]);
			}

			DrawTextEx(GetFontDefault(), lostText.text.c_str(), lostText.pos, lostText.fontSize, lostText.spacing, lostText.color);
		}
	}
	const float timeBetweenInput = 0.5f;

	static void update(ship::Ship& ship, asteroid::Asteroid asteroids[], float& asteroidSpawnCooldown, float& delta);
	static void drawPoints(int points);
	static void drawHp(int hp);
	static void draw(ship::Ship ship, asteroid::Asteroid asteroids[]);
	static void playing(ship::Ship& ship, asteroid::Asteroid asteroids[], button::Button pauseButtons[], button::Button loseButtons[], float& asteroidsCooldown, bool& isGamePaused, bool& isGameLost, gameScene::Scene& currentScene, bool& ignoreMouse, bool& resetElements, float delta);
	static void mainMenu(gameScene::Scene& currentScene, mainMenu::SubScene& currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], bool ignoreMouse);
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
		ship::draw(ship);
		asteroid::draw(asteroids);
		drawHp(ship.hp);
		drawPoints(ship.points);
	}

	static void playing(ship::Ship& ship, asteroid::Asteroid asteroids[], button::Button pauseButtons[], button::Button loseButtons[], float& asteroidsCooldown, bool& isGamePaused, bool& isGameLost, gameScene::Scene& currentScene, bool& ignoreMouse, bool& resetElements, float delta)
	{
		isGameLost = !ship.isAlive;

		if (isGameLost)
		{
			lost::update(loseButtons, currentScene, ignoreMouse, resetElements);
		}
		else if (isGamePaused)
		{
			pause::update(pauseButtons, currentScene, isGamePaused, ignoreMouse);
		}
		else
		{
			update(ship, asteroids, asteroidsCooldown, delta);

			if (IsKeyPressed(pause::pauseButton))
			{
				isGamePaused = true;
			}
		}

		BeginDrawing();
		ClearBackground(BLACK);

		draw(ship, asteroids);

		if (isGameLost)
		{
			lost::draw(loseButtons);
		}
		if (isGamePaused)
		{
			pause::draw(pauseButtons );
		}

		EndDrawing();
	}

	static void mainMenu(gameScene::Scene& currentScene, mainMenu::SubScene& currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], bool ignoreMouse)
	{
		if (!ignoreMouse)
		{
			mainMenu::update(currentScene, currentSubScene, titleScreenButtons, rulesButtons, creditsButtons, ignoreMouse);
		}

		mainMenu::draw(currentSubScene, titleScreenButtons, rulesButtons, creditsButtons);
	}

	static void resetElements(ship::Ship& ship, asteroid::Asteroid asteroids[])
	{
		ship::init(ship);
		asteroid::init(asteroids);
	}

	void runGame()
	{
		screen::openWindow();
		InitAudioDevice();

		float delta = 0.0f;

		ship::Ship ship;
		ship::init(ship);
		asteroid::Asteroid asteroids[asteroid::maxAsteroids];
		asteroid::init(asteroids);
		gameScene::Scene currentScene = gameScene::Scene::MainMenu;
		mainMenu::SubScene currentSubScene = mainMenu::SubScene::titleScreen;

		button::Button titleScreenButtons[mainMenu::titleScreen::maxButtons];
		mainMenu::titleScreen::initButtons(titleScreenButtons);

		button::Button rulesButtons[mainMenu::rules::maxButtons];
		mainMenu::rules::initButtons(rulesButtons);

		button::Button creditsButtons[mainMenu::credits::maxButtons];
		mainMenu::credits::initButtons(creditsButtons);

		button::Button pauseButtons[pause::maxButtons];
		pause::initButtons(pauseButtons);

		button::Button lostButtons[lost::maxButtons];
		lost::initButtons(lostButtons);

		Music menuMusic = LoadMusicStream("res/sound/music/menu/menuMusic.ogg");
		Music gameMusic = LoadMusicStream("res/sound/music/game/gameMusic.ogg");
		SetMusicVolume(menuMusic, 0.5f);
		SetMusicVolume(gameMusic, 0.5f);

		bool isGamePaused = false;
		bool ignoreMouse = false;
		bool resetGameElements = false;
		bool isGameLost = false;

		float asteroidsCooldown = asteroid::asteroidSpawnCooldown;

		PlayMusicStream(menuMusic);

		while (!WindowShouldClose() && currentScene != gameScene::Scene::Exit)
		{
			switch (currentScene)
			{
			case gameScene::Scene::Play:

				if (resetGameElements)
				{
					resetElements(ship, asteroids);
					resetGameElements = false;
				}
				if (!IsMusicStreamPlaying(gameMusic))
				{
					StopMusicStream(menuMusic);
					PlayMusicStream(gameMusic);
				}

				UpdateMusicStream(gameMusic);
				playing(ship, asteroids, pauseButtons, lostButtons, asteroidsCooldown, isGamePaused, isGameLost, currentScene, ignoreMouse, resetGameElements, delta);
				break;
			case gameScene::Scene::MainMenu:
				if (!IsMusicStreamPlaying(menuMusic))
				{
					StopMusicStream(gameMusic);
					PlayMusicStream(menuMusic);
				}

				UpdateMusicStream(menuMusic);
				mainMenu(currentScene, currentSubScene, titleScreenButtons, rulesButtons, creditsButtons, ignoreMouse);
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

		UnloadMusicStream(gameMusic);
		UnloadMusicStream(menuMusic);

		UnloadSound(button::Button::onSelect);
		UnloadSound(bullet::Bullet::onLandHit);
		UnloadSound(ship.onDie);
		UnloadSound(ship.onTakeDamage);
		UnloadSound(ship.onShoot);

		UnloadTexture(ship.sprite);

		CloseAudioDevice();
		screen::closeWindow();
	}
}
