#include "ui_generator.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace gui 
{
	Point::Point(float radius, sf::Vector2f position) {
		shape.setRadius(radius);
		shape.setOrigin(sf::Vector2f{radius, radius});
		shape.setPosition(position);
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineThickness(outlineThickness);
		shape.setOutlineColor(sf::Color::White);
	}

	void Point::setPosition(sf::Vector2f position) {
		shape.setPosition(position);
	}

	void Point::draw(sf::RenderWindow& window) {
		window.draw(shape);
	}
}