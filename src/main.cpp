#include <SFML\Graphics.hpp>
#include <animate.hpp>
#include <Animation.hpp>
#include <check_idle.hpp>
#include <collision.hpp>
#include <Config.hpp>
#include <get_key_pressed.hpp>
#include <move.hpp>
#include <Player.hpp>
#include <render.hpp>
#include <setup.hpp>

// background and platforms
extern sf::RectangleShape	ground;
extern sf::RectangleShape	box;
extern Player				box_obj;

// small player
extern sf::Sprite s_player;
extern Player s_obj;

// big player
extern sf::Sprite b_player;
extern Player b_obj;

// window
extern sf::RenderWindow window;

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

		check_idle(s_player, s_obj);
		check_idle(b_player, b_obj);

		move(s_player, s_obj, get_key_pressed(s_obj));
		move(b_player, b_obj, get_key_pressed(b_obj));
		move(box, box_obj);

		collision(s_player, s_obj, ground);
		collision(s_player, s_obj, box);
		collision(b_player, b_obj, ground);
		collision(b_player, b_obj, box);
		collision(box, box_obj, ground);

		render();
	}
	
	return EXIT_SUCCESS;
}