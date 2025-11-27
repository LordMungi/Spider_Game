#include "menu.h"

#include "button.h"
#include "global.h"
#include "math.h"

namespace menu
{
	const int maxButtons = 1;
	button::Button buttons[maxButtons];

	sf::Font font1("resource/fonts/CourierPrime-Regular.ttf");

	Screen nextScreen;

	void init()
	{
		nextScreen = Screen::MENU;

		sf::Vector2f buttonPos = { global::viewport.x / 2, 50 };
		sf::Vector2f buttonSize = { 50, 10 };
		float buttonSeparation = 20;

		buttons[0] = button::init(buttonPos, buttonSize, "PLAY", [&]() { nextScreen = Screen::GAME; });
		buttonPos.y += buttonSeparation;

	}

	Screen update()
	{
		for (int i = 0; i < maxButtons; i++)
		{
			button::update(buttons[i]);
		}

		return nextScreen;
	}

	void draw()
	{
		for (int i = 0; i < maxButtons; i++)
		{
			button::draw(buttons[i], font1);
		}
	}
}