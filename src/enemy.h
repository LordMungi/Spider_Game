#pragma once
#include "render.h"

namespace enemy
{
	struct Enemy
	{
		sf::CircleShape collider;
		sf::Vector2f direction;
		float speed;
	};

	Enemy init(sf::Vector2f gameBorders, float radius);

	void move(Enemy& enemy, float delta);

	void bounceHorizontal(Enemy& enemy);
	void bounceVertical(Enemy& enemy);

	void draw(Enemy& enemy);
}