#include <Config.hpp>

namespace Config
{
	const sf::Uint16 RES_SIZE = 900;
	sf::Uint16 frame_counter = 0;

	const sf::Keyboard::Key keybinds[2][4]
	{
		// small player keybinds
		{
			sf::Keyboard::Up   ,
			sf::Keyboard::Left ,
			sf::Keyboard::Down ,
			sf::Keyboard::Right
		},

		// big player keybinds
		{
			sf::Keyboard::W	   ,
			sf::Keyboard::A	   ,
			sf::Keyboard::S	   ,
			sf::Keyboard::D
		}
	};

	bool door_opened  = false;
	bool lever_pushed = false;

	// could add an array of pairs for multiple levers/buttons etc
	Pair_Player				small      { &s_player, &s_obj };
	Pair_Player				big        { &b_player, &b_obj };
	Pair_Object				pBox       { &box     , &box_obj };
	Pair_Object				pGround    { &ground  , &ground_obj };
	Pair_Object				pButton    { &button  , &button_obj };
	Pair_Object				pChicken   { &chicken , &chicken_obj};
	Pair_Object				pDoor      { &door , &door_obj};
	Pair_Object				pElevator  { &elevator , &elevator_obj};
	Pair_Object				pLever     { &lever , &lever_obj};
	Pair_Object				pPlatform  { &platform , &platform_obj};

	Pair_Object*			objects[OBJECTS] { &pGround, &pBox, &pButton, &pChicken, &pDoor, &pElevator, &pLever, &pPlatform };
	Pair_Player*            players[PLAYERS] { &small, &big };

}