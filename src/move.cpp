#include <move.hpp>
#include <iostream>

 extern Texture player_texture_run;
 extern Texture player_texture_idle;

void move(Sprite& player, Keyboard::Key key)
{
	if (Keyboard::isKeyPressed(key))
	{
		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::A))
		{
			if (velocity > 0) {
				velocity -= 3;
			}
			if (velocity < 0) {
				velocity += 3;
			}
			if (velocity == 0) {
				idle = true;
			}
		}
		else if (key == Keyboard::A)
		{
			player.setScale(-player_scale, player_scale);
			player.setOrigin(player.getLocalBounds().width, 0);
			if (velocity >= -60) {
				velocity -= 3;
			}
		}
		else if (key == Keyboard::D)
		{
			player.setScale(player_scale, player_scale);
			player.setOrigin(0, 0);
			if (velocity <= 60) {
				velocity += 3;
			}
		}

	}
	else
	{
		if (velocity > 0) {
			velocity -= 3;
		}
		if (velocity < 0) {
			velocity += 3;
		}
		if (velocity == 0) {
			idle = true;
		}
	}

	if (frame_counter % 14 == 0)
	{	
		if (velocity != 0) {
			player.setTexture(player_texture_run);
			player.setTextureRect(IntRect(run_animation_indicator * 40, 0, 39.5, 51));
			run_animation_indicator++;
			run_animation_indicator %= 4;
		}
	}
	//std::cout << "velocity: " << velocity << std::endl;
	player.move((float)velocity / 10, 0);
}