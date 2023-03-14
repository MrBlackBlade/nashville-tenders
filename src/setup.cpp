#include <setup.hpp>

extern Texture s_player_texture_idle;
extern Texture s_player_texture_run;
extern Texture b_player_texture_idle;
extern Texture b_player_texture_run;
extern Sprite s_player;
extern Sprite b_player;
extern Clock clock_var;
extern RenderWindow window;

void setup() {
	// (width, height), window name, window type

	window.setFramerateLimit(60);

	s_player_texture_idle.loadFromFile("resources\\small_idle_animation.png");

	s_player_texture_run.loadFromFile("resources\\small_run.png");

	s_player.setScale(s_player_scale, s_player_scale);

	// weird positioning shit
	s_player.setPosition(0, RES_SIZE - 152);

	// checking if textures loaded
	if (!s_player_texture_idle.loadFromFile("resources\\small_idle_animation.png"))
		exit(1);
	if (!s_player_texture_run.loadFromFile("resources\\small_run.png"))
		exit(1);

	b_player_texture_idle.loadFromFile("resources\\big_idle_animation.png");

	b_player_texture_run.loadFromFile("resources\\big_run.png");

	b_player.setScale(b_player_scale, b_player_scale);

	// weird positioning shit
	b_player.setPosition(0, RES_SIZE - 250);

	// checking if textures loaded
	if (!b_player_texture_idle.loadFromFile("resources\\big_idle_animation.png"))
		exit(1);
	if (!b_player_texture_run.loadFromFile("resources\\big_run.png"))
		exit(1);

}