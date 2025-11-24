#include "math.h"

#include "global.h"

namespace math
{
	sf::Vector2f getResPointFromViewport(sf::Vector2f vpPoint)
	{
		sf::Vector2f resPoint;
		resPoint.x = vpPoint.x * global::resolution.x / global::viewport.x;
		resPoint.y = vpPoint.y * global::resolution.y / global::viewport.y;
		return resPoint;
	}
	float getResValueFromViewport(float vpValue)
	{
		return vpValue * global::resolution.y / global::viewport.y;
	}

	sf::Vector2f getViewportPointFromRes(sf::Vector2u resPoint)
	{
		sf::Vector2f vpPoint;
		vpPoint.x = resPoint.x * global::viewport.x / global::resolution.x;
		vpPoint.y = resPoint.y * global::viewport.y / global::resolution.y;
		return vpPoint;
	}
}
