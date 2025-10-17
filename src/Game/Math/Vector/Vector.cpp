#include "Vector.h"

namespace vector
{
	Vector2f getVectorSum(Vector2f v1, Vector2f v2)
	{
		Vector2f result = {};

		result.x = v1.x + v2.x;
		result.y = v1.y + v2.y;

		return result;
	}

	Vector2f getVectorSub(Vector2f v1, Vector2f v2)
	{
		Vector2f result = {};

		result.x = v1.x - v2.x;
		result.y = v1.y - v2.y;

		return result;
	}
}
