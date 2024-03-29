#include <animate.hpp>
#include <Animation.hpp>
#include <check_idle.hpp>
#include <check_lever.hpp>
#include <collect.hpp>
#include <collision.hpp>
#include <Config.hpp>
#include <get_key_pressed.hpp>
#include <levels.hpp>
#include <menu.hpp>
#include <move.hpp>
#include <Object.hpp>
#include <out_of_bounds.hpp>
#include <Pair.hpp>
#include <Player.hpp>
#include <push.hpp>
#include <render.hpp>
#include <setup.hpp>
#include <SFML/Graphics.hpp>
#include <sound_system.hpp>

int main()
{
	setup();
	setup_menu();

	// main game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			// menu navigation
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					moveUp();
				if (event.key.code == sf::Keyboard::Down)
					moveDown();

				if (event.key.code == sf::Keyboard::Enter)
				{
					if (Config::menu_selection == 0)
						Config::menu_status = 0;

					if (Config::menu_selection == 1)
						Config::menu_status = -1;
				}
			}
		}

		// pressed "Play"
		if (Config::menu_status == 0)
		{
			caller();
		}

		// player idle checking and motion
		for (size_t player = 0; player < PLAYERS; player++)
		{
			using Config::players;
			check_idle(*players[player]);
			move(*players[player]);
		}

		// obstacle animations
		for (size_t object = 0; object < OBJECTS; object++)
		{
			using Config::objects;
			animate(*objects[object]);
		}

		// player to obstacle collision
		for (size_t player = 0; player < PLAYERS; player++)
		{
			using Config::players, Config::objects;
			for (size_t object = 0; object < OBJECTS; object++)
			{
				push(*players[player], *objects[object]);
				collision(*players[player], *objects[object]);
				collect(*players[player], *objects[object]);
			}
		}

		// ground obstacle collision
		for (size_t object = 1; object < OBJECTS; object++)
		{
			using Config::objects;
			collision(*objects[object], *objects[0]);
		}

		// obstacle to obstacle collision
		for (size_t object = 1; object < OBJECTS - 1; object++)
		{
			using Config::objects;
			collision(*objects[object], *objects[object + 1]);
		}

		// render the changes that happened in the last frame
		render();
	}
	return EXIT_SUCCESS;
}