#include <Config.hpp>

namespace Config
{
	const sf::Uint16 RES_SIZE = 900;
	sf::Uint16 frame_counter = 0;

	const sf::Keyboard::Key keybinds[2][4]
	{
		{
			sf::Keyboard::Up   ,
			sf::Keyboard::Left ,
			sf::Keyboard::Down ,
			sf::Keyboard::Right
		},

		{
			sf::Keyboard::W	   ,
			sf::Keyboard::A	   ,
			sf::Keyboard::S	   ,
			sf::Keyboard::D
		}
	};
}