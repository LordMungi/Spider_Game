#include "collision.h"

namespace collision
{
	bool circleCircle(sf::CircleShape circle1, sf::CircleShape circle2)
	{
		sf::Vector2f distance;
		distance.x = circle1.getPosition().x - circle2.getPosition().x;
		distance.y = circle1.getPosition().y - circle2.getPosition().y;

		float distVector = (distance.x * distance.x + distance.y * distance.y);

		return distVector <= (circle1.getRadius() + circle2.getRadius()) * (circle1.getRadius() + circle2.getRadius());
	}
}