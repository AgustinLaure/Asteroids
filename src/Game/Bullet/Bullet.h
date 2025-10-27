#pragma once

#include "Game/Math/Form/Form.h"

namespace bullet
{
	const float bulletInitialDmg = 1.0f;
	const float bulletInitialSpeed = 1000.0f;
	const float bulletInitialRadius = 5.0;

	struct Bullet
	{
		Vector2 pos;
		form::Circle body;
		float dmg = 0.0f;
		float speed = 0.0f;
		Vector2 dir = { 1,0 };
		bool isOn = false;
		Color color = WHITE;
	};

	void initBullets(Bullet bullets[], int bulletAmount);
	void update(Bullet bullets[], int bulletAmount, float delta);
	void draw(Bullet bullets[], int bulletAmount);
	void shoot(Bullet& bullet, Vector2 pos, Vector2 dir);
	void outBounds(Bullet& bullet);
	void resetBullet(Bullet& bullet);
}
