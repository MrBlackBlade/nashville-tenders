#include <SFML\Graphics.hpp>
#include <iostream>
#include <move.hpp>
#include <get_key_pressed.hpp>
#include <render.hpp>
#include <check_idle.hpp>
#include <Config.hpp>
#include <setup.hpp>
		  
using namespace sf;
using namespace Config;

Texture s_player_texture_idle;
Texture s_player_texture_run;
Sprite  s_player(s_player_texture_idle);

Texture b_player_texture_idle;
Texture b_player_texture_run;
Sprite  b_player(b_player_texture_idle);

Player  s_obj (0, 0, 1, 40, 28, 4, 4, 0, 40, 0, true);
Player  b_obj (0, 0, 1, 64, 64, 6, 4, 0, 25, 1, true);

Clock clock_var;
RenderWindow window(VideoMode(RES_SIZE, RES_SIZE),
"The Promised Chickenland",
Style::Default);

int main()
{
	setup();

	// main game loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		check_idle(s_player, s_obj);
		move(s_player, s_obj, get_key_pressed_s());

		//

		check_idle(b_player, b_obj);
		move(b_player, b_obj, get_key_pressed_b());

		render(window, s_player, b_player);
	}

	// freeing the dynamic memory allocated to the keybinds 2D array
	delete[] keybinds[0];
	delete[] keybinds[1];
	
	return EXIT_SUCCESS;
}