#pragma once

#include "Game/Math/Form/Form.h"

namespace bullet
{
	const float bulletInitialDmg = 1.0f;
	const float bulletInitialSpeed = 0.5f;
	const float bulletInitialRadius = 5.0;
	const int maxBullets = 100;

	struct Bullet
	{
		form::Circle body;
		float dmg = 0.0f;
		float speed = 0.0f;
		Vector2 dir = { 1,0 };
		bool isOn = false;
	};

	void initBullets(Bullet bullets[]);
	void update(Bullet bullets[]);
	
}
