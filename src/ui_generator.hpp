#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sf { class RenderWindow; } // Forward-declare RenderWindow; it will be defined in the cpp file

float const outlineThickness = 3.0;

namespace gui
{
	class Point {
		public:
			Point( float radius, sf::Vector2f position);
			void setPosition(sf::Vector2f position);
			void draw(sf::RenderWindow& window); 
		private:
			sf::CircleShape shape; 
	};
}