#include "program.h"

#include <SFML/Graphics.hpp>

namespace program
{
	static void init();
	static void update();
	static void draw();
	static void close();

	sf::RenderWindow window;

	bool isRunning = true;

	void run()
	{
		init();

		while (isRunning)
		{
			update();
			draw();
		}

		close();
	}

	static void init()
	{
		window = sf::RenderWindow(sf::VideoMode({ 1024, 768 }), "Spider game");
	}

	static void update()
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				isRunning = false;
		}

	}

	static void draw()
	{
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		window.clear();
	 	window.draw(shape);
		window.display();
	}

	static void close()
	{
		window.close();
	}
}