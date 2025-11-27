#pragma once
#include <SFML/Graphics.hpp>

namespace collision
{
	bool circleCircle(sf::CircleShape circle1, sf::CircleShape circle2);
	bool pointCircle(sf::Vector2f point, sf::CircleShape circle);
	bool pointLine(sf::Vector2f point, sf::Vector2f lineStart, sf::Vector2f lineEnd);
	bool circleLine(sf::CircleShape circle, sf::Vector2f lineStart, sf::Vector2f lineEnd);

	bool pointRectangle(sf::Vector2f point, sf::RectangleShape rectangle);
}