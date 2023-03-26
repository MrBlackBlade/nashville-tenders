#include <check_idle.hpp>

extern Texture s_player_texture_idle;
extern Texture b_player_texture_idle;
extern Player  s_obj;
extern Player  b_obj;

void check_idle(Sprite& player, Player& obj)
{
	// switching between different idle frames
	if (obj.idle && frame_counter % ((obj.id == 0) ? 16 : 12)==0)
	// the 18 will be a parameter to adjust the animation speed
	{
		player.setTexture
		(
			(obj.id == 0) ? s_player_texture_idle : b_player_texture_idle
		);

		player.setTextureRect
		(
			IntRect
			(
				obj.idle_ind * obj.sprite_size_idle, 0, obj.sprite_size_idle, 64
			)
		);

		obj.idle_ind++;
		obj.idle_ind %= obj.anims_idle;

		// breaking the idle state
		for (size_t i = 0; i < 2; i++)
			for (size_t j = 0; j < 4; j++)
				if (keybinds[i][j] == get_key_pressed_b() ||
					keybinds[i][j] == get_key_pressed_s())
					obj.idle = false;
	}
}