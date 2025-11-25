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

	void line(sf::Vector2f start, sf::Vector2f end, float width, sf::Color color)
	{
		sf::RectangleShape shape;


		shape.setOrigin({ math::getResValueFromViewport(width) / 2, 0 });

		sf::Vector2f d = math::getResPointFromViewport(start - end);
		shape.setSize({math::getResValueFromViewport(width), sqrt(d.x * d.x + d.y * d.y)});

		shape.setRotation(sf::radians(atan2(d.y, d.x) + 3.14f / 2.0f));
		shape.setPosition(math::getResPointFromViewport(start));
		shape.setFillColor(color);

		window.draw(shape);
	}

	void circle(sf::Vector2f position, float radius, sf::Color color)
	{
		sf::CircleShape shape;

		shape.setRadius(math::getResValueFromViewport(radius));
		shape.setPosition(math::getResPointFromViewport(position));
		shape.setOrigin({ math::getResValueFromViewport(radius), math::getResValueFromViewport(radius) });

		shape.setFillColor(color);
		window.draw(shape);
	}

	void circle(sf::CircleShape circle, sf::Color color)
	{
		sf::CircleShape shape;
				
		shape.setRadius(math::getResValueFromViewport(circle.getRadius()));
		shape.setPosition(math::getResPointFromViewport(circle.getPosition()));
		shape.setOrigin({ math::getResValueFromViewport(circle.getRadius()), math::getResValueFromViewport(circle.getRadius()) });

		shape.setFillColor(color);
		window.draw(shape);
	}

	void text(std::string text, sf::Font font, sf::Vector2f position, float size)
	{
		sf::Text label(font);

		label.setString(text);
		label.setPosition(math::getResPointFromViewport(position));
		label.setCharacterSize(static_cast<unsigned int>(math::getResValueFromViewport(size)));
		label.setFillColor(sf::Color::White);

		window.draw(label);
	}

}