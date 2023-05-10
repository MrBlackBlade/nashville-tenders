#include <setup.hpp>

// ciken
const sf::Vector2f _______narnia = { (float) INT_MAX, (float) INT_MAX };

// menu
sf::Text		   main_menu[2];
sf::Font		   font;
sf::Texture		   menu_texture;
sf::RectangleShape menu({ 900, 900 });

// music and sound
sf::Music		   main_menu_music;
sf::Music		   game_music;

sf::SoundBuffer	   chicken_collect_sound_buffer;
sf::Sound		   chicken_collect_sound;

sf::SoundBuffer	   elevator1_move_sound_buffer;
sf::SoundBuffer	   elevator2_move_sound_buffer;
sf::SoundBuffer	   elevator3_move_sound_buffer;
sf::Sound		   elevator1_move_sound;
sf::Sound		   elevator2_move_sound;
sf::Sound		   elevator3_move_sound;
sf::SoundBuffer	   lever_pull_sound_buffer;
sf::Sound		   lever_pull_sound;
sf::SoundBuffer	   button_push_sound_buffer;
sf::Sound		   button_push_sound;
sf::SoundBuffer	   door_open_sound_buffer;
sf::Sound		   door_open_sound;
sf::SoundBuffer	   level_complete_sound_buffer;
sf::Sound		   level_complete_sound;

// background and platforms
sf::Texture		   bg_texture_1;
sf::Texture		   bg_texture_2;
sf::Texture		   bg_texture_3;
sf::Texture		   bg_texture_4;
sf::Sprite		   background_1(bg_texture_1);
sf::Sprite		   background_2(bg_texture_2);
sf::Sprite		   background_3(bg_texture_3);
sf::Sprite		   background_4(bg_texture_4);

sf::Texture		   ground_texture;
sf::RectangleShape ground({ 900, 20 });

sf::Texture		   box_texture;
sf::RectangleShape box({ 32, 32 });

sf::Texture		   lv_comp_texture;
sf::RectangleShape lv_comp({ 900, 900 });

sf::Texture		   chicken_counter_texture;
sf::RectangleShape chicken_counter({ 96, 36 });

sf::Texture		   game_end_texture;
sf::Sprite		   game_end;

// collectibles w kda
sf::Texture		   button_texture;
sf::RectangleShape button1({ 32, 9 });
sf::RectangleShape button2({ 32, 9 });
sf::RectangleShape button3({ 32, 9 });

sf::Texture		   chicken_texture;
sf::RectangleShape chicken1({ 32, 36 });
sf::RectangleShape chicken2({ 32, 36 });
sf::RectangleShape chicken3({ 32, 36 });

sf::Texture		   door_texture;
sf::RectangleShape door1({ 32, 64 });
sf::RectangleShape door2({ 32, 64 });
sf::RectangleShape door3({ 32, 64 });

sf::Texture		   elevator_texture;
sf::RectangleShape elevator1({ 104, 16 });
sf::RectangleShape elevator2({ 104, 16 });
sf::RectangleShape elevator3({ 104, 16 });

sf::Texture		   lever_texture;
sf::RectangleShape lever1({ 32, 32 });
sf::RectangleShape lever2({ 32, 32 });
sf::RectangleShape lever3({ 32, 32 });

sf::Texture		   platform_texture;
sf::RectangleShape platform1({ 98, 16 });
sf::RectangleShape platform2({ 98, 16 });
sf::RectangleShape platform3({ 98, 16 });
sf::RectangleShape platform4({ 98, 16 });
sf::RectangleShape platform5({ 98, 16 });
sf::RectangleShape platform6({ 98, 16 });
sf::RectangleShape platform7({ 98, 16 });
sf::RectangleShape platform8({ 98, 16 });
sf::RectangleShape platform9({ 98, 16 });
sf::RectangleShape platform10({ 98, 16 });

sf::Texture		   end_texture;
sf::RectangleShape end({ 18, 35 });

sf::Texture		   loading_texture;
sf::RectangleShape loading({ 900, 900 });

/* Object initializations */
Object			   loading_obj {
	Object::loading, // ID
				{0, 0}, // velocity
				{0, 0}, // velocity_max
				{0, 0}, // acceleration
				{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	900, // size_x
	899, // size_y
	5	 // anims
};

Object chicken_counter_obj {
	Object::chicken_counter, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	96, // size_x
	36, // size_y
	0	 // anims
};

Object ground_obj {
	Object::ground, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	2, // anim_ind
	1.f, // scale
	900, // size_x
	32, // size_y
	0	 // anims
};

Object box_obj {
	Object::box, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	3.2f, // scale
	32, // size_x
	32, // size_y
	0  // anims
};

Object wall_obj {
	Object::box, // ID
	{  0, 0}, // velocity
	{  0, 0}, // velocity_max
	{  0, 0}, // acceleration
	{910, 0}, // position

	0, // anim_ind
	100.f, // scale
	1, // size_x
	2000, // size_y
	0  // anims
};

Object lv_comp_obj {
	Object::object_max, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	900, // size_x
	900, // size_y
	0	 // anims
};

Object button1_obj {
	Object::button1, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	9, // size_y
	2	 // anims
};
Object button2_obj {
	Object::button2, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	9, // size_y
	2	 // anims
};

Object button3_obj {
	Object::button3, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	9, // size_y
	2	 // anims
};

/* the 3 chickens */

Object chicken1_obj {
	Object::chicken1, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	36, // size_y
	4	 // anims
};

Object chicken2_obj {
	Object::chicken2, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	36, // size_y
	4	 // anims
};

Object chicken3_obj {
	Object::chicken3, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	36, // size_y
	4	 // anims
};

Object door1_obj {
	Object::door1, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	3.f, // scale
	32, // size_x
	64, // size_y
	6	 // anims
};

Object door2_obj {
	Object::door2, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	3.f, // scale
	32, // size_x
	64, // size_y
	6	 // anims
};

Object door3_obj {
	Object::door3, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	3.f, // scale
	32, // size_x
	64, // size_y
	6	 // anims
};

Object elevator1_obj {
	Object::elevator1, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	104, // size_x
	16, // size_y
	0	 // anims
};

Object elevator2_obj {
	Object::elevator2, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	104, // size_x
	16, // size_y
	0	 // anims
};

Object elevator3_obj {
	Object::elevator3, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	104, // size_x
	16, // size_y
	0	 // anims
};

Object lever1_obj {
	Object::lever1, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	32, // size_y
	3	 // anims
};

Object lever2_obj {
	Object::lever2, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	32, // size_y
	3	 // anims
};

Object lever3_obj {
	Object::lever3, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	1.f, // scale
	32, // size_x
	32, // size_y
	3	 // anims
};

Object platform1_obj {
	Object::platform1, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform2_obj {
	Object::platform2, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform3_obj {
	Object::platform3, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform4_obj {
	Object::platform4, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform5_obj {
	Object::platform5, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform6_obj {
	Object::platform6, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform7_obj {
	Object::platform7, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform8_obj {
	Object::platform8, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform9_obj {
	Object::platform9, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

Object platform10_obj {
	Object::platform10, // ID
	{0, 0}, // velocity
	{0, 0}, // velocity_max
	{0, 0}, // acceleration
	{0, 0}, // position

	0, // anim_ind
	2.f, // scale
	98, // size_x
	16, // size_y
	0	 // anims
};

// small player
sf::Texture s_player_texture_jump;
sf::Texture s_player_texture_idle;
sf::Texture s_player_texture_run;
sf::Sprite	s_player(s_player_texture_idle);

/* Player initializations */
Player		s_obj {
		 {  0,  0}, // velocity
		 {4.5, 50}, // velocity_max
		 {  0,  0}, // acceleration
		 {  0,  0}, // position

	 0, // idle_ind
	 0, // run_ind
	 0, // jump_ind
	 0, // push_ind
	 1, // scale
	 28, // size_idle_x
	 52, // size_idle_y
	 40, // size_run_x
	 52, // size_run_y
	 29, // size_jump_x
	 56, // size_jump_y
	 0, // size_push_x
	 0, // size_push_y
	 4, // anims_idle
	 4, // anims_run
	 9, // anims_jump
	 0, // anims_push
	 0, // ID

	 true, // jumping
	 true  // idle
};

// big player
sf::Texture b_player_texture_jump;
sf::Texture b_player_texture_idle;
sf::Texture b_player_texture_run;
sf::Texture b_player_texture_push;
sf::Sprite	b_player(b_player_texture_idle);

/* Player initializations */
Player		b_obj {
		 {  0,  0}, // velocity
		 {1.5, 50}, // velocity_max
		 {  0,  0}, // acceleration
		 {  0,  0}, // position

	 0, // idle_ind
	 0, // run_ind
	 0, // jump_ind
	 0, // push_ind
	 1, // scale
	 64, // size_idle_x
	 64, // size_idle_y
	 64, // size_run_x
	 64, // size_run_y
	 67, // size_jump_x
	 67, // size_jump_y
	 64, // size_push_x
	 64, // size_push_y
	 6, // anims_idle
	 4, // anims_run
	 10, // anims_jump
	 4, // anims_push
	 1, // ID

	 true, // jumping
	 true  // idle
};

// window
sf::RenderWindow window(
	sf::VideoMode(Config::RES_SIZE, Config::RES_SIZE),
	"The Promised Chickenland",
	sf::Style::Default
);

void setup()
{
	// set FPS
	window.setFramerateLimit(60);

	// music and sound
	main_menu_music.openFromFile("resources/main_menu.ogg");
	game_music.openFromFile("resources/game.ogg");

	chicken_collect_sound_buffer.loadFromFile("resources/chicken_collect.ogg");
	chicken_collect_sound.setBuffer(chicken_collect_sound_buffer);

	elevator1_move_sound.setBuffer(elevator1_move_sound_buffer);
	elevator1_move_sound_buffer.loadFromFile("resources/elevator.ogg");

	elevator2_move_sound.setBuffer(elevator2_move_sound_buffer);
	elevator2_move_sound_buffer.loadFromFile("resources/elevator.ogg");

	elevator3_move_sound.setBuffer(elevator3_move_sound_buffer);
	elevator3_move_sound_buffer.loadFromFile("resources/elevator.ogg");

	lever_pull_sound_buffer.loadFromFile("resources/lever_pull.ogg");
	lever_pull_sound.setBuffer(lever_pull_sound_buffer);

	button_push_sound_buffer.loadFromFile("resources/button.ogg");
	button_push_sound.setBuffer(button_push_sound_buffer);

	door_open_sound_buffer.loadFromFile("resources/door_open.ogg");
	door_open_sound.setBuffer(door_open_sound_buffer);

	level_complete_sound_buffer.loadFromFile("resources/level_complete.ogg");
	level_complete_sound.setBuffer(level_complete_sound_buffer);

	// background and objects
	menu_texture.loadFromFile("resources/bg_menu.png");

	bg_texture_1.loadFromFile("resources/bg1.png");
	bg_texture_2.loadFromFile("resources/bg2.png");
	bg_texture_3.loadFromFile("resources/bg3.png");
	bg_texture_4.loadFromFile("resources/bg4.png");

	ground_texture.loadFromFile("resources/tile_1.png");
	box_texture.loadFromFile("resources/box.png");
	chicken_counter_texture.loadFromFile("resources/chicken_counter.png");
	button_texture.loadFromFile("resources/button.png");
	chicken_texture.loadFromFile("resources/chicken.png");
	door_texture.loadFromFile("resources/door.png");
	elevator_texture.loadFromFile("resources/elevator.png");
	lever_texture.loadFromFile("resources/lever.png");
	platform_texture.loadFromFile("resources/platform.png");
	end_texture.loadFromFile("resources/end.png");

	lv_comp_texture.loadFromFile("resources/level_complete.png");
	loading_texture.loadFromFile("resources/loading.png");
	game_end_texture.loadFromFile("resources/game_end.png");

	menu.setTexture(&menu_texture);
	menu.setPosition(0, 0);

	end.setTexture(&end_texture);
	end.setPosition(300, 800 - ground.getGlobalBounds().height + 30);

	loading.setTexture(&loading_texture);
	loading.setTextureRect(sf::IntRect(0, 0, 900, 900));
	loading.setPosition(0, 0);

	game_end.setTexture(game_end_texture);
	game_end.setTextureRect(sf::IntRect(0, 0, 900, 900));
	game_end.setPosition(0, 0);

	chicken_counter.setTexture(&chicken_counter_texture);
	chicken_counter.setTextureRect(sf::IntRect(0, 0, 96, 36));
	chicken_counter.setScale(1.2, 1.2);
	chicken_counter.setPosition(20, 15);

	background_1.setTextureRect(sf::IntRect(0, 0, 4828, 1215));
	background_1.setScale(0.5, 0.5);
	background_1.setPosition(-804, 0);

	background_2.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	background_2.setScale(2, 2);
	background_2.setPosition(-576, -1300);

	background_3.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	background_3.setScale(2, 2);
	background_3.setPosition(-576, -1300);

	background_4.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	background_4.setScale(2, 2);
	background_4.setPosition(-576, -1280);

	ground.setTexture(&ground_texture);
	ground.setScale(ground_obj.scale, ground_obj.scale);
	ground_obj.position = { 0, Config::RES_SIZE - ground.getGlobalBounds().height };
	ground.setPosition(ground_obj.position);

	box.setTexture(&box_texture);
	box.setScale(box_obj.scale, box_obj.scale);

	lv_comp.setTexture(&lv_comp_texture);
	lv_comp.setScale(1, 1);
	lv_comp.setPosition(0, 0);

	/* the 3 buttons */

	button1.setTexture(&button_texture);
	button1.setScale(button1_obj.scale, button1_obj.scale);
	button1.setTextureRect(sf::IntRect(0, 0, button1_obj.size_x, button1_obj.size_y));
	button1_obj.position = { 50.f, ground.getGlobalBounds().top - button1.getGlobalBounds().height };
	button1.setPosition(button1_obj.position);

	button2.setTexture(&button_texture);
	button2.setScale(button2_obj.scale, button2_obj.scale);
	button2.setTextureRect(sf::IntRect(0, 0, button2_obj.size_x, button2_obj.size_y));
	button2_obj.position = { 100.f, ground.getGlobalBounds().top - button2.getGlobalBounds().height };
	button2.setPosition(button2_obj.position);

	button3.setTexture(&button_texture);
	button3.setScale(button3_obj.scale, button3_obj.scale);
	button3.setTextureRect(sf::IntRect(0, 0, button3_obj.size_x, button3_obj.size_y));
	button3_obj.position = { 150.f, ground.getGlobalBounds().top - button3.getGlobalBounds().height };
	button3.setPosition(button3_obj.position);

	/* the 3 chickens */

	chicken1.setTexture(&chicken_texture);
	chicken1.setScale(chicken1_obj.scale, chicken1_obj.scale);
	chicken1_obj.position = { 5000.f, ground.getGlobalBounds().top - chicken1.getGlobalBounds().height };
	chicken1.setPosition(chicken1_obj.position);

	chicken2.setTexture(&chicken_texture);
	chicken2.setScale(chicken2_obj.scale, chicken2_obj.scale);
	chicken2_obj.position = { 5500.f, ground.getGlobalBounds().top - chicken2.getGlobalBounds().height };
	chicken2.setPosition(chicken2_obj.position);

	chicken3.setTexture(&chicken_texture);
	chicken3.setScale(chicken3_obj.scale, chicken3_obj.scale);
	chicken3_obj.position = { 6000.f, ground.getGlobalBounds().top - chicken3.getGlobalBounds().height };
	chicken3.setPosition(chicken3_obj.position);

	/* the 3 doors */
	door1.setTexture(&door_texture);
	door1.setTextureRect(sf::IntRect(0, 0, door1_obj.size_x, door1_obj.size_y));
	door1.setScale(door1_obj.scale, door1_obj.scale);

	door2.setTexture(&door_texture);
	door2.setTextureRect(sf::IntRect(0, 0, door2_obj.size_x, door2_obj.size_y));
	door2.setScale(door2_obj.scale, door2_obj.scale);

	door3.setTexture(&door_texture);
	door3.setTextureRect(sf::IntRect(0, 0, door3_obj.size_x, door3_obj.size_y));
	door3.setScale(door3_obj.scale, door3_obj.scale);

	/* the 3 elevators */
	elevator1.setTexture(&elevator_texture);
	elevator1.setScale(elevator1_obj.scale, elevator1_obj.scale);

	elevator2.setTexture(&elevator_texture);
	elevator2.setScale(elevator2_obj.scale, elevator2_obj.scale);

	elevator3.setTexture(&elevator_texture);

	/* the 3 levers */
	lever1.setTexture(&lever_texture);
	lever1.setTextureRect(sf::IntRect(0, 0, lever1_obj.size_x, lever1_obj.size_y));
	lever1.setScale(lever1_obj.scale, lever1_obj.scale);

	lever2.setTexture(&lever_texture);
	lever2.setTextureRect(sf::IntRect(0, 0, lever2_obj.size_x, lever2_obj.size_y));
	lever2.setScale(lever2_obj.scale, lever2_obj.scale);

	lever3.setTexture(&lever_texture);
	lever3.setTextureRect(sf::IntRect(0, 0, lever3_obj.size_x, lever3_obj.size_y));
	lever3.setScale(lever3_obj.scale, lever3_obj.scale);

	/* platforms */
	platform1.setTexture(&platform_texture);
	platform1.setScale(platform1_obj.scale, platform1_obj.scale);

	platform2.setTexture(&platform_texture);
	platform2.setScale(platform2_obj.scale, platform2_obj.scale);

	platform3.setTexture(&platform_texture);
	platform3.setScale(platform3_obj.scale, platform3_obj.scale);

	platform4.setTexture(&platform_texture);
	platform4.setScale(platform4_obj.scale, platform4_obj.scale);

	platform5.setTexture(&platform_texture);
	platform5.setScale(platform5_obj.scale, platform5_obj.scale);

	platform6.setTexture(&platform_texture);
	platform6.setScale(platform6_obj.scale, platform6_obj.scale);

	platform7.setTexture(&platform_texture);
	platform7.setScale(platform7_obj.scale, platform7_obj.scale);

	platform8.setTexture(&platform_texture);
	platform8.setScale(platform8_obj.scale, platform8_obj.scale);

	platform9.setTexture(&platform_texture);
	platform9.setScale(platform9_obj.scale, platform9_obj.scale);

	platform10.setTexture(&platform_texture);
	platform10.setScale(platform10_obj.scale, platform10_obj.scale);

	// small player
	s_player_texture_jump.loadFromFile("resources/small_jump_animation.png");
	s_player_texture_idle.loadFromFile("resources/small_idle_animation.png");
	s_player_texture_run.loadFromFile("resources/small_run.png");

	s_player.setScale(s_obj.scale, s_obj.scale);

	// big player
	b_player_texture_jump.loadFromFile("resources/big_jump_animation.png");
	b_player_texture_idle.loadFromFile("resources/big_idle_animation.png");
	b_player_texture_run.loadFromFile("resources/big_run.png");
	b_player_texture_push.loadFromFile("resources/big_push_animation.png");

	b_player.setScale(b_obj.scale, b_obj.scale);
}