#pragma once
#include "render.h"

namespace spider
{
	struct Spider
	{
		sf::CircleShape collider;

		sf::Vector2f pivotPosition;
		float angle;
		
		float stringLength;
		float maxStringLength;
		float minStringLength;
		float stringSpeed = 0.05;

		sf::Vector2f velocity;

		float speed = 0.0015;
	};

	Spider init(float radius, sf::Vector2f pivotPosition, float maxStringLength);

	void pushRight(Spider& spider, float delta);
	void pushLeft(Spider& spider, float delta);
	void lengthenString(Spider& spider, float delta);
	void shortenString(Spider& spider, float delta);

	void draw(Spider& spider);

}