#include <collision.hpp>

CollisionType collision(Pair_Player& p_pair, Pair_Object& o_pair)
{
	auto& player	= *p_pair.sprite;
	auto& obj		= *p_pair.obj;
	auto& shape		= *o_pair.shape;
	auto& obj2		= *o_pair.obj;

	auto  p_bounds	= player.getGlobalBounds();
	auto  s_bounds	= shape.getGlobalBounds();

	bool  intersect = p_bounds.intersects(s_bounds);
	bool  u_coll	= intersect && p_bounds.top <= s_bounds.top;
	bool  d_coll	= intersect && p_bounds.top - p_bounds.height >= s_bounds.top + s_bounds.height;
	bool  l_coll =
		intersect &&
		std::fabs(((p_bounds.left + p_bounds.width) / 2.f) - ((s_bounds.left + s_bounds.width) / 2.f)) <=
			(p_bounds.width + s_bounds.width) &&
		obj.velocity.x > 0.f && !u_coll;
	bool r_coll =
		intersect &&
		std::fabs(((p_bounds.left + p_bounds.width) / 2.f) - ((s_bounds.left + s_bounds.width) / 2.f)) <=
			(p_bounds.width + s_bounds.width) &&
		obj.velocity.x < 0.f && !u_coll;

	// collide from up
	if (u_coll && !d_coll && !l_coll && !r_coll)
	{
		// no collision physics with lever
		if (obj2.id == Object::lever1 || obj2.id == Object::lever2 || obj2.id == Object::lever3)
			return CollisionType::null;

		// no collision physics with chicken
		if (obj2.id == Object::chicken1 || obj2.id == Object::chicken2 || obj2.id == Object::chicken3)
			return CollisionType::null;

		// dont collide if the door is open
		if ((obj2.id == Object::door1 || obj2.id == Object::door2 || obj2.id == Object::door3) &&
			door_open(o_pair))
			return CollisionType::null;

		// do the collision physics
		obj.position = { player.getPosition().x, s_bounds.top - p_bounds.height };
		player.setPosition(obj.position);

		obj.velocity.y = 0;
		obj.jump_ind   = 0;
		obj.jumping	   = false;

		// collision physics with the button
		if (obj2.id == Object::button1 || obj2.id == Object::button2 || obj2.id == Object::button3)
		{
			return CollisionType::button;
		}

		// small player standing on the top of the box
		if (obj.id == 0 && obj2.id == Object::box &&
			push(*Config::players[1], *Config::objects[Object::box]))
		{
			// big player came from left
			if (Config::players[1]->obj->velocity.x > 0.f)
			{
				obj.position.x++;

				player.setPosition(obj.position);
				return CollisionType::null;
			}

			// big player came from left
			if (Config::players[1]->obj->velocity.x < 0.f)
			{
				obj.position.x--;

				player.setPosition(obj.position);
				return CollisionType::null;
			}
		}

		return CollisionType::null;
	}

	// collide from down
	if (!u_coll && d_coll && !l_coll && !r_coll)
	{
		// no collision physics with lever
		if (obj2.id == Object::lever1 || obj2.id == Object::lever2 || obj2.id == Object::lever3)
			return CollisionType::null;

		// no collision physics with chicken
		if (obj2.id == Object::chicken1 || obj2.id == Object::chicken2 || obj2.id == Object::chicken3)
			return CollisionType::null;

		// dont collide if the door is open
		if ((obj2.id == Object::door1 || obj2.id == Object::door2 || obj2.id == Object::door3) &&
			door_open(o_pair))
			return CollisionType::null;

		// do the collision physics
		obj.position = { player.getPosition().x, s_bounds.top + s_bounds.height };
		player.setPosition(obj.position);

		obj.velocity.y = 0;

		return CollisionType::null;
	}

	// collide from left
	if (!u_coll && !d_coll && l_coll && !r_coll)
	{
		// no collision physics with lever
		if (obj2.id == Object::lever1 || obj2.id == Object::lever2 || obj2.id == Object::lever3)
			return CollisionType::null;

		// no collision physics with chicken
		if (obj2.id == Object::chicken1 || obj2.id == Object::chicken2 || obj2.id == Object::chicken3)
			return CollisionType::null;

		// dont collide if the door is open
		if ((obj2.id == Object::door1 || obj2.id == Object::door2 || obj2.id == Object::door3) &&
			door_open(o_pair))
			return CollisionType::null;

		// do the collision physics
		obj.position = { s_bounds.left - p_bounds.width, player.getPosition().y };
		player.setPosition(obj.position);

		if (obj.id == 1 && obj2.id == Object::box)
			return CollisionType::box;

		return CollisionType::null;
	}

	// collide from right
	if (!u_coll && !d_coll && !l_coll && r_coll)
	{
		// no collision physics with lever
		if (obj2.id == Object::lever1 || obj2.id == Object::lever2 || obj2.id == Object::lever3)
			return CollisionType::null;

		// no collision physics with chicken
		if (obj2.id == Object::chicken1 || obj2.id == Object::chicken2 || obj2.id == Object::chicken3)
			return CollisionType::null;

		// dont collide if the door is open
		if ((obj2.id == Object::door1 || obj2.id == Object::door2 || obj2.id == Object::door3) &&
			door_open(o_pair))
			return CollisionType::null;

		// do the collision physics
		obj.position = { s_bounds.left + s_bounds.width, player.getPosition().y };
		player.setPosition(obj.position);

		if (obj.id == 1 && obj2.id == Object::box)
			return CollisionType::box;

		return CollisionType::null;
	}
}

CollisionType collision(Pair_Object& pair1, Pair_Object& pair2)
{
	auto& shape1	= *pair1.shape;
	auto& obj		= *pair1.obj;
	auto& shape2	= *pair2.shape;
	auto& obj2		= *pair2.obj;

	auto  s1_bounds = shape1.getGlobalBounds();
	auto  s2_bounds = shape2.getGlobalBounds();

	bool  intersect = s1_bounds.intersects(s2_bounds);

	bool  u_coll	= intersect && s1_bounds.top <= s2_bounds.top;
	bool  d_coll	= intersect && s1_bounds.top - s1_bounds.height >= s2_bounds.top + s2_bounds.height;
	bool  l_coll =
		intersect &&
		std::fabs(
			((s1_bounds.left + s1_bounds.width) / 2.f) - ((s2_bounds.left + s2_bounds.width) / 2.f)
		) <= (s1_bounds.width + s2_bounds.width) &&
		obj.velocity.x > 0.f && !u_coll;
	bool r_coll =
		intersect &&
		std::fabs(
			((s1_bounds.left + s1_bounds.width) / 2.f) - ((s2_bounds.left + s2_bounds.width) / 2.f)
		) <= (s1_bounds.width + s2_bounds.width) &&
		obj.velocity.x < 0.f && !u_coll;

	// collide from up
	if (u_coll && !d_coll && !l_coll && !r_coll)
	{
		// no collision physics between box and button
		if (obj.id == Object::box &&
			(obj2.id == Object::button1 || obj2.id == Object::button2 || obj2.id == Object::button3) &&
			intersect)
			return CollisionType::button;

		// no collision physics with chicken
		if (obj.id == Object::chicken1 || obj.id == Object::chicken2 || obj.id == Object::chicken3)
			return CollisionType::null;
		if (obj2.id == Object::chicken1 || obj2.id == Object::chicken2 || obj2.id == Object::chicken3)
			return CollisionType::null;

		// do the collision physics
		obj.position = { shape1.getPosition().x, s2_bounds.top - s1_bounds.height };
		shape1.setPosition(obj.position);

		obj.velocity.y = 0;

		if (obj.id == Object::box && (obj2.id == Object::elevator1 || obj2.id == Object::elevator2 ||
									  obj2.id == Object::elevator3))
			return CollisionType::box;

		return CollisionType::null;
	}

	// collide from down
	if (!u_coll && d_coll && !l_coll && !r_coll)
	{
		// no collision physics between box and button
		if (obj.id == Object::box &&
			(obj2.id == Object::button1 || obj2.id == Object::button2 || obj2.id == Object::button3) &&
			intersect)
			return CollisionType::button;

		// no collision physics with chicken
		if (obj.id == Object::chicken1 || obj.id == Object::chicken2 || obj.id == Object::chicken3)
			return CollisionType::null;
		if (obj2.id == Object::chicken1 || obj2.id == Object::chicken2 || obj2.id == Object::chicken3)
			return CollisionType::null;

		// do the collision physics
		obj.position = { shape1.getPosition().x, s2_bounds.top + s2_bounds.height };
		shape1.setPosition(obj.position);

		obj.velocity.y = 0;

		return CollisionType::null;
	}

	// collide from left
	if (!u_coll && !d_coll && l_coll && !r_coll)
	{
		// no collision physics between box and button
		if (obj.id == Object::box &&
			(obj2.id == Object::button1 || obj2.id == Object::button2 || obj2.id == Object::button3) &&
			intersect)
			return CollisionType::button;

		// no collision physics with chicken
		if (obj.id == Object::chicken1 || obj.id == Object::chicken2 || obj.id == Object::chicken3)
			return CollisionType::null;
		if (obj2.id == Object::chicken1 || obj2.id == Object::chicken2 || obj2.id == Object::chicken3)
			return CollisionType::null;

		// do the collision physics
		obj.position = { s2_bounds.left - s1_bounds.width, shape1.getPosition().y };
		shape1.setPosition(obj.position);

		return CollisionType::null;
	}

	// collide from right
	if (!u_coll && !d_coll && !l_coll && r_coll)
	{
		// no collision physics between box and button
		if (obj.id == Object::box &&
			(obj2.id == Object::button1 || obj2.id == Object::button2 || obj2.id == Object::button3) &&
			intersect)
			return CollisionType::button;

		// no collision physics with chicken
		if (obj.id == Object::chicken1 || obj.id == Object::chicken2 || obj.id == Object::chicken3)
			return CollisionType::null;
		if (obj2.id == Object::chicken1 || obj2.id == Object::chicken2 || obj2.id == Object::chicken3)
			return CollisionType::null;

		// do the collision physics
		obj.position = { s2_bounds.left + s2_bounds.width, shape1.getPosition().y };
		shape1.setPosition(obj.position);

		return CollisionType::null;
	}
}