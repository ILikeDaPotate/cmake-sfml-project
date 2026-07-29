#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "configuration.hpp"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { conf::window_size.x, conf::window_size.y } ), "SFML works!" );
	window.setFramerateLimit(conf::max_framerate);
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
