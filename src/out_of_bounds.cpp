#include <out_of_bounds.hpp>

bool out_of_bounds(Pair_Player& pair)
{
	auto& obj    = *pair.obj;
	auto& sprite = *pair.sprite;

	return (obj.position.x > (Config::RES_SIZE - sprite.getGlobalBounds().width)) || (obj.position.x + sprite.getGlobalBounds().width < sprite.getGlobalBounds().width);
}

bool out_of_bounds(Pair_Object& pair)
{
	auto& obj = *pair.obj;
	auto& shape = *pair.shape;

	return (obj.position.x > (Config::RES_SIZE - shape.getGlobalBounds().width - 5.f)) || (obj.position.x + shape.getGlobalBounds().width < shape.getGlobalBounds().width + 5.f);
}