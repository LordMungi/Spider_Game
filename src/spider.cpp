#include "spider.h"

namespace spider
{
	Spider init(float radius, sf::Vector2f position)
	{
		Spider spider;

		spider.collider = sf::CircleShape(radius);
		spider.collider.setPosition(position);
		spider.position = position;
		spider.velocity = { 0,0 };

		return spider;
	}

	void move(Spider& spider, sf::Vector2f direction, float delta)
	{
		spider.position += direction * spider.speed * delta;
		spider.collider.setPosition(spider.position);
	}

	void draw(Spider& spider)
	{
		render::circle(spider.collider, sf::Color::Green);
	}
}