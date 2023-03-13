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

  Texture player_texture_idle;
  Texture player_texture_run;
  Clock clock_var;
  RenderWindow window(VideoMode(RES_SIZE, RES_SIZE),
	 "The Promised Chickenland",
	  Style::Default);
  Sprite player(player_texture_idle);

int main()
{
	setup();
	// main game loop
	while (window.isOpen())
	{
		// measuring the framerate
		float time_init = clock_var.restart().asSeconds();
		float fps = 1.f / time_init;
		//std::cout << fps << '\n';

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		check_idle(player);

		move(player, get_key_pressed());

		render(window, player);
	}
	system("pause");
	return EXIT_SUCCESS;
}