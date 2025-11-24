#include "game.h"

#include "render.h"

namespace game
{
	void start()
	{

	}

	Screen update()
	{
		return Screen::GAME;
	}

	void draw()
	{
		render::circle(100, sf::Color::Green);
	}

	void end()
	{

	}
}