#pragma once
#include <SFML\Graphics.hpp>
#include <cstdint>

using namespace sf;

namespace Config
{
	extern const std::uint16_t RES_SIZE;

	extern std::int32_t
		// 0 for first sprite, 1 for second etc...
		s_idle_ind,
		s_run_ind, 
		b_idle_ind,
		b_run_ind, 

		// to adjust the animation speed
		frame_counter,

		// sprite measurements
		s_player_scale,
		b_player_scale,
		s_sprite_size_idle,
		s_sprite_size_run,
		b_sprite_size_idle,
		b_sprite_size_run,

		// no of diff animations
		s_anims,
		b_anims_idle,
		b_anims_run,

		// player speed	
		s_velocity,
		b_velocity,
		s_velocity_max,
		b_velocity_max;

	extern const std::int16_t s_player_id, b_player_id;

	extern const Keyboard::Key s_player_binds[4];
	extern const Keyboard::Key b_player_binds[4];

	extern bool s_idle;
	extern bool b_idle;
}