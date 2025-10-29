#include "Game/Button/Button.h"

namespace button
{
	const MouseButton actionButton = MOUSE_LEFT_BUTTON;

	Sound Button::onSelect;

	void init(Button& button,float width, float height, Vector2 pos, std::string text, float fontSize, float spacing, Color textColor, Color bckgColor)
	{
		Button::onSelect = LoadSound("res/sound/sfx/ui/selectSound.ogg");
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
		button.isPressed = false;

		if (IsMouseButtonDown(actionButton))
		{
			if (form::isPointCollidingRect(GetMousePosition(), button.body))
			{
				button.isPressed = true;
				PlaySound(Button::onSelect);
			}
		}
	}

	void draw(Button button)
	{
		DrawTextEx(GetFontDefault(), button.text.text.c_str(), button.text.pos, button.text.fontSize, button.text.spacing, button.text.color);
	}
}