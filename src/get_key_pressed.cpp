#include <get_key_pressed.hpp>

sf::Keyboard::Key get_key_pressed(Pair_Player& pair)
{
	for (size_t bind = 0; bind < 4; ++bind)
		if (sf::Keyboard::isKeyPressed(Config::keybinds[pair.obj->id][bind]))
			return Config::keybinds[pair.obj->id][bind];

	return sf::Keyboard::Unknown;
}