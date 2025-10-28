#pragma once

#include <string>

#include "Game/Math/Vector/Vector.h"
#include "Game/Button/Button.h"
#include "Game/Text/Text.h"

namespace mainMenu
{
	enum class SubScene
	{
		titleScreen,
		Rules,
		Credits,
		Exit

	};

	void update(SubScene& currentSubscene);
	void draw(SubScene currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], Font gameFont);

	namespace titleScreen
	{
		const int maxButtons = 4;

		const text::Text title =
		{
			{0,0},
			"Asteroids",
			15.0f,
			2.0f,
			WHITE
		};

		const button::Button buttonsConst[maxButtons] =
		{
			//button1
			{
				//body
				{
					15.0f,	//width
					8.0f,	//height
					{0,0}	//pos
				},
			//text
			{
				{},		//pos
				"Play",	//text
				10,		//fontSize
				2,		//spacing
				WHITE	//color
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
					15.0f,	//width
					8.0f,	//height
					{0,0}	//pos
				},
			//text
			{
				{},			//pos
				"Rules",	//text
				10,			//fontSize
				2,			//spacing
				WHITE		//color
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
					15.0f,	//width
					8.0f,	//height
					{0,0}	//pos
				},
			//text
			{
				{},			//pos
				"Credits",	//text
				10,			//fontSize
				2,			//spacing
				WHITE		//color
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
					15.0f,	//width
					8.0f,	//height
					{0,0}	//pos
				},
			//text
			{
				{},			//pos
				"Exit",		//text
				10,			//fontSize
				2,			//spacing
				WHITE		//color
			},	
			//color
			WHITE,
			//isPressed
			false
			},

		};

		void initButtons(button::Button buttons[maxButtons]);
	}

	namespace rules
	{
		const int maxButtons = 1;

		const button::Button buttonsConst[maxButtons] =
		{
			//button1
			{
				//body
				{
					15.0f,	//width
					8.0f,	//height
					{0,0}	//pos
				},
			//text
			{
				{},		//pos
				"Back",	//text
				10,		//fontSize
				2,		//spacing
				WHITE	//color
			},
			//color
			WHITE,
			//isPressed
			false
			},
		};

		void initButtons(button::Button buttons[maxButtons]);
	}

	namespace credits
	{
		const int maxButtons = 1;

		const button::Button buttonsConst[maxButtons] =
		{
			//button1
			{
				//body
				{
					15.0f,	//width
					8.0f,	//height
					{0,0}	//pos
				},
			//text
			{
				{},		//pos
				"Back",	//text
				10,		//fontSize
				2,		//spacing
				WHITE	//color
			},
			//color
			WHITE,
			//isPressed
			false
			},
		};

		void initButtons(button::Button buttons[maxButtons]);
	}
}

