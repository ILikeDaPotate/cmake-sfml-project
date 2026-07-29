#pragma once
#include <SFML/System/Vector2.hpp>

namespace conf
{
	sf::Vector2u const window_size = {960, 720};
	sf::Vector2f const window_size_f = static_cast<sf::Vector2f>(window_size);
	uint32_t const max_framerate = 144;
}