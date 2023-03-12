#include <SFML\Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace sf;

const unsigned RES_SIZE = 850;		

int idle_animation_indicator = 0,   // 0 for first sprite, 1 for second etc...
run_animation_indicator = 0,		// 0 for first sprite, 1 for second etc...
frame_counter = 0,					// to adjust the speed of switching between each sprite animation
player_scale = 3;

bool idle = true;

int main()
{
	Clock clock;
	RenderWindow window(VideoMode(RES_SIZE, RES_SIZE), // (width, height)
	"The Promised Chickenland",						   // window name
	Style::Default);								   // window type

	window.setFramerateLimit(60);

	Texture player_texture_idle;
	player_texture_idle.loadFromFile("resources\\small_idle_animation.png");

	Texture player_texture_run;
	player_texture_run.loadFromFile("resources\\small_run.png");

	Sprite player(player_texture_idle);
	player.setScale(player_scale, player_scale);
	player.setPosition(0, RES_SIZE - 152);			 // weird positioning shit

	// checking if textures loaded
	if (!player_texture_idle.loadFromFile("resources\\small_idle_animation.png")) 
		return EXIT_FAILURE;													  
	if (!player_texture_run.loadFromFile("resources\\small_run.png"))			  
		return EXIT_FAILURE;

	// main game loop
	while (window.isOpen())
	{
		// measuring the framerate
		float time_init = clock.restart().asSeconds();
		float fps = 1.f / time_init;
		std::cout << fps << '\n';

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// switching between different idle frames
		if (idle && frame_counter % 16 == 0)	// the 16 will be a parameter for the 
												// function to adjust animation speed
		{
			player.setTexture(player_texture_idle);
			player.setTextureRect(IntRect(idle_animation_indicator * 28, 0, 28, 51));
			idle_animation_indicator++;
			idle_animation_indicator %= 4;

			if (Keyboard::isKeyPressed(Keyboard::Key::W)
				|| Keyboard::isKeyPressed(Keyboard::Key::A)
				|| Keyboard::isKeyPressed(Keyboard::Key::S)
				|| Keyboard::isKeyPressed(Keyboard::Key::D))
				idle = false;
		}


		// will be put into a function starting line 73 till 131
		if (Keyboard::isKeyPressed(Keyboard::Key::W))
		{
			if (frame_counter % 16 == 0)
			{
				player.setTexture(player_texture_run);
				player.setTextureRect(IntRect(run_animation_indicator * 39.5, 0, 39.5, 51));
				run_animation_indicator++;
				run_animation_indicator %= 4;
			}

			player.move(0, -4);
			idle = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::A))
		{
			if (frame_counter % 16 == 0)
			{
				player.setTextureRect(IntRect(run_animation_indicator * 39.5, 0, 39.5, 51));
				player.setTexture(player_texture_run);
				run_animation_indicator++;
				run_animation_indicator %= 4;
			}
			player.setScale(-player_scale, player_scale);
			player.move(-4, 0);
			player.setOrigin(player.getLocalBounds().width, 0);

			idle = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::S))
		{
			if (frame_counter % 16 == 0)
			{
				player.setTexture(player_texture_run);
				player.setTextureRect(IntRect(run_animation_indicator * 39.5, 0, 39.5, 51));
				run_animation_indicator++;
				run_animation_indicator %= 4;
			}

			player.move(0, 4);
			idle = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::D))
		{
			if (frame_counter % 16 == 0)
			{
				player.setTexture(player_texture_run);
				player.setTextureRect(IntRect(run_animation_indicator * 39.5, 0, 39.5, 51));
				run_animation_indicator++;
				run_animation_indicator %= 4;
			}

			player.setScale(player_scale, player_scale);
			player.move(4, 0);
			player.setOrigin(0, 0);
			idle = true;
		}

		// change the bg color
		window.RenderTarget::clear(Color(130, 130, 150, 255));

		window.draw(player);
		window.display();

		// for the animation speed
		frame_counter++;
	}
	return EXIT_SUCCESS;
}