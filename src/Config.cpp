#include <Config.hpp>

namespace Config
{
	const std::uint16_t RES_SIZE = 850;

	std::int32_t frame_counter = 0;
	
	const Keyboard::Key (*keybinds)[4] = new Keyboard::Key[2][4]
	{
		{
			Keyboard::Up   ,
			Keyboard::Left ,
			Keyboard::Down ,
			Keyboard::Right
		},

		{
			Keyboard::W	   ,
			Keyboard::A	   ,
			Keyboard::S	   ,
			Keyboard::D
		}
	};
}
