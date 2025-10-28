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

	void update(gameScene::Scene& currentScene, SubScene& currentSubscene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[]);
	void draw(SubScene currentSubScene, button::Button titleScreenButtons[], button::Button rulesButtons[], button::Button creditsButtons[], Font gameFont);

	namespace titleScreen
	{
		const int maxButtons = 4;

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
				RED							//color
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
					{175 +114+ disBetOptions,buttonsHeight}
				},
			//text
			{
				{},			
				"Rules",	
				buttonsFontSize,
				2,			
				RED			
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
					{339+146+ disBetOptions,buttonsHeight}
				},
			//text
			{
				{},				
				"Credits",		
				buttonsFontSize,
				2,				
				RED				
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
					{535+198+ disBetOptions,buttonsHeight}
				},
			//text
			{
				{},			
				"Exit",		
				buttonsFontSize,
				2,			
				RED		
			},	
			//color
			WHITE,
			//isPressed
			false
			},

		};

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

