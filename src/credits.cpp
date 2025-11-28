#include "credits.h"


#include "button.h"
#include "global.h"
#include "math.h"

namespace credits
{
	const int maxButtons = 1;
	button::Button buttons[maxButtons];

	sf::Font font1("resource/fonts/CourierPrime-Regular.ttf");

	Screen nextScreen;

	void init()
	{
		nextScreen = Screen::CREDITS;

		sf::Vector2f buttonPos = { 15, 7 };
		sf::Vector2f buttonSize = { 20, 6 };

		buttons[0] = button::init(buttonPos, buttonSize, "EXIT", [&]() { nextScreen = Screen::MENU; });
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

		float middleX = global::viewport.x / 2;

		render::text("CREDITS", font1, { middleX, 2 }, 7, render::TextAlgin::CENTER);
		render::text("Programming", font1, { middleX - 30, 30 }, 5, render::TextAlgin::CENTER);
		render::text("Santino Verrua", font1, { middleX + 30, 30 }, 5, render::TextAlgin::CENTER);

		render::text("ver 0.4", font1, { 3, 95 }, 3);
	}
}