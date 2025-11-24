#include "game.h"

#include "spider.h"
#include "global.h"

namespace game
{
	sf::Clock clock;

	spider::Spider spider;

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
			spider::lengthenString(spider, delta);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			spider::shortenString(spider, delta);

		return Screen::GAME;
	}

	void draw()
	{
		spider::draw(spider);
	}

	void end()
	{

	}
}