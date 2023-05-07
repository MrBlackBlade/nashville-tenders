#include <reset.hpp>

void reset()
{
	Config::door1_opened = false;
	Config::door2_opened = false;
	Config::door3_opened = false;

	Config::lever1_pushed = false;
	Config::lever2_pushed = false;
	Config::lever3_pushed = false;

	for (auto& object : Config::objects)
	{
		object->obj->anim_ind = 0;
		object->shape->setTextureRect(sf::IntRect(0, 0, object->obj->size_x, object->obj->size_y));
	}
}