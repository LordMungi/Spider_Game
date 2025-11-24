#pragma once
#include "render.h"

namespace spider
{
	struct Spider
	{
		sf::CircleShape collider;

		sf::Vector2f position;
		sf::Vector2f velocity;

		float speed = 200;
	};

	Spider init(float radius, sf::Vector2f position);

	void move(Spider& spider, sf::Vector2f direction, float delta);
	void draw(Spider& spider);

}