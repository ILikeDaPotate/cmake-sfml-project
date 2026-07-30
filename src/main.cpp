#include <SFML/Graphics.hpp>
#include "events.hpp"
#include "configuration.hpp"
#include "ui_generator.hpp"

int main()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = conf::antialiasing_level;

	sf::RenderWindow window( sf::VideoMode( { conf::window_size.x, conf::window_size.y } ), "SFML works!", sf::Style::Default, sf::State::Windowed, settings );
	window.setFramerateLimit(conf::max_framerate);

	gui::Point point(6.0, sf::Vector2f{500.0, 20.0});
	gui::RoundedRectangle roundedRectangle({500.0, 300.0}, 20.0, {300.0, 300.0}, 3);

	while ( window.isOpen() )
	{
		processEvents(window, point);

		window.clear(conf::background_color);

		point.draw(window);
		roundedRectangle.draw(window);

		window.display();
	}
}
