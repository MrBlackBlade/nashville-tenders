#include <setup.hpp>

// background and platforms
extern sf::Texture		 bg_texture;
extern sf::Sprite		 background;
extern sf::Texture		 platform_texture;
extern sf::Sprite		 platform;

// small player
extern sf::Texture       s_player_texture_idle;
extern sf::Texture       s_player_texture_run;
extern sf::Texture		 s_player_texture_jump;
extern sf::Sprite        s_player;
extern Player			 s_obj;

// big player
extern sf::Texture       b_player_texture_idle;
extern sf::Texture       b_player_texture_run;
extern sf::Texture		 b_player_texture_jump;
extern sf::Sprite        b_player;
extern Player			 b_obj;

// window
extern sf::RenderWindow  window;

void setup() 
{
	// set FPS
	window.setFramerateLimit(60);

	// background and platforms
	bg_texture.loadFromFile("resources/background.png");
	platform_texture.loadFromFile("resources/tile_1.png");

	if (!platform_texture.loadFromFile("resources/tile_1.png"))
		exit(1);
	if (!bg_texture.loadFromFile("resources/background.png"))
		exit(1);

	background.setTextureRect(sf::IntRect(0, 0, 1728, 1000));
	background.setScale(2, 2);
	background.setPosition(-576,-1300);

	platform.setTextureRect(sf::IntRect(0, 0, 10000, 32));
	platform.setScale(1, 1);
	platform.setPosition(0, Config::RES_SIZE - 20);

	// small player
	s_player_texture_jump.loadFromFile("resources/small_jump_animation.png");
	s_player_texture_idle.loadFromFile("resources/small_idle_animation.png");
	s_player_texture_run.loadFromFile("resources/small_run.png");

	if (!s_player_texture_jump.loadFromFile("resources/small_jump_animation.png"))
		exit(1);
	if (!s_player_texture_idle.loadFromFile("resources/small_idle_animation.png"))
		exit(1);
	if (!s_player_texture_run.loadFromFile("resources/small_run.png"))
		exit(1);

	s_player.setScale(s_obj.scale, s_obj.scale);
	s_obj.position =
	{
		s_player.getPosition().x,
		platform.getGlobalBounds().top - s_player.getGlobalBounds().height
	};
	s_player.setPosition(s_obj.position);

	// big player
	b_player_texture_jump.loadFromFile("resources/big_jump_animation.png");
	b_player_texture_idle.loadFromFile("resources/big_idle_animation.png");
	b_player_texture_run.loadFromFile("resources/big_run.png");

	if (!b_player_texture_jump.loadFromFile("resources/big_jump_animation.png"))
		exit(1);
	if (!b_player_texture_idle.loadFromFile("resources/big_idle_animation.png"))
		exit(1);
	if (!b_player_texture_run.loadFromFile("resources/big_run.png"))
		exit(1);

	b_player.setScale(b_obj.scale, b_obj.scale);
	b_obj.position =
	{
		b_player.getPosition().x,
		platform.getGlobalBounds().top - b_player.getGlobalBounds().height
	};
	b_player.setPosition(b_obj.position);
}