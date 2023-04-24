#pragma once
#ifndef _CONFIG_HPP
#define _CONFIG_HPP

#include <SFML/Graphics.hpp>

namespace Config
{
	extern const sf::Uint16 RES_SIZE;

	extern sf::Uint16 frame_counter;

	extern const sf::Keyboard::Key keybinds[2][4];
};

#endif // #ifndef _CONFIG_HPP