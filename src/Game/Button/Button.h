#pragma once

#include <string>

#include "raylib.h"

#include "Game/Math/Form/Form.h"
#include "Game/Math/Vector/Vector.h"
#include "Game/Text/Text.h"

namespace button
{
	const MouseButton actionButton = MOUSE_LEFT_BUTTON;

	struct Button
	{
		static Sound onSelect;
		form::Rectangle body;
		text::Text text;
		Color color = WHITE;
		bool isPressed = false;
	};

	void init(Button& button, float width, float height, Vector2 pos, std::string text, float fontSize, float spacing, Color textColor, Color bckgColor);
	void update(Button& button);
	void draw(Button button);
}

