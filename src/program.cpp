#include "program.h"

#include "global.h"
#include "render.h"

#include "game.h"
#include "menu.h"

namespace program
{
	static void init();
	static void update();
	static void draw();
	static void switchScreen();
	static void close();

	Screen currentScreen = Screen::MENU;
	Screen previousScreen = Screen::EXIT;

	bool isRunning = true;

	void run()
	{
		init();

		while (render::isWindowOpen())
		{
			update();
			draw();
			switchScreen();
		}

		close();
	}

	static void init()
	{
		srand(static_cast<unsigned int>(time(0)));
		render::startWindow(global::resolution, "Spider game");
	}

	static void update()
	{
		render::updateWindow();

		switch (currentScreen)
		{
		case Screen::GAME:
			currentScreen = game::update();
			break;
		case Screen::MENU:
			currentScreen = menu::update();
			break;
		case Screen::EXIT:
			isRunning = false;
			break;
		}
	}

	static void draw()
	{
		render::clear();

		switch (currentScreen)
		{
		case Screen::GAME:
			game::draw();
			break;
		case Screen::MENU:
			menu::draw();
			break;
		}

		render::draw();
	}

	static void switchScreen()
	{
		if (currentScreen != previousScreen)
		{
			switch (previousScreen)
			{
			case Screen::GAME:
				game::end();
				break;
			}

			switch (currentScreen)
			{
			case Screen::GAME:
				game::start();
				break;
			case Screen::MENU:
				menu::init();
				break;
			}
		}

		previousScreen = currentScreen;
	}

	static void close()
	{
	}
}