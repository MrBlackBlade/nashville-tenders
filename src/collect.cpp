#include <collect.hpp>

bool collect(Pair_Player& p_pair, Pair_Object& o_pair)
{
	auto& player = *p_pair.sprite;
	auto& obj	 = *p_pair.obj;
	auto& shape	 = *o_pair.shape;
	auto& obj2	 = *o_pair.obj;

	// break if not a chicken
	if (obj2.id != Object::chicken1 && obj2.id != Object::chicken2 && obj2.id != Object::chicken3)
		return false;

	if (player.getGlobalBounds().intersects(shape.getGlobalBounds()))
	{
		Config::chicken_num++;
		play_sfx(SoundIndex::chicken_collect);
		animate(pChicken_counter);

		// ciken.unget(&narnia)
		obj2.position = _______narnia;
		shape.setPosition(obj2.position);

		return true;
	}

	return false;
}
