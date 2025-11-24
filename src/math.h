#pragma once
#include <SFML/System.hpp>

namespace math
{
	sf::Vector2f getResPointFromViewport(sf::Vector2f vpPoint);
	float getResValueFromViewport(float vpValue);

	sf::Vector2f getViewportPointFromRes(sf::Vector2u resPoint);
}
