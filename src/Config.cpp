#include <Config.hpp>

namespace Config
{
	const std::uint16_t RES_SIZE = 850;

	std::int32_t
		// 0 for first sprite, 1 for second etc...
		s_idle_ind = 0,
		s_run_ind = 0,
		b_idle_ind = 0,
		b_run_ind = 0,

		// to adjust the animation speed
		frame_counter = 0,

		// sprite measurements
		s_player_scale = 3,
		b_player_scale = 3,
		s_sprite_size_idle = 28,
		s_sprite_size_run = 40,
		b_sprite_size_idle = 28,
		b_sprite_size_run = 64,

		// no of diff animations
		s_anims = 4,
		b_anims_idle = 4,
		b_anims_run = 6,

		// player speed
		s_velocity = 0,
		b_velocity = 0,
		s_velocity_max = 60,
		b_velocity_max = 25;

	const std::int16_t s_player_id = 0, b_player_id = 1;

	constexpr Keyboard::Key s_player_binds[4] =
	{
		Keyboard::W,
		Keyboard::A,
		Keyboard::S,
		Keyboard::D
	};

	constexpr Keyboard::Key b_player_binds[4] =
	{
		Keyboard::Up,
		Keyboard::Left,
		Keyboard::Down,
		Keyboard::Right
	};

	bool s_idle = true;
	bool b_idle = true;
}