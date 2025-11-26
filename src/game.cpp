#include "game.h"

#include "spider.h"
#include "enemy.h"

#include "global.h"
#include "collision.h"

namespace game
{
	sf::Clock deltaClock;
	sf::Clock enemyClock;

	const int maxEnemies = 50;

	spider::Spider spider;
	enemy::Enemy* enemies[maxEnemies];

	int enemySpawnCooldown = 1;

	sf::Font font1("resource/fonts/CourierPrime-Regular.ttf");

	void start()
	{
		srand(static_cast<unsigned int>(time(0)));

		deltaClock.start();
		enemyClock.start();

		spider = spider::init(5, { global::viewport.x / 2, 0}, 70);
	}

	Screen update()
	{
		float delta = deltaClock.restart().asSeconds();

		if (enemyClock.getElapsedTime().asSeconds() > enemySpawnCooldown)
		{
			for (int i = 0; i < maxEnemies; i++)
			{
				if (enemies[i] == nullptr)
				{
					enemies[i] = new enemy::Enemy(enemy::init(global::viewport, 2));
					enemyClock.restart();
					break;
				}
			}
		}

		for (int i = 0; i < maxEnemies; i++)
		{
			if (enemies[i] != nullptr)
			{
				enemy::move(*enemies[i], delta);

				if (enemies[i]->collider.getPosition().x - enemies[i]->collider.getRadius() > global::viewport.x ||
					enemies[i]->collider.getPosition().x + enemies[i]->collider.getRadius() < 0)
				{
					enemy::bounceHorizontal(*enemies[i]);
				}
				if	(enemies[i]->collider.getPosition().y - enemies[i]->collider.getRadius() > global::viewport.y ||
					enemies[i]->collider.getPosition().y + enemies[i]->collider.getRadius() < 0)
				{
					enemy::bounceVertical(*enemies[i]);
				}

				if (collision::circleCircle(enemies[i]->collider, spider.collider))
				{
					delete enemies[i];
					enemies[i] = nullptr;
				}
			}
		}

		spider::updatePosition(spider, delta);

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
		render::text("Push left", font1, { 20, 10 }, 3);
		render::text("Push right", font1, { 20, 14 }, 3);

		spider::draw(spider);


		for (int i = 0; i < maxEnemies; i++)
		{
			if (enemies[i] != nullptr)
			{
				enemy::draw(*enemies[i]);
			}
		}

		render::text("ver 0.2", font1, { 3, 95 }, 3);
	}

	void end()
	{
		for (int i = 0; i < maxEnemies; i++)
		{
			if (enemies[i] != nullptr)
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}
}