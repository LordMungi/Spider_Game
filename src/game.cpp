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

		spider = spider::init(100, { 200, 200 });
	}

	Screen update()
	{
		float delta = clock.restart().asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			spider::move(spider, { -1, 0 }, delta);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			spider::move(spider, { 1, 0 }, delta);

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