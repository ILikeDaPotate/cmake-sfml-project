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

	gui::RoundedRectangle box({500.0, 300.0}, 20.0, {300.0, 300.0}, 6, sf::Color(255, 76, 64));
	gui::RoundedRectangleOutline boxOutline({500.0, 300.0}, 20.0, {300.0, 300.0}, 6, -5.0);
	gui::RoundedRectangleOutline boxShadow({500.0, 300.0}, 20.0, {300.0, 300.0}, 6, 15.0, sf::Color(0, 0, 0, 50), sf::Color::Transparent);

	while ( window.isOpen() )
	{
		processEvents(window, point);

		window.clear(conf::background_color);

		window.draw(boxShadow);
		window.draw(box);
		window.draw(boxOutline);

		window.draw(point);

		window.display();
	}
}
