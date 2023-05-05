#include <Config.hpp>

namespace Config
{
	const sf::Uint16 RES_SIZE     = 900;
	sf::Uint16 frame_counter      = 0;
	sf::Uint16 game_status		  = 1;
	sf::Uint16 lv1_chicken_count  = 0;
	sf::Uint16 lv2_chicken_count  = 0;
	sf::Uint16 lv3_chicken_count  = 0;

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

	bool door1_opened  = false;
	bool lever1_pushed = false;

	bool door2_opened = false;
	bool lever2_pushed = false;

	bool door3_opened = false;
	bool lever3_pushed = false;

	Pair_Player				small      { &s_player, &s_obj };
	Pair_Player				big        { &b_player, &b_obj };

	Pair_Object				pBox			 { &box     , &box_obj };
	Pair_Object				pGround			 { &ground  , &ground_obj };
	Pair_Object				pButton1		 { &button1  , &button1_obj };
	Pair_Object				pButton2		 { &button2  , &button2_obj };
	Pair_Object				pButton3		 { &button3  , &button3_obj };
	Pair_Object				pChicken1		 { &chicken1 , &chicken1_obj};
	Pair_Object				pChicken2		 { &chicken2 , &chicken2_obj};
	Pair_Object				pChicken3		 { &chicken3 , &chicken3_obj};
	Pair_Object				pDoor1			 { &door1 , &door1_obj};
	Pair_Object				pDoor2			 { &door2 , &door2_obj };
	Pair_Object				pDoor3			 { &door3 , &door3_obj };
	Pair_Object				pElevator1		 { &elevator1 , &elevator1_obj};
	Pair_Object				pElevator2		 { &elevator2 , &elevator2_obj };
	Pair_Object				pElevator3		 { &elevator3 , &elevator3_obj };
	Pair_Object				pLever1			 { &lever1 , &lever1_obj };
	Pair_Object				pLever2			 { &lever2 , &lever2_obj };
	Pair_Object				pLever3			 { &lever3 , &lever3_obj };
	Pair_Object				pPlatform	     { &platform , &platform_obj};

	Pair_Object*			objects[OBJECTS] { &pGround, &pButton1, &pButton2, &pButton3, &pBox, &pChicken1, &pChicken2, &pChicken3, &pDoor1, &pDoor2, &pDoor3, &pElevator1, &pElevator2, &pElevator3, &pLever1, &pLever2, &pLever3, &pPlatform };
	Pair_Player*            players[PLAYERS] { &small, &big };

}