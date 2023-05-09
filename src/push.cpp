#include <push.hpp>

bool push(Pair_Player& p_pair, Pair_Object& o_pair)
{
	auto& sprite = *p_pair.sprite;
	auto& p_obj	 = *p_pair.obj;
	auto& shape	 = *o_pair.shape;
	auto& o_obj	 = *o_pair.obj;

	// make sure that the big player is pushing the box only
	if (p_obj.id != 1 || o_obj.id != Object::box)
		return false;

	// Keep the player in bounds (right)
	if (out_of_bounds(o_pair) && o_obj.velocity.x > 0.f)
	{
		o_obj.position.x = Config::RES_SIZE - sprite.getGlobalBounds().width;

		// Apply motion
		o_obj.velocity += o_obj.acceleration;
		o_obj.position += o_obj.velocity;
		sprite.setPosition(o_obj.position);
	}

	// Keep the player in bounds (left)
	if (out_of_bounds(o_pair) && o_obj.velocity.x < 0.f)
	{
		o_obj.position.x = 0;

		// Apply motion
		o_obj.velocity += o_obj.acceleration;
		o_obj.position += o_obj.velocity;
		sprite.setPosition(o_obj.position);
	}

	if (collision(p_pair, o_pair) == CollisionType::box)
	{
		animate(p_pair, Animation::push);

		if (!out_of_bounds(o_pair))
		{
			// left collision
			if (p_obj.velocity.x > 0.f)
			{
				o_obj.position.x++;

				shape.setPosition(o_obj.position);
				return true;
			}

			// right collision
			if (p_obj.velocity.x < 0.f)
			{
				o_obj.position.x--;

				shape.setPosition(o_obj.position);
				return true;
			}
		}
	}

	return false;
}