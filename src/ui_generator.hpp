#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sf { class RenderWindow; } // Forward-declare RenderWindow; it will be defined in the cpp file

namespace gui
{
	class CircleGenerator {
		public:
			CircleGenerator(float radius_, uint32_t quality);

			sf::Vector2f GetIthPoint(uint32_t i);

		private:
			float radius;
			float da;
	};

	class Point : public sf::Drawable {
		public:
			Point(sf::Vector2f position, sf::Color color = sf::Color::White);

			static int constexpr quality = 20;
			static float constexpr shape_radius = 15.0;
			static float constexpr shadow_radius = 30.0;
			static sf::Color constexpr shadow_col = sf::Color(0, 0, 0, 60);
		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			sf::VertexArray shape;
			CircleGenerator innerCircle;
			sf::VertexArray shadow;
			CircleGenerator outerCircle;
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