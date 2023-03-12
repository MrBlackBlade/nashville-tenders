#pragma once
#include <SFML\Graphics.hpp>
#include <cstdint>

using namespace sf;

namespace Config
{
	extern const std::uint16_t RES_SIZE;

	extern std::int32_t
		// 0 for first sprite, 1 for second etc...
		idle_animation_indicator,
		run_animation_indicator,

		// to adjust the animation speed
		frame_counter,

		// sprite size multiplier
		player_scale,

		// player speed	
		velocity;

	extern bool idle;
}