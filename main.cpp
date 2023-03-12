#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstdint>
using namespace sf;

const std::uint16_t RES_SIZE = 850;		

std::int32_t 
// 0 for first sprite, 1 for second etc...
idle_animation_indicator = 0,
run_animation_indicator = 0,	

// to adjust the animation speed
frame_counter = 0,

// sprite size multiplier
player_scale = 3;

bool idle = true;

int main()
{
	Clock clock;

	// (width, height), window name, window type
	RenderWindow window(VideoMode(RES_SIZE, RES_SIZE),
	"The Promised Chickenland",
	Style::Default);

	window.setFramerateLimit(60);

	Texture player_texture_idle;
	player_texture_idle.loadFromFile("resources\\small_idle_animation.png");

	Texture player_texture_run;
	player_texture_run.loadFromFile("resources\\small_run.png");

	Sprite player(player_texture_idle);
	player.setScale(player_scale, player_scale);

	// weird positioning shit
	player.setPosition(0, RES_SIZE - 152);

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
		if (idle && frame_counter % 16 == 0)
		// the 16 will be a parameter to adjust the animation speed
		{
			player.setTexture(player_texture_idle);
			player.setTextureRect(IntRect(idle_animation_indicator * 28, 0, 28, 51));
			idle_animation_indicator++;
			idle_animation_indicator %= 4;

			// breaking the idle state
			if (Keyboard::isKeyPressed(Keyboard::Key::W)
				|| Keyboard::isKeyPressed(Keyboard::Key::A)
				|| Keyboard::isKeyPressed(Keyboard::Key::S)
				|| Keyboard::isKeyPressed(Keyboard::Key::D))
				idle = false;
		}


		// this will be put into a function starting line 73 till 131
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
			
			// to prevent mirroring
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

			// to prevent mirroring
			player.setOrigin(0, 0);

			idle = true;
		}

		// change the bg color
		window.RenderTarget::clear(Color(130, 130, 150, 255));

		window.draw(player);
		window.display();

		// for the animation speed
		frame_counter++;
		// closest divisible number by 16 to 100
		frame_counter%=96;
	}
	return EXIT_SUCCESS;
}