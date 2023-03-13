#include <check_idle.hpp>
extern Texture player_texture_idle;

void check_idle(Sprite& player) {


	// switching between different idle frames
	if (idle && frame_counter % 16 == 0)
		// the 16 will be a parameter to adjust the animation speed
	{
		player.setTexture(player_texture_idle);
		player.setTextureRect(IntRect(idle_animation_indicator * 28, 0, 28, 51));
		idle_animation_indicator++;
		idle_animation_indicator %= 4;

		// breaking the idle state
		if (Keyboard::isKeyPressed(Keyboard::Key::W)
			|| Keyboard::isKeyPressed(Keyboard::Key::A)
			|| Keyboard::isKeyPressed(Keyboard::Key::S)
			|| Keyboard::isKeyPressed(Keyboard::Key::D))
			idle = false;
	}
}