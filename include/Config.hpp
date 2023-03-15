#pragma once
#include <SFML\Graphics.hpp>
#include <cstdint>

using namespace sf;

namespace Config
{
	extern const std::uint16_t RES_SIZE;

	extern std::int32_t
		// to adjust the animation speed
		frame_counter;

	extern const Keyboard::Key* s_player_binds;
	extern const Keyboard::Key* b_player_binds;
}