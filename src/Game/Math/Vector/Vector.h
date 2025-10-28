#pragma once

#include "raylib.h"

namespace vector
{
	Vector2 getVectorSum(Vector2 v1, Vector2 v2);
	Vector2 getVectorSub(Vector2 v1, Vector2 v2);
	Vector2 getVectorMult(Vector2 v, float mult);
	float getMagnitude(Vector2 v);
	Vector2 getNormalized(Vector2 v);
	float getDegree(Vector2 pos1, Vector2 pos2);
	Vector2 getDir(float degree);
}

