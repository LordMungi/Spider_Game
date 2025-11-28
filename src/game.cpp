#include "game.h"

#include "spider.h"
#include "enemy.h"

#include "global.h"
#include "collision.h"
#include "button.h"

namespace game
{
	enum class State
	{
		RUNNING,
		STANDBY,
		PAUSED,
	};


	static void reset();

	static void updatePlayer(float delta);
	static void spawnEnemies(float delta);
	static void updateEnemies(float delta);

	sf::Clock deltaClock;
	sf::Clock enemyClock;

	const int maxEnemies = 50;

	spider::Spider spider;
	enemy::Enemy* enemies[maxEnemies];

	float enemySpawnCooldown;
	float enemyCooldownSpeed = 0.05f;
	float enemyMinCooldown = 0.8f;

	const int enemyValue = 100;
	int score;

	State gamestate;
	Screen nextScreen;

	const int maxButtons = 2;
	button::Button buttons[maxButtons];

	sf::Font font1("resource/fonts/CourierPrime-Regular.ttf");

	void start()
	{
		deltaClock.start();
		enemyClock.start();

		enemySpawnCooldown = 2.5;
		score = 0;

		gamestate = State::STANDBY;

		sf::Vector2f buttonPos = { global::viewport.x / 2, 40 };
		sf::Vector2f buttonSize = { 50, 10 };
		float buttonSeparation = 13;

		buttons[0] = button::init(buttonPos, buttonSize, "RESUME", [&]() { gamestate = State::RUNNING; });
		buttonPos.y += buttonSeparation;
		buttons[1] = button::init(buttonPos, buttonSize, "EXIT", [&]() { nextScreen = Screen::MENU; });

		spider = spider::init(5, { global::viewport.x / 2, 0}, 70);

		nextScreen = Screen::GAME;
	}

	Screen update()
	{
		float delta = deltaClock.restart().asSeconds();


		switch (gamestate)
		{
		case State::RUNNING:
		{
			spawnEnemies(delta);
			updateEnemies(delta);
		}
		case State::STANDBY:
		{
			updatePlayer(delta);
			break;
		}

		case State::PAUSED:
			for (int i = 0; i < maxButtons; i++)
				button::update(buttons[i]);
			break;
		}

		return nextScreen;
	}

	void draw()
	{
		switch (gamestate)
		{
		case State::STANDBY:
		{
			render::text("W/Up", font1, { 3, 2 }, 3);
			render::text("S/Down", font1, { 3, 6 }, 3);
			render::text("A/Left", font1, { 3, 10 }, 3);
			render::text("D/Right", font1, { 3, 14 }, 3);

			render::text("Shorten string", font1, { 20, 2 }, 3);
			render::text("Lengthen string", font1, { 20, 6 }, 3);
			render::text("Push left", font1, { 20, 10 }, 3);
			render::text("Push right", font1, { 20, 14 }, 3);

			render::text("SPACE to start", font1, { global::viewport.x / 2, 90 }, 7, render::TextAlgin::CENTER);
			break;
		}
		case State::RUNNING:
		case State::PAUSED:
		{
			render::text(std::to_string(score), font1, { global::viewport.x / 2, 90 }, 7, render::TextAlgin::CENTER);
			float livesPosX = 3;
			for (int i = 0; i < spider.lives; i++)
			{
				render::text("<3", font1, { livesPosX, 2 }, 7);
				livesPosX += 9;
			}
			break;
		}
		}

		spider::draw(spider);

		for (int i = 0; i < maxEnemies; i++)
		{
			if (enemies[i] != nullptr)
				enemy::draw(*enemies[i]);
		}

		if (gamestate == State::PAUSED)
		{
			for (int i = 0; i < maxButtons; i++)
				button::draw(buttons[i], font1);
		}

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

	static void reset()
	{
		for (int i = 0; i < maxEnemies; i++)
		{
			if (enemies[i] != nullptr)
			{
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
		enemyClock.restart();
		spider::reset(spider);
	}

	static void updatePlayer(float delta)
	{
		if (spider.state != spider::State::DEAD)
		{
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
				gamestate = State::RUNNING;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				if (gamestate == State::RUNNING)
					gamestate = State::PAUSED;
				else
					gamestate = State::RUNNING;
			}

		}
		else
		{
			spider::fall(spider, delta);
			if (spider.deathClock.getElapsedTime().asSeconds() >= spider.respawnCooldown)
			{
				if (spider.lives <= 0)
				{
					end();
					start();
				}
				else
					reset();
			}
		}
	}
	static void spawnEnemies(float delta)
	{
		enemySpawnCooldown = fmaxf(enemySpawnCooldown - enemyCooldownSpeed * delta, enemyMinCooldown);
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
	}
	static void updateEnemies(float delta)
	{
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
				if (enemies[i]->collider.getPosition().y - enemies[i]->collider.getRadius() > global::viewport.y ||
					enemies[i]->collider.getPosition().y + enemies[i]->collider.getRadius() < 0)
				{
					enemy::bounceVertical(*enemies[i]);
				}

				if (spider.state != spider::State::DEAD)
				{
					if (collision::circleCircle(enemies[i]->collider, spider.collider))
					{
						delete enemies[i];
						enemies[i] = nullptr;
						score += enemyValue;
					}
					else if (collision::circleLine(enemies[i]->collider, spider.collider.getPosition(), spider.pivotPosition))
					{
						spider::die(spider);
					}
				}
			}
		}

	}
}