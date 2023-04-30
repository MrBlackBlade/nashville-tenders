#include <check_idle.hpp>

void check_idle(Pair_Player& pair)
{
	auto& player = *pair.sprite;
	auto& obj = *pair.obj;

	if (obj.idle)
	{
		animate(pair, Animation::idle);

		// breaking the idle state
		for ( size_t i = 0; i < 4; i++ )
			if ( Config::keybinds[obj.id][i] == get_key_pressed(pair) )
				obj.idle = false;
	}
}