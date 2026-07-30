#include "ui_generator.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

constexpr float pi{3.141592};

float constexpr point_radius{5.0};

// Anonymous namespace only lets this file use the class inside it
namespace 
{
	class CircleGenerator {
		public:
			CircleGenerator(float radius_, uint32_t quality) 
			:
				radius{radius_},
				da{static_cast<float>((2.0 * pi)) / static_cast<float>(quality)}
			{ }

			sf::Vector2f GetIthPoint(uint32_t i) {
				float const angle{da * i};
				return (radius * sf::Vector2f{cosf(angle), sinf(angle)});
			}

		private:
			float radius;
			float da;
	};
}

namespace gui 
{
	#pragma region Point Class

	Point::Point(sf::Vector2f position, sf::Color color) {
		shape.setRadius(point_radius);
		shape.setOrigin(sf::Vector2f{point_radius, point_radius});
		shape.setPosition(position);
		shape.setFillColor(color);
	}

	void Point::setPosition(sf::Vector2f position) {
		shape.setPosition(position);
	}

	void Point::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    	target.draw(shape, states);
	}

	#pragma endregion

	#pragma region Rounded Rectangle Class

	/*
		* @param quality_ The number of sides on each corner
	*/
	RoundedRectangle::RoundedRectangle(sf::Vector2f size, float radius_, sf::Vector2f position_, uint32_t quality_, sf::Color color_) 
		:
		radius{radius_},
		position{position_},
		quality{quality_},
		color{color_},
		centers{
			{size.x - radius, size.y - radius}, // Bottom right
			{radius, size.y - radius},          // Bottom left
			{radius, radius},                   // Top left
			{size.x - radius, radius},          // Top right
		},
		vertex_array{sf::PrimitiveType::TriangleFan, quality * 4}
	{

		GenerateVertices();
	}

	void RoundedRectangle::GenerateVertices() {
		CircleGenerator circle(radius, (quality - 1) * 4);
		
		for (uint32_t i{0}; i < quality * 4; ++i) {
			uint32_t const corner_id{i / quality};
			vertex_array[i].position = position + centers[corner_id] + circle.GetIthPoint(i - corner_id);
			vertex_array[i].color = color;
		}
	}

	sf::Vertex RoundedRectangle::GetIthVertex(uint32_t i){
		return vertex_array[i];
	}

	void RoundedRectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    	target.draw(vertex_array, states);
	}

	#pragma endregion

	#pragma region Rounded Rectangle Outline Class

	/*
		* @note inner_color and outer_color are optional parameters which are mostly useful for shadows
	*/
	RoundedRectangleOutline::RoundedRectangleOutline(sf::Vector2f size, float radius, sf::Vector2f position, uint32_t quality, 
		float thickness, sf::Color inner_color, sf::Color outer_color) 
		:
			vertex_array{sf::PrimitiveType::TriangleStrip, quality * 4 * 2 + 2}
	{
		RoundedRectangle inner(size, radius, position, quality, inner_color);
		RoundedRectangle outer({size.x + 2 * thickness, size.y + 2 * thickness}, radius + thickness, {position.x - thickness, position.y - thickness}, quality, outer_color);

		for (uint32_t i{0}; i < quality * 4; ++i) {
			vertex_array[i * 2] = inner.GetIthVertex(i);
			vertex_array[i * 2 + 1] = outer.GetIthVertex(i);
		}

		// Connect the last corner to the first
		vertex_array[quality * 4 * 2] = inner.GetIthVertex(0);
		vertex_array[quality * 4 * 2 + 1] = outer.GetIthVertex(0);
	}

	void RoundedRectangleOutline::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    	target.draw(vertex_array, states);
	}

	#pragma endregion
}