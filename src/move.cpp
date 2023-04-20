#include <move.hpp>

extern sf::Texture bg_texture;
extern sf::Sprite  background;

extern sf::Texture s_player_texture_run;
extern sf::Texture s_player_texture_idle;
extern sf::Texture s_player_texture_jump;

extern sf::Texture b_player_texture_run;
extern sf::Texture b_player_texture_idle;

float jumpHeight	    = 15.0f;
float jumpSpeed			= 0.05f;
float jumpAcceleration  = 0.2f;
float jumpDistance	    = 0.0f;
bool isJumping			= false;

float gravity = 0.05f;
float velocity_y = 0.0f;

void move(sf::Sprite& player, Player& obj, const sf::Keyboard::Key& key)
{
	if (sf::Keyboard::isKeyPressed(key))
	{
		if (sf::Keyboard::isKeyPressed(Config::keybinds[0][0]))
		{
			isJumping = true;
			jumpDistance = 0.0f;
		}
	}

	if (isJumping && obj.id == 0)
	{
		if (Config::frame_counter % ((obj.id == 0) ? 12 : 14) == 0)
			{
				player.setTexture
				(
					(obj.id == 0) ? s_player_texture_jump : b_player_texture_run
				);

				player.setTextureRect
				(
					sf::IntRect
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

	player.move ( 0, velocity_y );


		if (sf::Keyboard::isKeyPressed(key))
		{
			if (sf::Keyboard::isKeyPressed(Config::keybinds[obj.id][3]) && sf::Keyboard::isKeyPressed(Config::keybinds[obj.id][1]))
			{
				if (obj.velocity.x > 0)
					obj.velocity.x -= 2;

				if (obj.velocity.x < 0)
					obj.velocity.x += 2;

				if (obj.velocity.x == 0)
					obj.idle = true;
			}

			else if (key == Config::keybinds[obj.id][1])
			{
				player.setScale(-obj.player_scale, obj.player_scale);
				player.setOrigin(player.getLocalBounds().width, 0);

				if (obj.velocity.x >= -obj.velocity_max)
					obj.velocity.x -= 2;
			}

			else if (key == Config::keybinds[obj.id][3])
			{
				//background.move(-0.7, 0);
				player.setScale(obj.player_scale, obj.player_scale);
				player.setOrigin(0, 0);

				if (obj.velocity.x <= obj.velocity_max)
					obj.velocity.x += 2;
			}
		}

		else
		{
			if (obj.velocity.x > 0)
				obj.velocity.x -= 2;

			if (obj.velocity.x < 0)
				obj.velocity.x += 2;

			if (obj.velocity.x == 0)
				obj.idle = true;
		}

		if (Config::frame_counter % ((obj.id == 0) ? 14 : 14) == 0)
		{
			if (obj.velocity.x && velocity_y == 0 )
			{
				player.setTexture
				(
					(obj.id == 0) ? s_player_texture_run : b_player_texture_run
				);

				player.setTextureRect
				(
					sf::IntRect
					(
						obj.run_ind * obj.sprite_size_run, 0,
						obj.sprite_size_run - .5f, obj.sprite_sizeH_run
					)
				);

				obj.run_ind++;
				obj.run_ind %= obj.anims_run;
			}
		}
		if (sf::Keyboard::isKeyPressed(key))
		{
			if(isJumping)

				if(sf::Keyboard::isKeyPressed(Config::keybinds[obj.id][1]) && sf::Keyboard::isKeyPressed(Config::keybinds[obj.id][3]))
			{
				player.setTextureRect
				(
					sf::IntRect
					(
						obj.jump_ind* obj.sprite_size_jump, 0,
						obj.sprite_size_jump, obj.sprite_sizeH_jump
					)
				);

				obj.jump_ind++;
				obj.jump_ind %= obj.anims_jump;
			}
		}

		if (obj.velocity.x > 0.5)
			background.move(-0.7, 0);
		if (obj.velocity.x < 0)
			background.move(0.7, 0);

		std::cout << ((obj.id == 0) ? "s_velocity: " : "b_velocity: ") << obj.velocity.x << std::endl;
		player.move(obj.velocity.x / 10.f, 0);
	
}