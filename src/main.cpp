#include <SFML\Graphics.hpp>
#include <iostream>
#include <move.hpp>
#include <get_key_pressed.hpp>
#include <render.hpp>
#include <check_idle.hpp>
#include <Config.hpp>
#include <setup.hpp>
#include <getXposition.hpp>
#include <collision.hpp>
		  
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

Player s_obj (/*idle_ind*/ 0,/*run_ind*/ 0,/*jump_ind*/ 0,/*scale*/ 1,/*size_run*/ 40,/*sizeH_run*/ 50,/*size_idle*/ 28,/*sizeH_idle*/ 50,
 /*size_jump*/ 29,/*sizeH_jump*/ 50,/*anims_idle*/ 4,/*anims_run*/ 4,/*anims_jump*/ 4,/*velocityX*/ 0,/*MAXvelocityX*/ 40,/*ID*/ 0,/*isIdle*/ true);

Player b_obj (/*idle_ind*/ 0,/*run_ind*/0,/*jump_ind*/ 0,/*scale*/ 1,/*size_run*/ 64,/*sizeH_run*/ 64,/*size_idle*/ 64,/*sizeH_idle*/64,
 /*size_jump*/ 29,/*sizeH_jump*/ 64,/*anims_idle*/ 6,/*anims_run*/ 4,/*anims_jump*/ 4,/*velocityX*/ 0,/*MAXvelocityX*/ 25,/*ID*/ 1,/*isIdle*/ true);

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

		check_idle(s_player, s_obj);
		check_idle(b_player, b_obj);

		move(s_player, s_obj, get_key_pressed_s());
		move(b_player, b_obj, get_key_pressed_b());

		collision(s_player, platform_s);
		render(window, s_player, b_player, platform_s);
	}
	system("pause");
	return EXIT_SUCCESS;
}