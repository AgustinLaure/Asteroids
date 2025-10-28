#pragma once

#include <string>

#include "Game/Math/Vector/Vector.h"
#include "Game/Button/Button.h"
#include "Game/Text/Text.h"
#include "Game/GameScene.h"

namespace mainMenu
{
	enum class SubScene
	{
		titleScreen,
		Rules,
		Credits,
		Exit
	};

	void update(gameScene::Scene& currentScene, SubScene& currentSubscene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], bool& ignoreMouse);
	void draw(SubScene currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[]);

	namespace titleScreen
	{
		const int maxButtons = 4;

		void initButtons(button::Button titleScreenButtons[maxButtons]);
	}

	namespace rules
	{
		const int maxButtons = 1;

		void initButtons(button::Button buttons[maxButtons]);
	}

	namespace credits
	{
		const int maxButtons = 1;

		void initButtons(button::Button buttons[maxButtons]);
	}
}

