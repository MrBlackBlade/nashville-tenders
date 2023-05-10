#include <move.hpp>

void apply_motion(Pair_Player& pair)
{
	pair.obj->velocity += pair.obj->acceleration;
	pair.obj->position += pair.obj->velocity;
	pair.sprite->setPosition(pair.obj->position);
}

void apply_motion(Pair_Object& pair)
{
	pair.obj->velocity += pair.obj->acceleration;
	pair.obj->position += pair.obj->velocity;
	pair.shape->setPosition(pair.obj->position);
}

// For sprites
void move(Pair_Player& pair)
{
	auto&	   player = *pair.sprite;
	auto&	   obj	  = *pair.obj;
	const auto key	  = get_key_pressed(pair);

	// Decrementing the jump
	if (obj.jumping)
	{
		animate(pair, Animation::jump);
		obj.acceleration.y = .2f;

		apply_motion(pair);
	}

	// Pressing a button
	if (key != sf::Keyboard::Unknown)
	{
		// Up
		if (key == Config::keybinds[obj.id][0] && !obj.jumping)
		{
			animate(pair, Animation::jump);

			obj.jumping	   = true;
			obj.velocity.y = obj.id ? -2.f : -7.f;
		}

		// Left
		if (key == Config::keybinds[obj.id][1])
		{
			animate(pair, Animation::run);

			obj.acceleration.x = -.2f;

			// Rotate player to the left
			player.setScale(-obj.scale, obj.scale);
			player.setOrigin(player.getLocalBounds().width, 0);
		}

		// Down
		if (key == Config::keybinds[obj.id][2])
		{
			animate(pair, Animation::run);

			obj.acceleration.x = 0.f;
		}

		// Right
		if (key == Config::keybinds[obj.id][3])
		{
			animate(pair, Animation::run);

			obj.acceleration.x = .2f;

			// Rotate player to the right
			player.setScale(obj.scale, obj.scale);
			player.setOrigin(0, 0);
		}

		// Capping the velocity.x (+ve)
		if (obj.velocity.x > obj.velocity_max.x)
		{
			obj.velocity.x = obj.velocity_max.x;
		}

		// Capping the velocity.x (-ve)
		if (obj.velocity.x < -obj.velocity_max.x)
		{
			obj.velocity.x = -obj.velocity_max.x;
		}

		// Capping the acceleration (+ve)
		if (obj.acceleration.x > .2f)
		{
			obj.acceleration.x = .2f;
		}

		// Capping the acceleration (-ve)
		if (obj.acceleration.x < -.2f)
		{
			obj.acceleration.x = -.2f;
		}

		apply_motion(pair);
	}

	// Not pressing a button
	if (key == sf::Keyboard::Unknown)
	{
		// decelerate to the left
		if (obj.velocity.x > 0.f)
		{
			animate(pair, Animation::run);

			obj.acceleration.x = -.2f;
		}

		// decelerate to the right
		if (obj.velocity.x < 0.f)
		{
			animate(pair, Animation::run);

			obj.acceleration.x = .2f;
		}

		//  1.f is a tolerance value to check if the player "stopped" motion
		if (std::fabs(obj.velocity.x) < 1.f)
		{
			obj.velocity.x	   = 0.f;
			obj.acceleration.x = 0.f;
			obj.idle		   = true;
		}

		apply_motion(pair);
	}

	// Background movement
	if (obj.velocity.x > .5f)
	{
		background_1.move(-.2f, 0.f);
		background_2.move(-.3f, 0.f);
		background_3.move(-.5f, 0.f);
		background_4.move(-.7f, 0.f);
	}

	// Background movement
	if (obj.velocity.x < -.5f)
	{
		background_1.move(.2f, 0.f);
		background_2.move(.3f, 0.f);
		background_3.move(.5f, 0.f);
		background_4.move(.7f, 0.f);
	}

	// Keep the player in bounds (right)
	if (out_of_bounds(pair) && obj.velocity.x && obj.position.x > Config::RES_SIZE / 2)
	{
		obj.position.x = Config::RES_SIZE - player.getGlobalBounds().width;

		apply_motion(pair);
	}

	// Keep the player in bounds (left)
	if (out_of_bounds(pair) && obj.velocity.x && obj.position.x < Config::RES_SIZE / 2)
	{
		obj.position.x = 0;

		apply_motion(pair);
	}

	// Keep the player in bounds (down)
	if (obj.position.y > Config::RES_SIZE)
	{
		obj.position.y = Config::RES_SIZE - 50;
		obj.velocity.y = 0;

		apply_motion(pair);
	}
}