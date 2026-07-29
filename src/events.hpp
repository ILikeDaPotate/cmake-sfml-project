#pragma once
#include <SFML/Window.hpp>

namespace gui { class Point; }

void processEvents(sf::Window& window, gui::Point& point);
