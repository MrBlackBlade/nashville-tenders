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
	//Clock clock;
	//
	//// (width, height), window name, window type
	//RenderWindow window(VideoMode(RES_SIZE, RES_SIZE),
	//"The Promised Chickenland",
	//Style::Default);
	//
	//window.setFramerateLimit(60);
	//
	//player_texture_idle.loadFromFile("resources\\small_idle_animation.png");
	//
	//player_texture_run.loadFromFile("resources\\small_run.png");
	//
	//Sprite player(player_texture_idle);
	//player.setScale(player_scale, player_scale);
	//
	//// weird positioning shit
	//player.setPosition(0, RES_SIZE - 152);
	//
	//// checking if textures loaded
	//if (!player_texture_idle.loadFromFile("resources\\small_idle_animation.png")) 
	//	return EXIT_FAILURE;													  
	//if (!player_texture_run.loadFromFile("resources\\small_run.png"))			  
		//return EXIT_FAILURE;

	// main game loop
	while (window.isOpen())
	{
		// measuring the framerate
		float time_init = clock_var.restart().asSeconds();
		float fps = 1.f / time_init;
		std::cout << fps << '\n';

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		check_idle(player);

		move(player, get_key_pressed(), velocity);
		
		render(window, player);
	}

	return EXIT_SUCCESS;
}