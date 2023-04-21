#include <setup.hpp>

extern sf::Texture       s_player_texture_idle;
extern sf::Texture       s_player_texture_run;
extern sf::Texture		 s_player_texture_jump;
extern sf::Texture		 s_player_texture_collision;
extern sf::Texture       b_player_texture_idle;
extern sf::Texture       b_player_texture_run;
extern sf::Texture		 platform_texture;
extern sf::Sprite		 platform_s;
extern sf::Texture		 bg_texture;
extern sf::Sprite		 background;
extern sf::Sprite        s_player;
extern sf::Sprite        b_player;
extern Player			 s_obj;
extern Player			 b_obj;
extern sf::Clock         clock_var;
extern sf::RenderWindow  window;

void setup() 
{
	window.setFramerateLimit(60);

	bg_texture.loadFromFile("resources\\background.png");

	platform_texture.loadFromFile("resources\\tile_1.png");

	s_player_texture_collision.loadFromFile("resources\\small_collision_animation.png");
	s_player_texture_jump.loadFromFile("resources\\small_jump_animation.png");
	s_player_texture_idle.loadFromFile("resources\\small_idle_animation.png");
	s_player_texture_run.loadFromFile("resources\\small_run.png");
	s_player.setScale(s_obj.player_scale, s_obj.player_scale);

	// weird positioning shit
	background.setTextureRect(sf::IntRect(0, 0, 1728, 1000));
	background.setScale(2, 2);
	background.setPosition(-576,-1300);

	platform_s.setTextureRect(sf::IntRect(0, 0, 1000, 32));
	platform_s.setScale(1, 1);
	platform_s.setPosition(0, Config::RES_SIZE - 20);

	s_player.setPosition(s_obj.position);


	// checking if textures loaded
	if (!s_player_texture_idle.loadFromFile("resources\\small_idle_animation.png"))
		exit(1);
	if (!s_player_texture_run.loadFromFile("resources\\small_run.png"))
		exit(1);
	if (!platform_texture.loadFromFile("resources\\tile_1.png"))
		exit(1);
	if (!bg_texture.loadFromFile("resources\\background.png"))
		exit(1);

	b_player_texture_idle.loadFromFile("resources\\big_idle_animation.png");
	b_player_texture_run.loadFromFile("resources\\big_run.png");
	b_player.setScale(b_obj.player_scale, b_obj.player_scale);

	// weird positioning shit
	b_player.setPosition(b_obj.position);

	// checking if textures loaded
	if (!b_player_texture_idle.loadFromFile("resources\\big_idle_animation.png"))
		exit(1);
	if (!b_player_texture_run.loadFromFile("resources\\big_run.png"))
		exit(1);
}