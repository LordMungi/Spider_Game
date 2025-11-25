#include "game.h"

#include "spider.h"
#include "global.h"

namespace game
{
	sf::Clock clock;

	spider::Spider spider;

	sf::Font font1("resource/fonts/CourierPrime-Regular.ttf");

	void start()
	{
		clock.start();

		spider = spider::init(5, { global::viewport.x / 2, 0}, 70);
	}

	Screen update()
	{
		float delta = clock.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			spider::pushLeft(spider, delta);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			spider::pushRight(spider, delta);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			spider::shortenString(spider, delta);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			spider::lengthenString(spider, delta);

		return Screen::GAME;
	}

	void draw()
	{

		render::text("W/Up", font1, { 3, 2 }, 3);
		render::text("S/Down", font1, { 3, 6 }, 3);
		render::text("A/Left", font1, { 3, 10 }, 3);
		render::text("D/Right", font1, { 3, 14 }, 3);

		render::text("Shorten string", font1, { 20, 2 }, 3);
		render::text("Lengthen string", font1, { 20, 6 }, 3);
		render::text("Move left", font1, { 20, 10 }, 3);
		render::text("Move right", font1, { 20, 14 }, 3);

		spider::draw(spider);

		render::text("ver 0.1", font1, { 3, 95 }, 3);
	}

	void end()
	{

	}
}