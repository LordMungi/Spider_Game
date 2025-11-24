#include "render.h"


namespace render
{
	sf::RenderWindow window;
	
	void startWindow(sf::Vector2u resolution, std::string title)
	{
		window = sf::RenderWindow(sf::VideoMode(resolution), title);
	}

	void updateWindow()
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				closeWindow();
		}

	}

	void closeWindow()
	{
		window.close();
	}

	bool isWindowOpen()
	{
		return window.isOpen();
	}

	void clear()
	{
		window.clear();
	}
	void draw()
	{
		window.display();
	}

	void circle(float radius, sf::Color color)
	{
		sf::CircleShape shape(radius);
		shape.setFillColor(color);
		window.draw(shape);
	}

	void circle(sf::CircleShape circle, sf::Color color)
	{
		circle.setFillColor(color);
		window.draw(circle);
	}

}