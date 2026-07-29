#include <SFML/Graphics.hpp>
#include "events.hpp"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Yellow );

	while ( window.isOpen() )
	{
		processEvents(window);

		window.clear();
		window.draw( shape );
		window.display();
	}
}
