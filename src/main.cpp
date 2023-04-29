#include <SFML/Graphics.hpp>
#include <animate.hpp>
#include <Animation.hpp>
#include <check_idle.hpp>
#include <collision.hpp>
#include <Config.hpp>
#include <get_key_pressed.hpp>
#include <move.hpp>
#include <Player.hpp>
#include <Pair.hpp>
#include <render.hpp>
#include <setup.hpp>

int main()
{
	setup();

	// main game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// player idle checking and motion
		for (size_t player = 0; player < PLAYERS; player++)
		{
			using Config::players;
			check_idle(*players[player]->sprite, *players[player]->obj);
			move(*players[player]->sprite, *players[player]->obj, get_key_pressed(*players[player]->obj));
		}
		// obstacle gravity
		move(box, box_obj);

		// player to obstacle collision
		for (size_t player = 0; player < PLAYERS; player++)
		{
			using Config::players, Config::objects;
			for (size_t object = 0; object < OBJECTS; object++)
				collision(*players[player]->sprite, *players[player]->obj, *objects[object]);
		}
		// obstacle to obstacle collision
		collision(box, box_obj, ground);

		render();
	}
	
	return EXIT_SUCCESS;
}