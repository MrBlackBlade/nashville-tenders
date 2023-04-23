#include <Config.hpp>

namespace Config
{
	const sf::Uint16 RES_SIZE = 900;
	sf::Uint16 frame_counter = 0;

	const sf::Keyboard::Key keybinds[2][4]
	{
		// small player keybinds
		{
			sf::Keyboard::Up   ,
			sf::Keyboard::Left ,
			sf::Keyboard::Down ,
			sf::Keyboard::Right
		},

		// big player keybinds
		{
			sf::Keyboard::W	   ,
			sf::Keyboard::A	   ,
			sf::Keyboard::S	   ,
			sf::Keyboard::D
		}
	};
}