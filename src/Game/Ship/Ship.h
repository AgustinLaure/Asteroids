#pragma once

#include "Game/Bullet/Bullet.h"

namespace ship
{
	const int maxBullets = 5;

	struct Ship
	{
		Vector2 pos = {};
		Vector2 lookDir = {};
		Vector2 velocity = {};
		float rotation = 0.0f;
		form::Circle hitBox;
		Color color = WHITE;
		bullet::Bullet bullets[maxBullets];
		float shootCooldown = 0.0f;
		float takeDamageCooldown = 0.0f;
		int hp = 0;
		bool isAlive = true;
		int points = 0;
		Sound onDie;
		Sound onTakeDamage;
		Sound onShoot;
		Texture2D sprite;
	};

	void init(Ship& ship);
	void update(Ship& ship, asteroid::Asteroid asteroids[], float& delta);
	void draw(Ship ship);
}

