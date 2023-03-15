#include <check_idle.hpp>

extern Texture s_player_texture_idle;
extern Texture b_player_texture_idle;
extern Player s_obj;
extern Player b_obj;

void check_idle(Sprite& player, Player& obj)
{
	// switching between different idle frames
	if (obj.idle && frame_counter % 16 == 0)
		// the 16 will be a parameter to adjust the animation speed
	{
		player.setTexture
		(
			(obj.id == 0) ? s_player_texture_idle : b_player_texture_idle
		);

		player.setTextureRect(IntRect(obj.idle_ind * obj.sprite_size_idle, 0, obj.sprite_size_idle, 51));
		obj.idle_ind++;
		obj.idle_ind %= obj.anims_idle;

		// breaking the idle state
		/*if (Keyboard::isKeyPressed(Keyboard::Key::W)
			|| Keyboard::isKeyPressed(Keyboard::Key::A)
			|| Keyboard::isKeyPressed(Keyboard::Key::S)
			|| Keyboard::isKeyPressed(Keyboard::Key::D))*/
		for (const auto& bind : obj.keybinds)
			if (bind == get_key_pressed_s() || bind == get_key_pressed_b())
				obj.idle = false;
				
	}
}