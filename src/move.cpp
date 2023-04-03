#include <move.hpp>

extern Texture s_player_texture_run;
extern Texture s_player_texture_idle;
extern Texture s_player_texture_jump;
extern Texture b_player_texture_run;
extern Texture b_player_texture_idle;

float jumpHeight = 15.0f;
float jumpSpeed = 0.05f;
float jumpAcceleration = 0.2f;
float jumpDistance = 0.0f;
bool isJumping = false;

float gravity = 0.05f;
float velocity_y = 0.0f;

void move(Sprite& player, Player& obj, Keyboard::Key key)
{
	if (Keyboard::isKeyPressed(key))
	{

		if (Keyboard::isKeyPressed(keybinds[obj.id][0]))
		{

			isJumping = true;

			jumpDistance = 0.0f;
		}
	}

	if (isJumping)
	{
		if (frame_counter % ((obj.id == 0) ? 18 : 14) == 0)
			{
				player.setTexture
				(
					(obj.id == 0) ? s_player_texture_jump : b_player_texture_run
				);

				player.setTextureRect
				(
					IntRect
					(
						obj.jump_ind * obj.sprite_size_jump, 0,
						obj.sprite_size_jump, 56
					)
				);

				obj.jump_ind++;
				obj.jump_ind %= obj.anims_jump;
			}

		float jumpAmount = jumpHeight * jumpSpeed * jumpAcceleration;
			jumpDistance += jumpAmount;
		player.move(0, -jumpAmount);
		jumpSpeed += jumpAcceleration;
		if (jumpDistance >= jumpHeight)
		{
			isJumping = false;
			jumpSpeed = 5.0f;
		}
	}
	else

		velocity_y += gravity;
		player.move(0, velocity_y);






		if (Keyboard::isKeyPressed(key))
		{
			if (Keyboard::isKeyPressed(keybinds[obj.id][3]) && Keyboard::isKeyPressed(keybinds[obj.id][1]))
			{
				if (obj.velocity > 0)
					obj.velocity -= 2;

				if (obj.velocity < 0)
					obj.velocity += 2;

				if (obj.velocity == 0)
					obj.idle = true;
			}

			else if (key == keybinds[obj.id][1])
			{
				player.setScale(-obj.player_scale, obj.player_scale);
				player.setOrigin(player.getLocalBounds().width, 0);

				if (obj.velocity >= -obj.velocity_max)
					obj.velocity -= 2;
			}

			else if (key == keybinds[obj.id][3])
			{
				player.setScale(obj.player_scale, obj.player_scale);
				player.setOrigin(0, 0);

				if (obj.velocity <= obj.velocity_max)
					obj.velocity += 2;
			}
		}

		else
		{
			if (obj.velocity > 0)
				obj.velocity -= 2;

			if (obj.velocity < 0)
				obj.velocity += 2;

			if (obj.velocity == 0)
				obj.idle = true;
		}

		if (frame_counter % ((obj.id == 0) ? 14 : 14) == 0)
		{
			if (obj.velocity &&  velocity_y == 0 )
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
						obj.sprite_size_run - .5f, 50
					)
				);

				obj.run_ind++;
				obj.run_ind %= obj.anims_run;
			}
		}
		if (Keyboard::isKeyPressed(key))
		{
			if(isJumping)

				if(Keyboard::isKeyPressed(keybinds[obj.id][1]) && Keyboard::isKeyPressed(keybinds[obj.id][3]))
			{
				player.setTextureRect
				(
					IntRect
					(
						obj.jump_ind* obj.sprite_size_jump, 0,
						obj.sprite_size_jump, 56
					)
				);

				obj.jump_ind++;
				obj.jump_ind %= obj.anims_jump;
			}
		}
		std::cout << ((obj.id == 0) ? "s_velocity: " : "b_velocity: ") << obj.velocity << std::endl;
		player.move(obj.velocity / 10.f, 0);
	
}