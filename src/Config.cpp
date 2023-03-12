#include "..\include\Config.hpp"

namespace Config
{
	const std::uint16_t RES_SIZE = 850;

	std::int32_t
	// 0 for first sprite, 1 for second etc...
	idle_animation_indicator = 0,
	run_animation_indicator = 0,

	// to adjust the animation speed
	frame_counter = 0,

	// sprite size multiplier
	player_scale = 3,

	// player speed
	velocity = 4;

	bool idle = true;
}