#include "button.h"

#include "collision.h"
#include "math.h"
#include "global.h"

namespace button
{
	Button init(sf::Vector2f position, sf::Vector2f size, std::string label, std::function<void()> onTrigger)
	{
		Button button;

		button.label = label;
		button.shape = sf::RectangleShape(size);
		button.shape.setPosition(position);
		button.onTrigger = onTrigger;

		button.wasPressed = false;
		button.isPressed = false;
		button.isSelected = false;

		return button;
	}

	void update(Button& button)
	{
		button.isSelected = collision::pointRectangle(global::mousePosition, button.shape);

		if (button.isSelected)
		{
			button.isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

			if (!button.isPressed && button.wasPressed)
				button.onTrigger();

			button.wasPressed = button.isPressed;
		}
		else
		{
			button.isPressed = false;
			button.wasPressed = false;
		}
	}

	void draw(Button button, sf::Font font)
	{
		if (button.isPressed)
			render::rectangle(button.shape, sf::Color::Red);
		else if (button.isSelected)
			render::rectangle(button.shape, sf::Color::Blue);
		else
			render::rectangle(button.shape, sf::Color::White);

		sf::Vector2f textPos = button.shape.getPosition();
		textPos.y = button.shape.getPosition().y - button.shape.getSize().y / 2;

		render::text(button.label, font, textPos, button.shape.getSize().y, render::TextAlgin::CENTER, sf::Color::Black);
	}
}