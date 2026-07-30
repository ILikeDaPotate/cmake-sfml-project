#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sf { class RenderWindow; } // Forward-declare RenderWindow; it will be defined in the cpp file




namespace gui
{
	class Point : public sf::Drawable {
		public:
			Point(sf::Vector2f position, sf::Color color = sf::Color::White);
			void setPosition(sf::Vector2f position);
		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			sf::CircleShape shape; 
	};

	class RoundedRectangle : public sf::Drawable {
		public:
			RoundedRectangle(sf::Vector2f size, float radius_, sf::Vector2f position_, uint32_t quality_, sf::Color color_ = sf::Color::White);
			void GenerateVertices();
			sf::Vertex GetIthVertex(uint32_t i);
		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			float radius;
			sf::Vector2f position;
			uint32_t quality;
			sf::Color color;
			sf::Vector2f centers[4];

			sf::VertexArray vertex_array;
	};

	class RoundedRectangleOutline : public sf::Drawable {
		public:
			RoundedRectangleOutline(sf::Vector2f size, float radius_, sf::Vector2f position_, uint32_t quality_, 
				float thickness, sf::Color inner_color = sf::Color::White, sf::Color outer_color = sf::Color::White);
		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			sf::VertexArray vertex_array;
	};
}