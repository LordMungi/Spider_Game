#include "menu.h"

#include "button.h"
#include "global.h"
#include "math.h"

namespace menu
{
	const int maxButtons = 3;
	button::Button buttons[maxButtons];

	sf::Font font1("resource/fonts/AnticDidone-Regular.otf");
	sf::Font font2("resource/fonts/Archistico_Bold.ttf");

	Screen nextScreen;

	void init()
	{
		nextScreen = Screen::MENU;

		sf::Vector2f buttonPos = { global::viewport.x / 2, 50 };
		sf::Vector2f buttonSize = { 50, 10 };
		float buttonSeparation = 13;

		buttons[0] = button::init(buttonPos, buttonSize, "PLAY", [&]() { nextScreen = Screen::GAME; });
		buttonPos.y += buttonSeparation;
		buttons[1] = button::init(buttonPos, buttonSize, "CREDITS", [&]() { nextScreen = Screen::CREDITS; });
		buttonPos.y += buttonSeparation;
		buttons[2] = button::init(buttonPos, buttonSize, "EXIT", [&]() { nextScreen = Screen::EXIT; });

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
		render::text("Web Cleaner", font2, { global::viewport.x / 2, 20 }, 15, render::TextAlgin::CENTER);
		for (int i = 0; i < maxButtons; i++)
		{
			button::draw(buttons[i], font1);
		}
		render::text("ver 1.0", font1, { 3, 95 }, 3);
	}
}