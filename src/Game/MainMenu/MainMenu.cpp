#include "Game/MainMenu/MainMenu.h"

namespace mainMenu
{
	namespace titleScreen
	{
		static void update()
		{

		}

		static void draw(button::Button buttons[maxButtons], Font gameFont)
		{
			DrawTextEx(gameFont, title.text.c_str(), title.pos, title.fontSize, title.spacing, title.color);

			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(buttons[i], gameFont);
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

	namespace rules
	{
		static void update()
		{

		}

		static void draw(button::Button rulesButtons[], Font gameFont)
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(rulesButtons[i], gameFont);
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
		static void update()
		{

		}

		static void draw(button::Button creditsButtons[], Font gameFont)
		{
			for (int i = 0; i < maxButtons; i++)
			{
				button::draw(creditsButtons[i], gameFont);
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

	void update(SubScene& currentSubscene)
	{
		switch (currentSubscene)
		{
		case SubScene::titleScreen:
			titleScreen::update();
			break;

		case SubScene::Rules:
			rules::update();
			break;
		case SubScene::Credits:
			credits::update();
			break;
		case SubScene::Exit:
			break;
		default:
			break;
		}
	}

	void draw(SubScene currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[],  Font gameFont)
	{
		switch (currentSubScene)
		{
		case SubScene::titleScreen:
			titleScreen::draw(titleScreenButtons, gameFont);
			break;
		case SubScene::Rules:
			rules::draw(rulesButtons, gameFont);
			break;
		case SubScene::Credits:
			credits::draw(creditsButtons, gameFont);
			break;
		case SubScene::Exit:
			break;
		default:
			break;
		}
	}
}