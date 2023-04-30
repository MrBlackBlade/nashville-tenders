#include <check_idle.hpp>

void check_idle(Pair& pair)
{
	auto& player = *pair.sprite;
	auto& obj = *pair.obj;

	if (obj.idle)
	{
		animate(player, obj, Animation::idle);

		// breaking the idle state
		for ( size_t i = 0; i < 4; i++ )
			if ( Config::keybinds[obj.id][i] == get_key_pressed(obj) )
				obj.idle = false;
	}
}