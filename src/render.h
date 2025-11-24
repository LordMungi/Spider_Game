#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace render
{
	void startWindow(sf::Vector2u resolution, std::string title);
	void updateWindow();
	void closeWindow();
	bool isWindowOpen();

	void clear();
	void draw();

	void circle(float radius, sf::Color color);
	void circle(sf::CircleShape circle, sf::Color color);
}