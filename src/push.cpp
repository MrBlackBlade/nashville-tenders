#include <push.hpp>
#include <iostream>

bool push(Pair_Player& p_pair, Pair_Object& o_pair)
{
	auto& sprite = *p_pair.sprite;
    auto& p_obj  = *p_pair.obj;
	auto& shape  = *o_pair.shape;
    auto& o_obj  = *o_pair.obj;

	// Keep the player in bounds (right)
    if (o_obj.position.x > (Config::RES_SIZE - shape.getGlobalBounds().width))
    {
        o_obj.position.x = Config::RES_SIZE - shape.getGlobalBounds().width;

        // Apply motion
        o_obj.velocity += o_obj.acceleration;
        o_obj.position += o_obj.velocity;
        shape.setPosition(o_obj.position);
    }

    // Keep the player in bounds (left)
    if (o_obj.position.x < 0)
    {
        o_obj.position.x = 0;

        // Apply motion
        o_obj.velocity += o_obj.acceleration;
        o_obj.position += o_obj.velocity;
        shape.setPosition(o_obj.position);
    }

	if (collision(p_pair, o_pair))
	{
		animate(p_pair, Animation::push);
		// left collision
		if (p_obj.velocity.x > 0.f)
		{
			//animate(p_pair, Animation::push);
			std::cout << "Pushing from left\n";
			o_obj.position.x++;

			shape.setPosition(o_obj.position);
			return true;
		}

		// right collision
		if (p_obj.velocity.x < 0.f)
		{
			//animate(p_pair, Animation::push);
			std::cout << "Pushing from right\n";
			o_obj.position.x--;

			shape.setPosition(o_obj.position);
			return true;
		}
	}

	return false;
}