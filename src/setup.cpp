#include <setup.hpp>

// background and platforms
sf::Texture			bg_texture_1;
sf::Texture			bg_texture_2;
sf::Texture			bg_texture_3;
sf::Texture			bg_texture_4;
sf::Sprite			background_1(bg_texture_1);
sf::Sprite			background_2(bg_texture_2);
sf::Sprite			background_3(bg_texture_3);
sf::Sprite			background_4(bg_texture_4);
sf::Texture			ground_texture;
sf::RectangleShape	ground({900, 20});
sf::Texture			box_texture;
sf::RectangleShape  box({32, 32});
sf::Texture			button_texture;
sf::RectangleShape	button({32, 9});
sf::Texture         chicken_texture;
sf::RectangleShape	chicken1({32, 36});
sf::RectangleShape	chicken2({32, 36});
sf::RectangleShape	chicken3({32, 36});
sf::Texture			door_texture;
sf::RectangleShape  door({32, 64});
sf::Texture			elevator_texture;
sf::RectangleShape  elevator({104, 16});
sf::Texture			lever_texture;
sf::RectangleShape  lever({32, 32});
sf::Texture			platform_texture;
sf::RectangleShape  platform({98, 16});

Object ground_obj
{
Object::ground,		// ID
{ 0, 0 },			// velocity    
{ 0, 0 },			// velocity_max
{ 0, 0 },			// acceleration
{ 0, 0 },			// position    
				    
2,					// anim_ind    
1.f,				// scale       
900,				// size_x	
32,					// size_y	
0					// anims
};

Object box_obj
{
Object::box,			// ID
{ 0, 0 },			// velocity    
{ 0, 0 },			// velocity_max
{ 0, 0 },			// acceleration
{ 0, 0 },			// position    
				 
0,					// anim_ind    
2.5f,				// scale       
32,					// size_x	
32,					// size_y	
0					// anims	
};

Object button_obj
{
Object::button,		// ID
{ 0, 0 },			// velocity    
{ 0, 0 },			// velocity_max
{ 0, 0 },			// acceleration
{ 0, 0 },			// position    
				 
0,					// anim_ind    
1.f,				// scale       
32,					// size_x	
9,					// size_y	
2					// anims	
};

/* the 3 chickens */

Object chicken1_obj
{
Object::chicken1,		// ID
{ 0, 0 },			// velocity    
{ 0, 0 },			// velocity_max
{ 0, 0 },			// acceleration
{ 0, 0 },			// position    
				 
0,					// anim_ind    
1.f,				// scale       
32,					// size_x	
36,					// size_y	
4					// anims	
};

Object chicken2_obj
{
Object::chicken2,		// ID
{ 0, 0 },			// velocity    
{ 0, 0 },			// velocity_max
{ 0, 0 },			// acceleration
{ 0, 0 },			// position    
				 
0,					// anim_ind    
1.f,				// scale       
32,					// size_x	
36,					// size_y	
4					// anims	
};

Object chicken3_obj
{
Object::chicken3,		// ID
{ 0, 0 },			// velocity    
{ 0, 0 },			// velocity_max
{ 0, 0 },			// acceleration
{ 0, 0 },			// position    
				 
0,					// anim_ind    
1.f,				// scale       
32,					// size_x	
36,					// size_y	
4					// anims	
};

/* the 3 chicken
s */

Object door_obj
{
Object::door,	// ID
{ 0, 0 },		// velocity    
{ 0, 0 },		// velocity_max
{ 0, 0 },		// acceleration
{ 0, 0 },		// position    
				 
0,				// anim_ind    
3.f,			// scale       
32,				// size_x	
64,				// size_y	
6				// anims	
};

Object elevator_obj
{
Object::elevator, // ID
{ 0, 0 },		  // velocity    
{ 0, 0 },		  // velocity_max
{ 0, 0 },		  // acceleration
{ 0, 0 },		  // position    
				   
0,				  // anim_ind    
1.f,			  // scale       
104,			  // size_x	
16,				  // size_y	
0				  // anims	
};

Object lever_obj
{
Object::lever,    // ID
{ 0, 0 },		  // velocity    
{ 0, 0 },		  // velocity_max
{ 0, 0 },		  // acceleration
{ 0, 0 },		  // position    
				   
0,				  // anim_ind    
1.f,			  // scale       
32,			      // size_x	
32,				  // size_y	
3				  // anims	
};

Object platform_obj
{
Object::platform,    // ID
{ 0, 0 },			 // velocity    
{ 0, 0 },			 // velocity_max
{ 0, 0 },			 // acceleration
{ 0, 0 },			 // position    
				   
0,					 // anim_ind    
1.f,				 // scale       
98,					 // size_x	
16,					 // size_y	
0					 // anims	
};

// small player
sf::Texture s_player_texture_jump;
sf::Texture s_player_texture_idle;
sf::Texture s_player_texture_run;
sf::Sprite  s_player(s_player_texture_idle);

Player s_obj
{
{  0, 0  },		// velocity    
{  5, 50 },		// velocity_max
{  0, 0  },		// acceleration
{  0, 0  },		// position    
			    		   
0,				// idle_ind    
0,				// run_ind     
0,				// jump_ind 
0,				// push_ind
1,				// scale       
28,				// size_idle_x 
50,				// size_idle_y 
40,				// size_run_x  
50,				// size_run_y  
29,				// size_jump_x 
56,				// size_jump_y 
0,				// size_push_x
0,				// size_push_y
4,				// anims_idle  
4,				// anims_run   
9,				// anims_jump 
0,				// anims_push
0,				// ID          
			    		   
false,			// jumping     
true			// idle        
};

// big player
sf::Texture b_player_texture_jump;
sf::Texture b_player_texture_idle;
sf::Texture b_player_texture_run;
sf::Texture b_player_texture_push;
sf::Sprite  b_player(b_player_texture_idle);

Player b_obj
{
{  0, 0  },		// velocity    
{  2, 50 },		// velocity_max
{  0, 0  },		// acceleration
{  0, 0  },		// position    
	 					   
0,				// idle_ind    
0,				// run_ind     
0,				// jump_ind
0,				// push_ind
1,				// scale       
64,				// size_idle_x 
64,				// size_idle_y 
64,				// size_run_x  
64,				// size_run_y  
67,				// size_jump_x 
67,				// size_jump_y 
64,				// size_push_x
64,				// size_push_y
6,				// anims_idle  
4,				// anims_run   
10,				// anims_jump 
4,				// anims_push
1,				// ID          
	 					   
true,			// jumping     
true			// idle        
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

	// background and objects
	bg_texture_1.loadFromFile("resources/bg1.png");
	bg_texture_2.loadFromFile("resources/bg2.png");
	bg_texture_3.loadFromFile("resources/bg3.png");
	bg_texture_4.loadFromFile("resources/bg4.png");

	ground_texture.loadFromFile("resources/tile_1.png");
	box_texture.loadFromFile("resources/box.png");
	button_texture.loadFromFile("resources/button.png");
	chicken_texture.loadFromFile("resources/chicken.png");
	door_texture.loadFromFile("resources/door.png");
	elevator_texture.loadFromFile("resources/elevator.png");
	lever_texture.loadFromFile("resources/lever.png");
	platform_texture.loadFromFile("resources/platform.png");

	if (!ground_texture.loadFromFile("resources/tile_1.png"))
		exit(1);
	if (!bg_texture_1.loadFromFile("resources/bg1.png"))
		exit(1);
	if (!bg_texture_2.loadFromFile("resources/bg2.png"))
		exit(1);
	if (!bg_texture_3.loadFromFile("resources/bg3.png"))
		exit(1);
	if (!bg_texture_4.loadFromFile("resources/bg4.png"))
		exit(1);
	if (!box_texture.loadFromFile("resources/box.png"))
		exit(1);
	if (!button_texture.loadFromFile("resources/button.png"))
		exit(1);
	if (!chicken_texture.loadFromFile("resources/chicken.png"))
		exit(1);
	if (!door_texture.loadFromFile("resources/door.png"))
		exit(1);
	if (!elevator_texture.loadFromFile("resources/elevator.png"))
		exit(1);
	if (!lever_texture.loadFromFile("resources/lever.png"))
		exit(1);
	if (!platform_texture.loadFromFile("resources/platform.png"))
		exit(1);

	background_1.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	background_1.setScale(2, 2);
	background_1.setPosition(-576,-1300);

	background_2.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	background_2.setScale(2, 2);
	background_2.setPosition(-576, -1300);

	background_3.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	background_3.setScale(2, 2);
	background_3.setPosition(-576, -1300);

	background_4.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	background_4.setScale(2, 2);
	background_4.setPosition(-576, -1300);

	ground.setTexture(&ground_texture);
	ground.setScale(ground_obj.scale, ground_obj.scale);
	ground_obj.position =
	{
		0,
		Config::RES_SIZE - ground.getGlobalBounds().height
	};
	ground.setPosition(ground_obj.position);

	box.setTexture(&box_texture);
	box.setScale(box_obj.scale, box_obj.scale);
	box_obj.position =
	{
		300,
		ground.getGlobalBounds().top - box.getGlobalBounds().height
	};
	box.setPosition(box_obj.position);

	button.setTexture(&button_texture);
	button.setScale(button_obj.scale, button_obj.scale);
	button.setTextureRect(sf::IntRect(0, 0, button_obj.size_x, button_obj.size_y));

	button_obj.position =
	{
		200.f,
		ground.getGlobalBounds().top - button.getGlobalBounds().height
	};
	button.setPosition(button_obj.position);

	/* the 3 chickens */

	chicken1.setTexture(&chicken_texture);
	chicken1.setScale(chicken1_obj.scale, chicken1_obj.scale);
	chicken1_obj.position =
	{
		500.f,
		ground.getGlobalBounds().top - chicken1.getGlobalBounds().height
	};
	chicken1.setPosition(chicken1_obj.position);
	//
	chicken2.setTexture(&chicken_texture);
	chicken2.setScale(chicken2_obj.scale, chicken2_obj.scale);
	chicken2_obj.position =
	{
		550.f,
		ground.getGlobalBounds().top - chicken2.getGlobalBounds().height
	};
	chicken2.setPosition(chicken1_obj.position);
	//
	chicken3.setTexture(&chicken_texture);
	chicken3.setScale(chicken3_obj.scale, chicken3_obj.scale);
	chicken3_obj.position =
	{
		600.f,
		ground.getGlobalBounds().top - chicken3.getGlobalBounds().height
	};
	chicken3.setPosition(chicken3_obj.position);
	//

	/* the 3 chickens */
	door.setTexture(&door_texture);
	door.setTextureRect(sf::IntRect(0, 0, door_obj.size_x, door_obj.size_y));
	door.setScale(door_obj.scale, door_obj.scale);
	door_obj.position =
	{
		700.f,
		ground.getGlobalBounds().top - door.getGlobalBounds().height
	};
	door.setPosition(door_obj.position);

	elevator.setTexture(&elevator_texture);
	elevator.setScale  (elevator_obj.scale, elevator_obj.scale);
	elevator_obj.position =
	{
		40,
		ground.getGlobalBounds().top - elevator.getGlobalBounds().height
	};
	elevator.setPosition(elevator_obj.position);

	lever.setTexture(&lever_texture);
	lever.setTextureRect(sf::IntRect(0, 0, lever_obj.size_x, lever_obj.size_y));
	lever.setScale(lever_obj.scale, lever_obj.scale);
	lever_obj.position =
	{
		800.f,
		ground.getGlobalBounds().top - lever.getGlobalBounds().height
	};
	lever.setPosition(lever_obj.position);

	platform.setTexture(&platform_texture);
	platform.setScale(platform_obj.scale, platform_obj.scale);
	platform_obj.position =
	{
		6000.f,
		0.f/*Config::RES_SIZE / 2.f + 30.f*/
	};
	platform.setPosition(platform_obj.position);

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
		ground.getGlobalBounds().top - s_player.getGlobalBounds().height
	};
	s_player.setPosition(s_obj.position);

	// big player
	b_player_texture_jump.loadFromFile("resources/big_jump_animation.png");
	b_player_texture_idle.loadFromFile("resources/big_idle_animation.png");
	b_player_texture_run.loadFromFile ("resources/big_run.png");
	b_player_texture_push.loadFromFile("resources/big_push_animation.png");

	if (!b_player_texture_jump.loadFromFile("resources/big_jump_animation.png"))
		exit(1);
	if (!b_player_texture_idle.loadFromFile("resources/big_idle_animation.png"))
		exit(1);
	if (!b_player_texture_run.loadFromFile("resources/big_run.png"))
		exit(1);
	if (!b_player_texture_push.loadFromFile("resources/big_push_animation.png"))
		exit(1);

	b_player.setScale(b_obj.scale, b_obj.scale);
	b_obj.position =
	{
		500.f,
		ground.getGlobalBounds().top - b_player.getGlobalBounds().height - 64.f 
	};
	b_player.setPosition(b_obj.position);
}