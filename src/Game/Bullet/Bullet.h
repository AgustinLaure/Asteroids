#pragma once

#include "Game/Math/Form/Form.h"

namespace bullet
{
	const float bulletInitialDmg = 1.0f;

	struct Bullet
	{
		form::Circle body;
		float dmg = 0.0f;
		
	};
}
