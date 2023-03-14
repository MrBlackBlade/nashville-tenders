#include <check_idle.hpp>

extern Texture s_player_texture_idle;
extern Texture b_player_texture_idle;

void check_idle_s(Sprite& player)
{
	// switching between different idle frames
	if (s_idle && frame_counter % 16 == 0)
		// the 16 will be a parameter to adjust the animation speed
	{
		player.setTexture(s_player_texture_idle);
		player.setTextureRect(IntRect(s_idle_ind * s_sprite_size_idle, 0, s_sprite_size_idle, 51));
		s_idle_ind++;
		s_idle_ind %= s_anims;

		// breaking the idle state
		if (Keyboard::isKeyPressed(Keyboard::Key::W)
			|| Keyboard::isKeyPressed(Keyboard::Key::A)
			|| Keyboard::isKeyPressed(Keyboard::Key::S)
			|| Keyboard::isKeyPressed(Keyboard::Key::D))
			s_idle = false;
	}
} //Small player

void check_idle_b(Sprite& player)
{
	// switching between different idle frames
	if (b_idle && frame_counter % 16 == 0)
		// the 16 will be a parameter to adjust the animation speed
	{
		player.setTexture(b_player_texture_idle);
		player.setTextureRect(IntRect(b_idle_ind * b_sprite_size_idle, 0, b_sprite_size_idle, 51));
		b_idle_ind++;
		b_idle_ind %= b_anims_idle;

		// breaking the idle state
		if (Keyboard::isKeyPressed(Keyboard::Key::W)
			|| Keyboard::isKeyPressed(Keyboard::Key::A)
			|| Keyboard::isKeyPressed(Keyboard::Key::S)
			|| Keyboard::isKeyPressed(Keyboard::Key::D))
			b_idle = false;
	}
} //Big player