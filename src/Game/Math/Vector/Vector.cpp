#include "Vector.h"

namespace vector
{
	Vector2 getVectorSum(Vector2 v1, Vector2 v2)
	{
		Vector2 result = {};

		result.x = v1.x + v2.x;
		result.y = v1.y + v2.y;

		return result;
	}

	Vector2 getVectorSub(Vector2 v1, Vector2 v2)
	{
		Vector2 result = {};

		result.x = v1.x - v2.x;
		result.y = v1.y - v2.y;

		return result;
	}

	Vector2 getVectorMult(Vector2 v, float mult)
	{
		Vector2 result = {};

		result.x = v.x * mult;
		result.y = v.y * mult;

		return result;
	}

}
