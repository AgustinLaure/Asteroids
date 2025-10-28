#include "Game/Button/Button.h"

#include "raylib.h"

namespace button
{
	void init(Button& button,float width, float height, Vector2 pos, std::string text, float fontSize, float spacing, Color textColor, Color bckgColor)
	{
		button.body.width = width;
		button.body.height = height;
		button.body.pos = pos;
		button.text.pos = button.body.pos;
		button.text.text = text;
		button.text.fontSize = fontSize;
		button.text.spacing = spacing;
		button.text.color = textColor;
		button.color = bckgColor;
		button.isPressed = false;
	}

	void update(Button& button)
	{
		if (IsMouseButtonDown(actionButton))
		{
			if (form::isPointCollidingRect(GetMousePosition(), button.body))
			{
				button.isPressed = true;
			}
		}
	}

	void draw(Button button, Font gameFont)
	{
		DrawRectangle(static_cast<int>(button.body.pos.x), static_cast<int>(button.body.pos.y), static_cast<int>(button.body.width), static_cast<int>(button.body.height), button.color);
		DrawTextEx(gameFont, button.text.text.c_str(), button.text.pos, button.text.fontSize, button.text.spacing, button.text.color);
	}
}