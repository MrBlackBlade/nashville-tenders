#include <SFML\Graphics.hpp>
#include <iostream>
#include <move.hpp>
#include <get_key_pressed.hpp>
#include <render.hpp>
#include <check_idle.hpp>
#include <Config.hpp>
#include <setup.hpp>
#include <getXposition.hpp>
		  
using namespace sf;
using namespace Config;

extern float velocity_y;
extern float gravity;
extern bool isJumping;

Texture platform_texture;
Sprite platform_s(platform_texture);

Texture s_player_texture_jump;
Texture s_player_texture_idle;
Texture s_player_texture_run;
Sprite  s_player(s_player_texture_idle);

Texture b_player_texture_idle;
Texture b_player_texture_run;
Sprite  b_player(b_player_texture_idle);

Player  s_obj (0, 0, 0, 1, 40, 28, 29, 4, 4, 4, 0, 40, 0, true);
Player  b_obj (0, 0, 0, 1, 64, 64, 29, 6, 4, 4, 0, 25, 1, true);

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
		sf::Thread thread(&getXposition, std::ref(s_player));
		thread.launch();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		getXposition(s_player);
		check_idle(s_player, s_obj);
		move(s_player, s_obj, get_key_pressed_s());

		if (s_player.getGlobalBounds().intersects(platform_s.getGlobalBounds()))
		{
			s_player.setPosition(getXposition(s_player).x, 800 - 32);

			gravity=0;
			velocity_y = 0;
		}
		else
		{
			gravity = 0.5;
		}
		//

		check_idle(b_player, b_obj);
		move(b_player, b_obj, get_key_pressed_b());

		render(window, s_player, b_player, platform_s);
	}
	system("pause");
	return EXIT_SUCCESS;
}