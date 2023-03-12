#include <setup.hpp>
extern Texture player_texture_idle;
extern Texture player_texture_run;
	extern Clock clock_var;
	extern RenderWindow window;
	extern Sprite player;
void setup() {


	// (width, height), window name, window type

	window.setFramerateLimit(60);

	player_texture_idle.loadFromFile("resources\\small_idle_animation.png");

	player_texture_run.loadFromFile("resources\\small_run.png");

	player.setScale(player_scale, player_scale);

	// weird positioning shit
	player.setPosition(0, RES_SIZE - 152);

	// checking if textures loaded
	if (!player_texture_idle.loadFromFile("resources\\small_idle_animation.png"))
		exit(1);
	if (!player_texture_run.loadFromFile("resources\\small_run.png"))
		exit(1);


}