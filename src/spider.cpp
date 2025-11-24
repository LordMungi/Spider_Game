#include "spider.h"

namespace spider
{
	static void setPosFromAngle(Spider& spider);

	Spider init(float radius, sf::Vector2f pivotPosition, float stringLength)
	{
		Spider spider;

		spider.collider = sf::CircleShape(radius);

		spider.pivotPosition = pivotPosition;
		spider.angle = 0;
		spider.stringLength = stringLength;

		setPosFromAngle(spider);

		spider.velocity = { 0,0 };

		return spider;
	}

	void pushRight(Spider& spider, float delta)
	{
		spider.angle += spider.speed;
		setPosFromAngle(spider);
	}

	void pushLeft(Spider& spider, float delta)
	{
		spider.angle -= spider.speed;
		setPosFromAngle(spider);
	}

	void draw(Spider& spider)
	{
		render::circle(spider.pivotPosition, 2, sf::Color::Red);
		render::circle(spider.collider, sf::Color::Green);
	}

	static void setPosFromAngle(Spider& spider)
	{
		sf::Vector2f position;
		position.x = sinf(spider.angle) * spider.stringLength + spider.pivotPosition.x;
		position.y = cosf(spider.angle) * spider.stringLength + spider.pivotPosition.y;

		spider.collider.setPosition(position);
	}
}