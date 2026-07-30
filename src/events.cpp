#include "events.hpp"
#include "ui_generator.hpp"
#include <iostream>

void processEvents(sf::Window& window, gui::Point& point) {
	//sf::Vector2f mousePos_f = static_cast<sf::Vector2f>(sf::Mouse::getPosition());

	while ( const std::optional event = window.pollEvent() )
	{
		if ( event->is<sf::Event::Closed>() ) 
		{
			window.close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
				window.close();
			}
        }
		else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
			if (mousePressed->button == sf::Mouse::Button::Left) {
				std::cout << "Left mouse down at: " 
						<< mousePressed->position.x << ", " 
						<< mousePressed->position.y << "\n";

				sf::Vector2f mousePos_f = static_cast<sf::Vector2f>(mousePressed->position);
				point = gui::Point(mousePos_f, sf::Color(mousePos_f.x, mousePos_f.y, sf::Mouse::ButtonCount * 20));
			}
		}
	}
}