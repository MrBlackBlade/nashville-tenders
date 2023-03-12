#include <move.hpp>

 extern Texture player_texture_run;
 extern Texture player_texture_idle;

void move(Sprite& player, Keyboard::Key key, std::int32_t velocity)
{
	if (Keyboard::isKeyPressed(key))
	{
		if (frame_counter % 16 == 0)
		{
			player.setTexture(player_texture_run);
			player.setTextureRect(IntRect(run_animation_indicator * 39.5, 0, 39.5, 51));
			run_animation_indicator++;
			run_animation_indicator %= 4;
		}

		switch (key)
		{
			// W
		case Keyboard::W:
			player.move(0, -velocity);
			break;

			// A
		case Keyboard::A:
			player.setScale(-player_scale, player_scale);
			player.move(-velocity, 0);
			player.setOrigin(player.getLocalBounds().width, 0);
			break;

			// S
		case Keyboard::S:
			player.move(0, velocity);
			break;

			// D
		case Keyboard::D:
			player.setScale(player_scale, player_scale);
			player.move(velocity, 0);
			player.setOrigin(0, 0);
			break;
		}

		idle = true;
	}
}