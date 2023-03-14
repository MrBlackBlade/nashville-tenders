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
Sprite s_player(s_player_texture_idle);

Texture b_player_texture_idle;
Texture b_player_texture_run;
Sprite b_player(b_player_texture_idle);

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
		//// measuring the framerate
		//float time_init = clock_var.restart().asSeconds();
		//float fps = 1 / time_init;
		////std::cout << fps << '\n';

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		check_idle_s(s_player);
		move_s(s_player, get_key_pressed_s());

		//

		check_idle_b(b_player);
		move_b(b_player, get_key_pressed_b());

		render(window, s_player, b_player);
	}

	return EXIT_SUCCESS;
}