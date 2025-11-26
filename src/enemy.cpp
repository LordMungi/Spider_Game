#include "enemy.h"
#include <iostream>

namespace enemy
{
	Enemy init(sf::Vector2f gameBorders, float radius)
	{
		Enemy enemy;

		enemy.collider.setRadius(radius);

		sf::Vector2f position;
		switch (rand() % 3)
		{
		case 0:
			position.x = static_cast<float>(rand() % static_cast<int>(gameBorders.x) + 1);
			position.y = gameBorders.y + radius;
			break;
		case 1:
			position.x = gameBorders.x + radius;
			position.y = static_cast<float>(rand() % static_cast<int>(gameBorders.y) + 1);
			break;
		case 2:
			position.x = -radius;
			position.y = static_cast<float>(rand() % static_cast<int>(gameBorders.y) + 1);
			break;
		}
		enemy.collider.setPosition(position);

		enemy.direction.x = rand() % static_cast<int>(gameBorders.x / 2) + gameBorders.x / 4 - position.x;
		enemy.direction.y = rand() % static_cast<int>(gameBorders.y / 2) + gameBorders.y / 4 - position.y;
		enemy.direction /= sqrt(enemy.direction.x * enemy.direction.x + enemy.direction.y * enemy.direction.y);

		enemy.speed = 30;

		return enemy;

	}

	void move(Enemy& enemy, float delta)
	{
		enemy.collider.setPosition(enemy.collider.getPosition() + enemy.direction * enemy.speed * delta);
	}

	void bounceHorizontal(Enemy& enemy)
	{
		enemy.direction.x *= -1;
	}
	void bounceVertical(Enemy& enemy)
	{
		enemy.direction.y *= -1;
	}

	void draw(Enemy& enemy)
	{
		render::circle(enemy.collider, sf::Color::Blue);
	}
}