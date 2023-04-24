#include <SFML\Graphics.hpp>
#include <animate.hpp>
#include <Animation.hpp>
#include <check_idle.hpp>
#include <collision.hpp>
#include <Config.hpp>
#include <get_key_pressed.hpp>
#include <move.hpp>
#include <Player.hpp>
#include <render.hpp>
#include <setup.hpp>

// background and platforms
sf::Texture bg_texture;
sf::Sprite  background(bg_texture);
sf::Texture platform_texture;
sf::Sprite  platform(platform_texture);

// small player
sf::Texture s_player_texture_jump;
sf::Texture s_player_texture_idle;
sf::Texture s_player_texture_run;
sf::Sprite  s_player(s_player_texture_idle);

Player s_obj
{
/* velocity     */	{ 0, 0 },
/* velocity_max */	{ 5, 50 },
/* acceleration */	{ 0, 0 },
/* position     */	{ 70, static_cast<float>(Config::RES_SIZE) - 200 },
			    
/* idle_ind     */	0,
/* run_ind      */	0,
/* jump_ind     */	0,
/* scale        */	1,
/* size_idle_x  */	28,
/* size_idle_y  */	50,
/* size_run_x   */	40,
/* size_run_y   */	50,
/* size_jump_x  */	29,
/* size_jump_y  */	50,
/* anims_idle   */	4,
/* anims_run    */	4,
/* anims_jump   */	9,
/* ID           */	0,
			    
/* jumping      */	false,
/* idle         */	true
};

// big player
sf::Texture b_player_texture_jump;
sf::Texture b_player_texture_idle;
sf::Texture b_player_texture_run;
sf::Sprite  b_player(b_player_texture_idle);

Player b_obj
{
/* velocity     */	{ 0, 0 },
/* velocity_max */	{ 2, 50 },
/* acceleration */	{ 0, 0 },
/* position     */	{ 0, static_cast<float>(Config::RES_SIZE) - 200 },
			    
/* idle_ind     */	0,
/* run_ind      */	0,
/* jump_ind     */	0,
/* scale        */	1,
/* size_idle_x  */	64,
/* size_idle_y  */	64,
/* size_run_x   */	64,
/* size_run_y   */	64,
/* size_jump_x  */	67,
/* size_jump_y  */	67,
/* anims_idle   */	6,
/* anims_run    */	4,
/* anims_jump   */	10,
/* ID           */	1,
			    
/* jumping      */	false,
/* idle         */	true
};

sf::RenderWindow window
(
	sf::VideoMode
	(
		Config::RES_SIZE, Config::RES_SIZE
	),
	"The Promised Chickenland",
	sf::Style::Default
);

int main()
{
	setup();

	// main game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		check_idle(s_player, s_obj);
		check_idle(b_player, b_obj);

		move(s_player, s_obj, get_key_pressed(s_obj));
		move(b_player, b_obj, get_key_pressed(b_obj));

		collision(s_player, s_obj, platform);
		collision(b_player, b_obj, platform);

		render();
	}
	
	return EXIT_SUCCESS;
}