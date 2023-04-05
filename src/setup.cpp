#include <setup.hpp>

extern Texture       s_player_texture_idle;
extern Texture       s_player_texture_run;
extern Texture		 s_player_texture_jump;
extern Texture		 s_player_texture_collision;

extern Texture       b_player_texture_idle;
extern Texture       b_player_texture_run;

extern Texture		 platform_texture;
extern Sprite		 platform_s;

extern Texture		 bg_texture;
extern Sprite		 background;

extern Sprite        s_player;
extern Sprite        b_player;
extern Player        s_obj;
extern Player        b_obj;
extern Clock         clock_var;
extern RenderWindow  window;

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
	background.setTextureRect(IntRect(0, 0, 1728, RES_SIZE));
	background.setScale(2, 2);
	background.setPosition(-576,-1200);

	platform_s.setTextureRect(IntRect(0, 0, 1000, 32));
	platform_s.setScale(1, 1);
	platform_s.setPosition(0, RES_SIZE - 20);

	s_player.setPosition(70, RES_SIZE - 200);


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
	b_player.setPosition(0, RES_SIZE - 200 );

	// checking if textures loaded
	if (!b_player_texture_idle.loadFromFile("resources\\big_idle_animation.png"))
		exit(1);
	if (!b_player_texture_run.loadFromFile("resources\\big_run.png"))
		exit(1);
}