#include <check_lever.hpp>

bool check_lever(Pair_Player& p_pair, Pair_Object& o_pair)
{
	auto&	   player = *p_pair.sprite;
	auto&	   obj	  = *p_pair.obj;
	auto&	   shape  = *o_pair.shape;
	auto&	   obj2	  = *o_pair.obj;

	const auto key	  = get_key_pressed(p_pair);

	// break if not a lever
	if (obj2.id != Object::lever1 && obj2.id != Object::lever2 && obj2.id != Object::lever3)
		return false;

	if (player.getGlobalBounds().intersects(shape.getGlobalBounds()))
		return true;

	return false;
}
