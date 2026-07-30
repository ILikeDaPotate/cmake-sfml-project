#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sf { class RenderWindow; } // Forward-declare RenderWindow; it will be defined in the cpp file

float const outlineThickness = 3.0;

namespace gui
{
	class Point : public sf::Drawable {
		public:
			Point( float radius, sf::Vector2f position);
			void setPosition(sf::Vector2f position);
		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			sf::CircleShape shape; 
	};

	class RoundedRectangle : public sf::Drawable {
		public:
			RoundedRectangle(sf::Vector2f size, float radius_, sf::Vector2f position_, uint32_t quality_);
			void GenerateVertices();
			sf::Vector2f GetIthVertex(uint32_t i);
		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			float radius;
			sf::Vector2f position;
			uint32_t quality;
			sf::Vector2f centers[4];

			sf::VertexArray vertex_array;
	};
}