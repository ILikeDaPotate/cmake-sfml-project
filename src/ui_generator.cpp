#include "ui_generator.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

constexpr float pi{3.141592};

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

	/////////////////////////////////////////////////////
	

	/*
		* @param quality The number of sides on each corner
	*/
	RoundedRectangle::RoundedRectangle(sf::Vector2f size, float radius, sf::Vector2f position, uint32_t quality) 
		:
		centers{
			{size.x - radius, size.y - radius}, // Bottom right
			{radius, size.y - radius},          // Bottom left
			{radius, radius},                   // Top left
			{size.x - radius, radius},          // Top right
		},
		vertex_array{sf::PrimitiveType::TriangleFan, quality * 4}
	{

		float da{static_cast<float>((2.0 * pi)) / static_cast<float>((quality - 1) * 4)};

		for (uint32_t i{0}; i < quality * 4; ++i) {
			uint32_t const corner_id{i / quality};
			float const angle{da * (i - corner_id)};
			vertex_array[i].position = position + centers[corner_id] + (radius * sf::Vector2f{cosf(angle), sinf(angle)});
		}
	}

	void RoundedRectangle::draw(sf::RenderWindow& window) {
		window.draw(vertex_array);
	}
}