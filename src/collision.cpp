#include "collision.h"
#include "render.h"

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

	bool pointCircle(sf::Vector2f point, sf::CircleShape circle)
	{
		sf::Vector2f distance = point - circle.getPosition();
		float distVector = distance.x * distance.x + distance.y * distance.y;

		return distVector <= circle.getRadius() * circle.getRadius();
	}

	bool pointLine(sf::Vector2f point, sf::Vector2f lineStart, sf::Vector2f lineEnd)
	{
		sf::Vector2f distanceStart = lineStart - point;
		float lengthStart = sqrtf(distanceStart.x * distanceStart.x + distanceStart.y * distanceStart.y);

		sf::Vector2f distanceEnd = lineEnd - point;
		float lengthEnd = sqrtf(distanceEnd.x * distanceEnd.x + distanceEnd.y * distanceEnd.y);

		sf::Vector2f distance = lineStart - lineEnd;
		float length = sqrtf(distance.x * distance.x + distance.y * distance.y);


		float buffer = 0.01f;

		return lengthStart + lengthEnd >= length - buffer && lengthStart + lengthEnd <= length + buffer;
	}


	bool circleLine(sf::CircleShape circle, sf::Vector2f lineStart, sf::Vector2f lineEnd)
	{
		if (pointCircle(lineStart, circle) || pointCircle(lineEnd, circle))
			return true;

		sf::Vector2f center = circle.getPosition();
		float radius = circle.getRadius();

		sf::Vector2f distance = lineEnd - lineStart;
		float lengthSq = distance.x * distance.x + distance.y * distance.y;

		sf::Vector2f lineStartCircle = center - lineStart;

		float dot = (lineStartCircle.x * distance.x + lineStartCircle.y * distance.y) / lengthSq;

		sf::Vector2f closest = lineStart + (dot * (lineEnd - lineStart));

		if (!pointLine(closest, lineStart, lineEnd))
			return false;

		sf::Vector2f distCircle = closest - center;
		float distVector = distCircle.x * distCircle.x + distCircle.y * distCircle.y;

		return distVector <= radius * radius;
	}
}

