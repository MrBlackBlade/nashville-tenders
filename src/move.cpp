#include <move.hpp>
#include <iostream>

 extern Texture s_player_texture_run;
 extern Texture s_player_texture_idle;
 extern Texture b_player_texture_run;
 extern Texture b_player_texture_idle;

void move_s(Sprite& player, Keyboard::Key key)
{
	if (Keyboard::isKeyPressed(key))
	{
		if (Keyboard::isKeyPressed(s_player_binds[3]) && Keyboard::isKeyPressed(s_player_binds[1]))
		{
			if (s_velocity > 0)
				s_velocity -= 3;
			
			if (s_velocity < 0)
				s_velocity += 3;

			if (s_velocity == 0)
				s_idle = true;
		}

		else if (key == s_player_binds[1])
		{
			player.setScale(-s_player_scale, s_player_scale);
			player.setOrigin(player.getLocalBounds().width, 0);

			if (s_velocity >= -s_velocity_max)
				s_velocity -= 3;
		}

		else if (key == s_player_binds[3])
		{
			player.setScale(s_player_scale, s_player_scale);
			player.setOrigin(0, 0);

			if (s_velocity <= s_velocity_max)
				s_velocity += 3;
		}
	}

	else
	{
		if (s_velocity > 0)
			s_velocity -= 3;

		if (s_velocity < 0)
			s_velocity += 3;

		if (s_velocity == 0)
			s_idle = true;
	}

	if (frame_counter % 14 == 0)
	{	
		if (s_velocity) 
		{
			player.setTexture(s_player_texture_run);
			player.setTextureRect(IntRect(s_run_ind * s_sprite_size_run, 0, s_sprite_size_run - .5f, 51));

			s_run_ind++;
			s_run_ind %= s_anims;
		}
	}
	std::cout << "s_velocity: " << s_velocity << std::endl;
	player.move(s_velocity / 10.f, 0);
} // Small player

void move_b(Sprite& player, Keyboard::Key key)
{
	if (Keyboard::isKeyPressed(key))
	{
		if (Keyboard::isKeyPressed(b_player_binds[3]) && Keyboard::isKeyPressed(b_player_binds[1]))
		{
			if (b_velocity > 0)
				b_velocity -= 3;

			if (b_velocity < 0)
				b_velocity += 3;

			if (b_velocity == 0)
				b_idle = true;
		}

		else if (key == b_player_binds[1])
		{
			player.setScale(-b_player_scale, b_player_scale);
			player.setOrigin(player.getLocalBounds().width, 0);

			if (b_velocity >= -b_velocity_max)
				b_velocity -= 3;
		}

		else if (key == b_player_binds[3])
		{
			player.setScale(b_player_scale, b_player_scale);
			player.setOrigin(0, 0);

			if (b_velocity <= b_velocity_max)
				b_velocity += 3;
		}
	}

	else
	{
		if (b_velocity > 0)
			b_velocity -= 3;

		if (b_velocity < 0)
			b_velocity += 3;

		if (b_velocity == 0)
			b_idle = true;
	}

	if (frame_counter % 14 == 0)
	{
		if (b_velocity)
		{
			player.setTexture(b_player_texture_run);
			player.setTextureRect(IntRect(b_run_ind * b_sprite_size_run, 0, b_sprite_size_run, 64));

			b_run_ind++;
			b_run_ind %= b_anims_run;
		}
	}
	std::cout << "b_velocity: " << b_velocity << std::endl;
	player.move(b_velocity / 10.f, 0);
} // Big player