#include "Game/Math/Vector/Vector.h"

#include <math.h>

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

	float getMagnitude(Vector2 v)
	{
		float magnitude = static_cast<float>(sqrt(v.x * v.x + v.y * v.y));

		return magnitude;
	}

	Vector2 getNormalized(Vector2 v)
	{
		Vector2 normalized = v;
			
		float vMagnitude = getMagnitude(v);

		if (vMagnitude > 0)
		{
			normalized.x /= vMagnitude;
			normalized.y /= vMagnitude;
		}
		else
		{
			normalized.x = 0;
			normalized.y = 0;
		}

		return normalized;
	}

	float getDegree(Vector2 pos1, Vector2 pos2)
	{
		float degree = 0.0f;

		Vector2 dist = vector::getVectorSub(pos2, pos1);

		float op = static_cast<float>(fabs(pos2.x - pos1.x));
		float ad = static_cast<float>(fabs(pos2.y - pos1.y));

		degree = atanf(ad / op);

		degree *= RAD2DEG;

		if (pos2.x > pos1.x)
		{
			if (pos2.y > pos1.y)
			{
				degree = 360 - degree;
			}
		}
		else if (pos2.x < pos1.x)
		{
			if (pos2.y > pos1.y)
			{
				degree = 180 + degree;
			}
			else
			{
				degree = 180 - degree;
			}
		}

		degree *= -1;
		degree -= 90;

		return degree;
	}

	Vector2 getDir(float degree)
	{
		degree *= DEG2RAD;

		Vector2 dir = {cosf(degree), sinf(degree)};

		return dir;
	}
}
