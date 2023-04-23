#include <check_idle.hpp>

// small player
extern sf::Texture s_player_texture_idle;
extern Player	   s_obj;

// big player
extern sf::Texture b_player_texture_idle;
extern Player	   b_obj;

void check_idle(sf::Sprite& player, Player& obj)
{
	if (obj.idle)
	{
		animate(player, obj, Animation::idle);

		// breaking the idle state
		for ( size_t i = 0; i < 4; i++ )
			if ( Config::keybinds[obj.id][i] == get_key_pressed(obj) )
				obj.idle = false;
	}
}