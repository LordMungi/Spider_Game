#pragma once
#include "render.h"

namespace spider
{
	struct Spider
	{
		sf::CircleShape collider;

		sf::Vector2f pivotPosition;
		float stringLength;
		float angle;

		sf::Vector2f velocity;

		float speed = 0.0015;
	};

	Spider init(float radius, sf::Vector2f pivotPosition, float stringLength);

	void pushRight(Spider& spider, float delta);
	void pushLeft(Spider& spider, float delta);

	void draw(Spider& spider);

}