#pragma once
#include "render.h"

namespace spider
{
	enum class State
	{
		IDLE,
		DEAD,
	};

	struct Spider
	{
		sf::CircleShape collider;
		State state;
		int lives;

		sf::Clock deathClock;
		float fallCooldown = 0.5f;
		float respawnCooldown = 2.0f;

		sf::Vector2f pivotPosition;
		float angle;
		
		float stringLength;
		float maxStringLength;
		float minStringLength;
		float stringSpeed = 100.0f;

		float velocity;
		float acceleration;

		float strength = 200.0f;
	};

	Spider init(float radius, sf::Vector2f pivotPosition, float maxStringLength);

	void updatePosition(Spider& spider, float delta);

	void pushRight(Spider& spider, float delta);
	void pushLeft(Spider& spider, float delta);
	void lengthenString(Spider& spider, float delta);
	void shortenString(Spider& spider, float delta);

	void die(Spider& spider);
	void fall(Spider& spider, float delta);
	void reset(Spider& spider);

	void draw(Spider& spider);

}