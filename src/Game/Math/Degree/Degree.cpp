#include "Game/Math/Degree/Degree.h"

#include <math.h>

#include "Game/Math/Vector/Vector.h"


namespace degree
{
	float getDegree(Vector2 pos1, Vector2 pos2)
	{
		float degree = 0.0f;

		Vector2 dist = vector::getVectorSub(pos2, pos1);

		float op = static_cast<float>(fabs(pos2.x - pos1.x));
		float ad = static_cast<float>(fabs(pos2.y - pos1.y));

		degree = atanf(ad/op);
		
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
			if (pos2.y >pos1.y)
			{
				degree = 180 + degree;
			}
			else
			{
				degree = 180 - degree;
			}
		}

		degree *= -1;

		return degree;
	}
}