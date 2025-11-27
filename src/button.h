#pragma once
#include "render.h"
#include <functional>

namespace button
{
	struct Button
	{
		std::string label;
		sf::RectangleShape shape;

		bool wasPressed = false;
		bool isPressed = false;
		bool isSelected = false;

		std::function<void()> onTrigger;
	};

	Button init(sf::Vector2f position, sf::Vector2f size, std::string label, std::function<void()> onTrigger);

	void update(Button& button);
	void draw(Button button, sf::Font font);
}