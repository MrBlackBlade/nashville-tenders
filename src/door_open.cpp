#include <door_open.hpp>

bool door_open(Pair_Object& o_pair)
{
	auto& shape  = *o_pair.shape;
	auto& obj   = *o_pair.obj;
	
	// make sure that the o_pair is now a door
	if (obj.id != Object::door1)
		return false;
	if (obj.id != Object::door2)
		return false;
	if (obj.id != Object::door3)
		return false;

	// door is open
	if (obj.anim_ind == 4)
		return true;

	return false;
}