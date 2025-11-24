#include "spider.h"

namespace spider
{
	const float pi = 3.14159265359;

	static void setPosFromAngle(Spider& spider);

	Spider init(float radius, sf::Vector2f pivotPosition, float maxStringLength)
	{
		Spider spider;

		spider.collider = sf::CircleShape(radius);

		spider.pivotPosition = pivotPosition;
		spider.angle = 0;

		spider.maxStringLength = maxStringLength ;
		spider.minStringLength = maxStringLength / 10;
		spider.stringLength = maxStringLength / 2;

		setPosFromAngle(spider);

		spider.velocity = { 0,0 };

		return spider;
	}

	void pushRight(Spider& spider, float delta)
	{
		spider.angle = fmin(spider.angle + spider.speed, pi / 2);
		setPosFromAngle(spider);
	}

	void pushLeft(Spider& spider, float delta)
	{
		spider.angle = fmax(spider.angle - spider.speed, -pi / 2);
		setPosFromAngle(spider);
	}

	void lengthenString(Spider& spider, float delta)
	{
		spider.stringLength = fmin(spider.stringLength + spider.stringSpeed, spider.maxStringLength);
		setPosFromAngle(spider);
	}

	void shortenString(Spider& spider, float delta)
	{
		spider.stringLength = fmax(spider.stringLength - spider.stringSpeed, spider.minStringLength);
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