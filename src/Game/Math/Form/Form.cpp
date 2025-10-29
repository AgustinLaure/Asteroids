#include "Game/Math/Form/Form.h"

#include <math.h>

namespace form
{
	bool isCircleCollidingCircle(Circle c1, Circle c2)
	{
		float dx = static_cast<float>(fabs(c1.pos.x - c2.pos.x));
		float dy = static_cast<float>(fabs(c1.pos.y - c2.pos.y));

		return ((dx <= c1.radius && dy <= c1.radius)
			|| dx <= c2.radius && dy <= c2.radius);
	}

	bool isPointCollidingRect(Vector2 p, Rectangle rect)
	{
		return p.x <= rect.pos.x + rect.width && p.x >= rect.pos.x &&
				p.y <= rect.pos.y + rect.height && p.y >= rect.pos.y;
	}
}