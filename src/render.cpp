#include "render.h"
#include "global.h"
#include "math.h"

namespace render
{
	sf::RenderWindow window;

	static void setViewportFromResolution();

	void startWindow(sf::Vector2u resolution, std::string title)
	{
		window = sf::RenderWindow(sf::VideoMode(resolution), title);
		setViewportFromResolution();
	}

	static void setViewportFromResolution()
	{
		global::viewport.y = 100;
		global::viewport.x = global::resolution.x * global::viewport.y / global::resolution.y;
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

	void circle(sf::Vector2f position, float radius, sf::Color color)
	{
		sf::CircleShape shape;

		shape.setRadius(math::getResValueFromViewport(radius));

		sf::Vector2f resPosition = math::getResPointFromViewport(position);
		resPosition.x -= shape.getRadius();
		resPosition.y -= shape.getRadius();
		shape.setPosition(resPosition);

		shape.setFillColor(color);
		window.draw(shape);
	}

	void circle(sf::CircleShape circle, sf::Color color)
	{
		sf::CircleShape shape;
				
		shape.setRadius(math::getResValueFromViewport(circle.getRadius()));

		sf::Vector2f position = math::getResPointFromViewport(circle.getPosition());
		position.x -= shape.getRadius();
		position.y -= shape.getRadius();
		shape.setPosition(position);

		shape.setFillColor(color);
		window.draw(shape);
	}

}