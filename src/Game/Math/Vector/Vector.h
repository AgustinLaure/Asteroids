#pragma once

namespace vector
{
	struct Vector2f
	{
		float x = 0;
		float y = 0;
	};

	Vector2f getVectorSum(Vector2f v1, Vector2f v2);
	Vector2f getVectorSub(Vector2f v1, Vector2f v2);
}

