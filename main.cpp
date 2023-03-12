#include <SFML\Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace sf;

const unsigned RES_SIZE = 850;

short idle_animation_indicator = 0, run_animation_indicator = 0, frame_counter = 0;
int player_scale = 3;

bool idle = true;

int main()
{
	Clock clock;
	RenderWindow window(VideoMode(RES_SIZE, RES_SIZE), "The Promised Chickenland", Style::Default);

	window.setFramerateLimit(60);

	Texture player_texture_idle;
	player_texture_idle.loadFromFile("resources\\small_idle_animation.png");
	Texture player_texture_run;
	player_texture_run.loadFromFile("resources\\small_run.png");

	Sprite player(player_texture_idle);
	player.setScale(player_scale, player_scale);
	player.setPosition(0, RES_SIZE - 152);


	if (!player_texture_idle.loadFromFile("resources\\small_idle_animation.png"))
		return EXIT_FAILURE;
	if (!player_texture_run.loadFromFile("resources\\small_run.png"))
		return EXIT_FAILURE;

	while (window.isOpen())
	{
		// initial time
		float time_init = clock.restart().asSeconds();
		float fps = 1.f / time_init;

		std::cout << fps << '\n';

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//idle = true;

		if (idle && frame_counter % 16 == 0)
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
				player.setTexture(player_texture_run);
				player.setTextureRect(IntRect(run_animation_indicator * 39.5, 0, 39.5, 51));
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

		window.RenderTarget::clear(Color(130, 130, 150, 255));
		window.draw(player);
		window.display();
		frame_counter++;
	}
	return EXIT_SUCCESS;
}