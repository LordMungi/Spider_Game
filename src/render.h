#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace render
{
	enum class TextAlgin
	{
		LEFT,
		RIGHT,
		CENTER
	};

	void startWindow(sf::Vector2u resolution, std::string title);
	void updateWindow();
	void closeWindow();
	bool isWindowOpen();

	void clear();
	void draw();
	
	void line(sf::Vector2f start, sf::Vector2f end, float width, sf::Color color);

	void circle(sf::Vector2f position, float radius, sf::Color color);
	void circle(sf::CircleShape circle, sf::Color color);

	void rectangle(sf::RectangleShape rectangle, sf::Color color);

	void text(std::string text, sf::Font font, sf::Vector2f position, float size);
	void text(std::string text, sf::Font font, sf::Vector2f position, float size, TextAlgin align);
	void text(std::string text, sf::Font font, sf::Vector2f position, float size, TextAlgin align, sf::Color color);
}