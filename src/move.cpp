#include <move.hpp>

extern Texture s_player_texture_run;
extern Texture s_player_texture_idle;
extern Texture b_player_texture_run;
extern Texture b_player_texture_idle;

void move(Sprite& player, Player& obj, Keyboard::Key key)
{
	if (Keyboard::isKeyPressed(key))
	{
		if (Keyboard::isKeyPressed(obj.keybinds[3]) && Keyboard::isKeyPressed(obj.keybinds[1]))
		{
			if (obj.velocity > 0)
				obj.velocity -= 3;
			
			if (obj.velocity < 0)
				obj.velocity += 3;

			if (obj.velocity == 0)
				obj.idle = true;
		}

		else if (key == obj.keybinds[1])
		{
			player.setScale(-obj.player_scale, obj.player_scale);
			player.setOrigin(player.getLocalBounds().width, 0);

			if (obj.velocity >= -obj.velocity_max)
				obj.velocity -= 3;
		}

		else if (key == obj.keybinds[3])
		{
			player.setScale(obj.player_scale, obj.player_scale);
			player.setOrigin(0, 0);

			if (obj.velocity <= obj.velocity_max)
				obj.velocity += 3;
		}
	}

	else
	{
		if (obj.velocity > 0)
			obj.velocity -= 3;

		if (obj.velocity < 0)
			obj.velocity += 3;

		if (obj.velocity == 0)
			obj.idle = true;
	}

	if (frame_counter % 14 == 0)
	{	
		if (obj.velocity) 
		{
			player.setTexture
			(
				(obj.id == 0) ? s_player_texture_run : b_player_texture_run
			);

			player.setTextureRect
			(
				IntRect
				(
				obj.run_ind * obj.sprite_size_run, 0,
				obj.sprite_size_run - .5f, 51
				)
			);

			obj.run_ind++;
			obj.run_ind %= obj.anims_run;
		}
	}

	std::cout << ((obj.id == 0) ? "s_velocity: " : "b_velocity: ") << obj.velocity << std::endl;
	player.move(obj.velocity / 10.f, 0);
}