#include "spider.h"

namespace spider
{
	const float pi = 3.14159265359f;
	const float gravity = 1000;

	static void setPosFromAngle(Spider& spider);

	Spider init(float radius, sf::Vector2f pivotPosition, float maxStringLength)
	{
		Spider spider;

		spider.collider = sf::CircleShape(radius);

		spider.pivotPosition = pivotPosition;
		spider.angle = pi / 4;

		spider.maxStringLength = maxStringLength ;
		spider.minStringLength = maxStringLength / 5;
		spider.stringLength = maxStringLength / 2;

		setPosFromAngle(spider);

		spider.velocity = 0;
		spider.acceleration = 0;

		return spider;
	}

	void updatePosition(Spider& spider, float delta)
	{
		spider.velocity += (-(gravity * sin(spider.angle)) / spider.stringLength) * delta;

		spider.angle += spider.velocity * delta;

		spider.velocity -= spider.velocity * 0.5f * delta;
		if (spider.angle > pi / 2)
		{
			spider.angle = pi / 2;
			spider.velocity = 0;
		}
		if (spider.angle < -pi / 2)
		{
			spider.angle = -pi / 2;
			spider.velocity = 0;
		}

		setPosFromAngle(spider);
	}

	void pushRight(Spider& spider, float delta)
	{
		spider.velocity += spider.strength / spider.stringLength  * delta;
	}

	void pushLeft(Spider& spider, float delta)
	{
		spider.velocity -= spider.strength / spider.stringLength * delta;
	}

	void lengthenString(Spider& spider, float delta)
	{
		spider.stringLength = fmin(spider.stringLength + spider.stringSpeed * delta, spider.maxStringLength);
		setPosFromAngle(spider);
	}

	void shortenString(Spider& spider, float delta)
	{
		spider.stringLength = fmax(spider.stringLength - spider.stringSpeed * delta, spider.minStringLength);
		setPosFromAngle(spider);
	}

	void draw(Spider& spider)
	{
		render::line(spider.pivotPosition, spider.collider.getPosition(), 1, sf::Color::White);
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