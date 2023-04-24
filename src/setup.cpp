#include <setup.hpp>

// background and platforms
sf::Texture			bg_texture;
sf::Sprite			background(bg_texture);
sf::Texture			platform_texture;
sf::RectangleShape	platform({900, 32});
sf::Texture			box_texture;
sf::RectangleShape  box({32, 32});

Player box_obj
{
/* velocity     */	{ 0, 0 },
/* velocity_max */	{ 0, 0 },
/* acceleration */	{ 0, 0 },
/* position     */	{ 0, 0 },
			    
/* idle_ind     */	0,
/* run_ind      */	0,
/* jump_ind     */	0,
/* scale        */	1.5f,
/* size_idle_x  */	32,
/* size_idle_y  */	32,
/* size_run_x   */	32,
/* size_run_y   */	32,
/* size_jump_x  */	32,
/* size_jump_y  */	32,
/* anims_idle   */	0,
/* anims_run    */	0,
/* anims_jump   */	0,
/* ID           */	rand() % 69,
			    
/* jumping      */	false,
/* idle         */	true
};

// small player
sf::Texture s_player_texture_jump;
sf::Texture s_player_texture_idle;
sf::Texture s_player_texture_run;
sf::Sprite  s_player(s_player_texture_idle);

Player s_obj
{
/* velocity     */	{  0, 0  },
/* velocity_max */	{  5, 50 },
/* acceleration */	{  0, 0  },
/* position     */	{  0, 0  },
			    
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
/* velocity     */	{  0, 0  },
/* velocity_max */	{  2, 50 },
/* acceleration */	{  0, 0  },
/* position     */	{  0, 0  },
			    
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

// window
sf::RenderWindow window
(
	sf::VideoMode
	(
		Config::RES_SIZE, Config::RES_SIZE
	),
	"The Promised Chickenland",
	sf::Style::Default
);

void setup() 
{
	// set FPS
	window.setFramerateLimit(60);

	// background and platforms
	bg_texture.loadFromFile("resources/background.png");
	platform_texture.loadFromFile("resources/tile_1.png");
	box_texture.loadFromFile("resources/box.png");

	if (!platform_texture.loadFromFile("resources/tile_1.png"))
		exit(1);
	if (!bg_texture.loadFromFile("resources/background.png"))
		exit(1);
	if (!box_texture.loadFromFile("resources/box.png"))
		exit(1);

	background.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	background.setScale(2, 2);
	background.setPosition(-576,-1300);

	platform.setTexture(&platform_texture);
	platform.setScale(1, 1);
	platform.setPosition(0, Config::RES_SIZE - 20);

	box.setTexture(&box_texture);
	box.setScale(box_obj.scale, box_obj.scale);
	box_obj.position =
	{
		box.getPosition().x, 
		platform.getGlobalBounds().top - box.getGlobalBounds().height
	};
	box.setPosition(box_obj.position);

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
		platform.getGlobalBounds().top - 300.f/*s_player.getGlobalBounds().height */
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
		platform.getGlobalBounds().top - b_player.getGlobalBounds().height - 64
	};
	b_player.setPosition(b_obj.position);
}