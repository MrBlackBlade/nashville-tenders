#pragma once

#include <cstdint>
#include <SFML\Graphics.hpp>

using namespace sf;

struct Player
{
	Player
	(
		const std::int32_t&,
		const std::int32_t&,
		const std::int32_t&,
		const std::int32_t&,
		const std::int32_t&,
		const std::int32_t&,
		const std::int32_t&,
		const std::int32_t&,
		const std::int32_t&,
		const std::int16_t&,
		const bool&
	);

	std::int32_t
		// 0 for first sprite, 1 for second etc...
		idle_ind,
		run_ind,

		// sprite measurements
		player_scale,
		sprite_size_idle,
		sprite_size_run,
		
		// no of diff animations
		anims_idle,
		anims_run,

		// player speed	
		velocity,
		velocity_max;

	std::int16_t id;

	bool idle;
	
	Keyboard::Key keybinds[4];

	void set_binds(const Keyboard::Key*);
};
