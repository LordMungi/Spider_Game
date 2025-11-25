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
		float stringSpeed = 100.0f;

		float velocity;
		float acceleration;

		float speed = 3.0f;
	};

	Spider init(float radius, sf::Vector2f pivotPosition, float maxStringLength);

	void updatePosition(Spider& spider, float delta);

	void pushRight(Spider& spider, float delta);
	void pushLeft(Spider& spider, float delta);
	void lengthenString(Spider& spider, float delta);
	void shortenString(Spider& spider, float delta);

	void draw(Spider& spider);

}