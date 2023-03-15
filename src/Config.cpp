#include <Config.hpp>

namespace Config
{
	const std::uint16_t RES_SIZE = 850;

	std::int32_t
		// to adjust the animation speed
		frame_counter = 0;

	const Keyboard::Key* s_player_binds
	{ new Keyboard::Key[4]
	{
		Keyboard::W,
		Keyboard::A,
		Keyboard::S,
		Keyboard::D
	}
	};

	const Keyboard::Key* b_player_binds
	{ new Keyboard::Key[4]
	{
		Keyboard::Up,
		Keyboard::Left,
		Keyboard::Down,
		Keyboard::Right
	}
	};
}