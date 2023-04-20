#include <check_idle.hpp>

extern sf::Texture s_player_texture_idle;
extern sf::Texture b_player_texture_idle;
extern Player  s_obj;
extern Player  b_obj;

void check_idle(sf::Sprite& player, Player& obj)
{
	// switching between different idle frames
	if (obj.idle && Config::frame_counter % ((obj.id == 0) ? 16 : 12)==0)
	// the 18 will be a parameter to adjust the animation speed
	{
		player.setTexture
		(
			(obj.id == 0) ? s_player_texture_idle : b_player_texture_idle
		);

		player.setTextureRect
		(
			sf::IntRect
			(
				obj.idle_ind * obj.sprite_size_idle, 0, obj.sprite_size_idle, obj.sprite_sizeH_idle
			)
		);

		obj.idle_ind++;
		obj.idle_ind %= obj.anims_idle;

		// breaking the idle state
		for ( size_t i = 0; i < 4; i++ )
			if (Config::keybinds[obj.id][i] == get_key_pressed(obj))
				obj.idle = false;
	}
}