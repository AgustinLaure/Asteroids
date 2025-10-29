#pragma once

#include "Game/Asteroid/Asteroid.h"

namespace bullet
{
	const int bulletInitialDmg = 1;
	const float bulletInitialSpeed = 1000.0f;
	const float bulletInitialRadius = 5.0;
	const int pointsPerHit = 10;

	struct Bullet
	{
		static Texture2D sprite;
		static Sound onLandHit;
		Vector2 pos = {};
		form::Circle hitBox;
		int dmg = 0;
		float speed = 0.0f;
		Vector2 dir = { 1,0 };
		bool isOn = false;
		Color color = WHITE;
	};

	void initBullets(Bullet bullets[], int bulletAmount);
	void update(Bullet bullets[], int bulletAmount, asteroid::Asteroid asteroids[], int& shipPoints, float delta);
	void draw(Bullet bullets[], int bulletAmount);
	void shoot(Bullet& bullet, Vector2 pos, Vector2 dir);
}
