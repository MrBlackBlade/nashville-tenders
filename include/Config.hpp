#pragma once
#ifndef _CONFIG_HPP
#define _CONFIG_HPP

#include <SFML\Graphics.hpp>
#include <cstdint>

using namespace sf;

namespace Config
{
	extern const std::uint16_t RES_SIZE;

	extern std::int32_t frame_counter;

	extern const Keyboard::Key keybinds[2][4];
}

#endif // #ifndef _CONFIG_HPP