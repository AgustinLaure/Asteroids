#include "Game/MainMenu/MainMenu.h"

namespace mainMenu
{
	namespace titleScreen
	{
		enum class Options
		{
			Play,
			Rules,
			Credits,
			Exit
		};

		const text::Text title =
		{
			{360,100},
			"Asteroids",
			75.0f,
			2.0f,
			WHITE
		};

		const float buttonsHeight = 500;
		const float buttonsFontSize = 60;
		const float disBetOptions = 50.0f;

		const button::Button buttonsConst[maxButtons] =
		{
			//button1
			{
				//body
				{
					114.0f,					//width
					buttonsFontSize,		//height
					{175,buttonsHeight}		//pos
				},
			//text
			{
				{},							//pos
				"Play",						//text
				buttonsFontSize,			//fontSize
				2,							//spacing
				WHITE							//color
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

					146.0f,
					buttonsFontSize,
					{175 + 114 + disBetOptions,buttonsHeight}
				},
			//text
			{
				{},
				"Rules",
				buttonsFontSize,
				2,
				WHITE
			},
			//color
			WHITE,
			//isPressed
			false
			},

			//button3
			{
				//body
				{
					198,
					buttonsFontSize,
					{339 + 146 + disBetOptions,buttonsHeight}
				},
			//text
			{
				{},
				"Credits",
				buttonsFontSize,
				2,
				WHITE
			},
			//color
			WHITE,
			//isPressed
			false
			},

			//button4
			{
				//body
				{
					102.0f,
					buttonsFontSize,
					{535 + 198 + disBetOptions,buttonsHeight}
				},
			//text
			{
				{},
				"Exit",
				buttonsFontSize,
				2,
				WHITE
			},
			//color
			WHITE,
			//isPressed
			false
			},

		};


		static void update(gameScene::Scene& currentScene, SubScene& currentSubscene, button::Button titleScreenButtons[maxButtons], bool& ignoreMouse);
		static void draw(button::Button titleScreenButtons[maxButtons]);

		static void update(gameScene::Scene& currentScene, SubScene& currentSubscene, button::Button titleScreenButtons[maxButtons], bool& ignoreMouse)
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::update(titleScreenButtons[i]);
			}

			if (titleScreenButtons[static_cast<int>(Options::Play)].isPressed)
			{
				currentScene = gameScene::Scene::Play;
				currentSubscene = SubScene::titleScreen;
				ignoreMouse = true;
			}
			else if ((titleScreenButtons[static_cast<int>(Options::Rules)].isPressed))
			{
				currentSubscene = SubScene::Rules;
				ignoreMouse = true;
			}
			else if ((titleScreenButtons[static_cast<int>(Options::Credits)].isPressed))
			{
				currentSubscene = SubScene::Credits;
				ignoreMouse = true;
			}
			else if ((titleScreenButtons[static_cast<int>(Options::Exit)].isPressed))
			{
				currentSubscene = SubScene::titleScreen;
				currentScene = gameScene::Scene::Exit;
				ignoreMouse = true;
			}
		}

		static void draw(button::Button titleScreenButtons[maxButtons])
		{
			DrawTextEx(GetFontDefault(), title.text.c_str(), title.pos, title.fontSize, title.spacing, title.color);

			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(titleScreenButtons[i]);
			}
		}

		void initButtons(button::Button titleScreenButtons[maxButtons])
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

				button::init(titleScreenButtons[i], width, height, pos, text, fontSize, spacing, textColor, bckgColor);
			}
		}
	}

	namespace rules
	{
		enum class Options
		{
			Back
		};

		const int optionsFontSize = 45;
		const int optionsHeightPos = 650;

		const button::Button buttonsConst[maxButtons] =
		{
			//button1
			{
				//body
				{
					100.0f,						//width
					optionsFontSize,			//height
					{125,optionsHeightPos}		//pos
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
		};

		const int maxRulesLines = 5;
		const float rulesFontSize = 30.0f;
		const float rulesSpacing = 2.0f;
		const Color rulesColor = WHITE;
		const float rulesX = 150;

		const text::Text rulesText[maxRulesLines] =
		{
			{
				{rulesX, 100},
				"-Use right click to MOVE and left click to SHOOT",
				rulesFontSize,
				rulesSpacing,
				rulesColor
			},
			{
				{rulesX,250},
				"-Destroy as many asteroids as you can without getting hit",
				rulesFontSize,
				rulesSpacing,
				rulesColor
			},
			{
				{rulesX,400},
				"-You have 3 lives",
				rulesFontSize,
				rulesSpacing,
				rulesColor
			},
			{
				{rulesX, 550},
				"-Press P to pause",
				rulesFontSize,
				rulesSpacing,
				rulesColor
			},
			{
				{},
				"",
				rulesFontSize,
				rulesSpacing,
				rulesColor
			},
		};

		static void update(SubScene& currentSubscene, button::Button rulesButtons[], bool& ignoreMouse);
		static void draw(button::Button rulesButtons[]);

		static void update(SubScene& currentSubscene, button::Button rulesButtons[], bool& ignoreMouse)
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::update(rulesButtons[i]);
			}

			if (rulesButtons[static_cast<int>(Options::Back)].isPressed)
			{
				currentSubscene = SubScene::titleScreen;
				ignoreMouse = true;
			}
		}

		static void draw(button::Button rulesButtons[])
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(rulesButtons[i]);
			}

			for (int i = 0; i < maxRulesLines; i++)
			{
				DrawTextEx(GetFontDefault(), rulesText[i].text.c_str(), rulesText[i].pos, rulesText[i].fontSize, rulesText[i].spacing, rulesText[i].color);
			}
		}

		void initButtons(button::Button buttons[maxButtons])
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

				button::init(buttons[i], width, height, pos, text, fontSize, spacing, textColor, bckgColor);
			}
		}
	}

	namespace credits
	{
		enum class Options
		{
			Back
		};

		const int optionsFontSize = 45;
		const int optionsHeightPos = 650;

		const button::Button buttonsConst[maxButtons] =
		{
			//button1
			{
				//body
				{
					100.0f,							//width
					optionsFontSize,				//height
					{100,optionsHeightPos}			//pos
				},
			//text
			{
				{},									//pos
				"Back",								//text
				optionsFontSize,					//fontSize
				2,									//spacing
				WHITE									//color
			},
			//color
			WHITE,
			//isPressed
			false
			},
		};
		
		const int maxCreditsLines = 5;

		const float CreditsFontSize = 30.0f;
		const float CreditsSpacing = 2.0f;
		const Color CreditsColor = WHITE;
		const float CreditsX = 150;

		const text::Text creditsLines[maxCreditsLines] =
		{
			{
				{CreditsX, 100},
				"-Agustin Laure",
				CreditsFontSize,
				CreditsSpacing,
				CreditsColor
			},
			{
				{CreditsX,250},
				"-mianostudiogames - itchio - Asteroids Assets Pack",
				CreditsFontSize,
				CreditsSpacing,
				CreditsColor
			},
			{
				{CreditsX,400},
				"-kenney - Interface Sounds",
				CreditsFontSize,
				CreditsSpacing,
				CreditsColor
			},
			{
				{CreditsX, 550},
				"-Tallbeard studios -itchio- Three red hearts",
				CreditsFontSize,
				CreditsSpacing,
				CreditsColor
			},
			{
				{},
				"",
				CreditsFontSize,
				CreditsSpacing,
				CreditsColor
			},
		};

		static void update(SubScene& currentSubscene, button::Button creditsButtons[], bool& ignoreMouse);
		static void draw(button::Button creditsButtons[]);

		static void update(SubScene& currentSubscene, button::Button creditsButtons[], bool& ignoreMouse)
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::update(creditsButtons[i]);
			}

			if (creditsButtons[static_cast<int>(Options::Back)].isPressed)
			{
				currentSubscene = SubScene::titleScreen;
				ignoreMouse = true;
			}
		}

		static void draw(button::Button creditsButtons[])
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(creditsButtons[i]);
			}

			for (int i = 0; i < maxCreditsLines; i++)
			{
				DrawTextEx(GetFontDefault(), creditsLines[i].text.c_str(), creditsLines[i].pos, creditsLines[i].fontSize, creditsLines[i].spacing, creditsLines[i].color);
			}
		}

		void initButtons(button::Button buttons[maxButtons])
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

				button::init(buttons[i], width, height, pos, text, fontSize, spacing, textColor, bckgColor);
			}
		}
	}

	void update(gameScene::Scene& currentScene, SubScene& currentSubscene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], bool& ignoreMouse)
	{
		switch (currentSubscene)
		{
		case SubScene::titleScreen:
			titleScreen::update(currentScene, currentSubscene, titleScreenButtons, ignoreMouse);
			break;

		case SubScene::Rules:
			rules::update(currentSubscene, rulesButtons, ignoreMouse);
			break;
		case SubScene::Credits:
			credits::update(currentSubscene, creditsButtons, ignoreMouse);
			break;
		case SubScene::Exit:
			break;
		default:
			break;
		}
	}

	void draw(SubScene currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[])
	{
		BeginDrawing();
		ClearBackground(BLACK);

		switch (currentSubScene)
		{
		case SubScene::titleScreen:
			titleScreen::draw(titleScreenButtons);
			break;
		case SubScene::Rules:
			rules::draw(rulesButtons);
			break;
		case SubScene::Credits:
			credits::draw(creditsButtons);
			break;
		case SubScene::Exit:
			break;
		default:
			break;
		}

		EndDrawing();
	}
}