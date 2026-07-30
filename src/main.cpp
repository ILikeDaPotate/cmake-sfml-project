#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "configuration.hpp"
#include "ui_generator.hpp"

int main()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = conf::antialiasing_level;

	sf::RenderWindow window( sf::VideoMode( { conf::window_size.x, conf::window_size.y } ), "SFML works!" );
	window.setFramerateLimit(conf::max_framerate);

	gui::Point point(6.0, sf::Vector2f{500.0, 20.0});
	gui::RoundedRectangle roundedRectangle({400.0, 200.0}, 20.0, {300.0, 300.0}, 8);

	while ( window.isOpen() )
	{
		processEvents(window, point);

		window.clear(conf::background_color);

		point.draw(window);
		roundedRectangle.draw(window);

		window.display();
	}
}
