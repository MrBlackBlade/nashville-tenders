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
sf::RectangleShape	button1({32, 9});
sf::RectangleShape	button2({ 32, 9 });
sf::RectangleShape	button3({ 32, 9 });


sf::Texture         chicken_texture;
sf::RectangleShape	chicken1({32, 36});
sf::RectangleShape	chicken2({32, 36});
sf::RectangleShape	chicken3({32, 36});

sf::Texture			door_texture;
sf::RectangleShape  door1({32, 64});
sf::RectangleShape  door2({ 32, 64 });
sf::RectangleShape  door3({ 32, 64 });

sf::Texture			elevator_texture;
sf::RectangleShape  elevator1({104, 16});
sf::RectangleShape  elevator2({ 104, 16 });
sf::RectangleShape  elevator3({ 104, 16 });

sf::Texture			lever_texture;
sf::RectangleShape  lever1({32, 32});
sf::RectangleShape  lever2({ 32, 32 });
sf::RectangleShape  lever3({ 32, 32 });

sf::Texture			platform_texture;
sf::RectangleShape  platform({98, 16});

sf::Texture			end_texture;
sf::RectangleShape  end({18, 35});

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
Object::box,		// ID
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

Object button1_obj
{
Object::button1,		// ID
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
Object button2_obj
{
Object::button2,		// ID
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

Object button3_obj
{
Object::button3,		// ID
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

Object door1_obj
{
Object::door1,	// ID
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


Object door2_obj
{
Object::door2,	// ID
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



Object door3_obj
{
Object::door3,	// ID
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


Object elevator1_obj
{
Object::elevator1, // ID
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

Object elevator2_obj
{
Object::elevator2, // ID
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


Object elevator3_obj
{
Object::elevator3, // ID
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


Object lever1_obj
{
Object::lever1,    // ID
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

Object lever2_obj
{
Object::lever2,    // ID
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

Object lever3_obj
{
Object::lever3,    // ID
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
			    		   
true,			// jumping     
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
	end_texture.loadFromFile("resources/end.png");

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
	if (!end_texture.loadFromFile("resources/end.png"))
		exit(1);

	end.setTexture(&end_texture);
	end.setPosition(300, 800 - ground.getGlobalBounds().height + 30);

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

	// the 3 buttons

	button1.setTexture(&button_texture);
	button1.setScale(button1_obj.scale, button1_obj.scale);
	button1.setTextureRect(sf::IntRect(0, 0, button1_obj.size_x, button1_obj.size_y));

	button1_obj.position =
	{
		50.f,
		ground.getGlobalBounds().top - button1.getGlobalBounds().height
	};
	button1.setPosition(button1_obj.position);
	//
	button2.setTexture(&button_texture);
	button2.setScale(button2_obj.scale, button2_obj.scale);
	button2.setTextureRect(sf::IntRect(0, 0, button2_obj.size_x, button2_obj.size_y));

	button2_obj.position =
	{
		100.f,
		ground.getGlobalBounds().top - button2.getGlobalBounds().height
	};
	button2.setPosition(button2_obj.position);
	//
	button3.setTexture(&button_texture);
	button3.setScale(button3_obj.scale, button3_obj.scale);
	button3.setTextureRect(sf::IntRect(0, 0, button3_obj.size_x, button3_obj.size_y));

	button3_obj.position =
	{
		150.f,
		ground.getGlobalBounds().top - button3.getGlobalBounds().height
	};
	button3.setPosition(button3_obj.position);

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
	chicken2.setPosition(chicken2_obj.position);
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

	// the 3 doors
	door1.setTexture(&door_texture);
	door1.setTextureRect(sf::IntRect(0, 0, door1_obj.size_x, door1_obj.size_y));
	door1.setScale(door1_obj.scale, door1_obj.scale);
	door1_obj.position =
	{
		600.f,
		ground.getGlobalBounds().top - door1.getGlobalBounds().height
	};
	door1.setPosition(door1_obj.position);

	door2.setTexture(&door_texture);
	door2.setTextureRect(sf::IntRect(0, 0, door2_obj.size_x, door2_obj.size_y));
	door2.setScale(door2_obj.scale, door2_obj.scale);
	door2_obj.position =
	{
		700.f,
		ground.getGlobalBounds().top - door2.getGlobalBounds().height
	};
	door2.setPosition(door2_obj.position);

	door3.setTexture(&door_texture);
	door3.setTextureRect(sf::IntRect(0, 0, door3_obj.size_x, door3_obj.size_y));
	door3.setScale(door3_obj.scale, door3_obj.scale);
	door3_obj.position =
	{
		800.f,
		ground.getGlobalBounds().top - door3.getGlobalBounds().height
	};
	door3.setPosition(door3_obj.position);
	
	// the 3 elevators
	elevator1.setTexture(&elevator_texture);
	elevator1.setScale  (elevator1_obj.scale, elevator1_obj.scale);
	elevator1_obj.position =
	{
		50,
		ground.getGlobalBounds().top - elevator1.getGlobalBounds().height - 300
	};
	elevator1.setPosition(elevator1_obj.position);
	//
	elevator2.setTexture(&elevator_texture);
	elevator2.setScale(elevator2_obj.scale, elevator2_obj.scale);
	elevator2_obj.position =
	{
		160,
		ground.getGlobalBounds().top - elevator2.getGlobalBounds().height - 200
	};
	elevator2.setPosition(elevator2_obj.position);
	//
	elevator3.setTexture(&elevator_texture);
	elevator3.setScale(elevator3_obj.scale, elevator3_obj.scale);
	elevator3_obj.position =
	{
		270,
		ground.getGlobalBounds().top - elevator3.getGlobalBounds().height - 100
	};
	elevator3.setPosition(elevator3_obj.position);

	// the 3 levers
	lever1.setTexture(&lever_texture);
	lever1.setTextureRect(sf::IntRect(0, 0, lever1_obj.size_x, lever1_obj.size_y));
	lever1.setScale(lever1_obj.scale, lever1_obj.scale);
	lever1_obj.position =
	{
		800.f,
		ground.getGlobalBounds().top - lever1.getGlobalBounds().height
	};
	lever1.setPosition(lever1_obj.position);

	lever2.setTexture(&lever_texture);
	lever2.setTextureRect(sf::IntRect(0, 0, lever2_obj.size_x, lever2_obj.size_y));
	lever2.setScale(lever2_obj.scale, lever2_obj.scale);
	lever2_obj.position =
	{
		700.f,
		ground.getGlobalBounds().top - lever2.getGlobalBounds().height
	};
	lever2.setPosition(lever2_obj.position);

	lever3.setTexture(&lever_texture);
	lever3.setTextureRect(sf::IntRect(0, 0, lever3_obj.size_x, lever3_obj.size_y));
	lever3.setScale(lever3_obj.scale, lever3_obj.scale);
	lever3_obj.position =
	{
		600.f,
		ground.getGlobalBounds().top - lever3.getGlobalBounds().height
	};
	lever3.setPosition(lever3_obj.position);
	//
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