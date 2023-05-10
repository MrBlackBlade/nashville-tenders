#include <levels.hpp>

void caller()
{
	if (Config::game_status == 1)
		level_one();
	else if (Config::game_status == 2)
		level_two();
	else if (Config::game_status == 3)
		level_three();
}

void spawn(
	Pair_Object* renderable_pair,
	const float& x,
	const float& y,
	const float& angle,
	float		 scale_x,
	float		 scale_y
)
{
	renderable_pair->obj->position = { x, y };
	renderable_pair->shape->setPosition(renderable_pair->obj->position);
	renderable_pair->shape->setRotation(angle);

	// if no scale parameters were passed
	if (scale_x == -1.f)
	{
		scale_x = renderable_pair->shape->getScale().x;
		return;
	}

	if (scale_y == -1.f)
	{
		scale_y = renderable_pair->shape->getScale().y;
		return;
	}

	// a scale was explicitly specified
	renderable_pair->shape->setScale(scale_x, scale_y);
}

void level_one()
{
	using Config::objects, Config::players;

	// animate the loading screen
	animate(pLoading);

	// run once at the start of the level
	if (!Config::lv1_spawned)
	{
		// reset all object attributes and booleans
		reset();

		play_bgm(MusicIndex::game_music_index);

		// sound only plays once
		game_music.stop();

		// platforms
		spawn(Config::objects[Object::platform1], 0, 328);
		spawn(Config::objects[Object::platform2], 200, 328);
		spawn(Config::objects[Object::platform3], 400, 328);
		spawn(Config::objects[Object::platform4], 600, 328);
		spawn(Config::objects[Object::platform5], 700, 550);
		spawn(Config::objects[Object::platform6], 500, 550);
		spawn(Config::objects[Object::platform7], 300, 550);
		spawn(Config::objects[Object::platform8], 0, 550);
		spawn(Config::objects[Object::platform9], 400, 6500);
		spawn(Config::objects[Object::platform10], 6000, 700);

		// Elevators
		spawn(Config::objects[Object::elevator1], 195.5, 881);
		spawn(Config::objects[Object::elevator2], 795, 328);
		spawn(Config::objects[Object::elevator3], 6000, 700);

		// Box
		spawn(Config::objects[Object::box], 6000, 700);

		// Doors
		spawn(Config::objects[Object::door1], 600, 0, 0, door1_obj.scale * 1.8, door1_obj.scale * 1.8);
		spawn(Config::objects[Object::door2], 500, 360, 0, door2_obj.scale * 1, door2_obj.scale * 1);
		spawn(Config::objects[Object::door3], 600, 700, 0, door3_obj.scale * 1.6, door3_obj.scale * 1.6);

		// Buttons
		spawn(Config::objects[Object::button1], 85, 541);
		spawn(Config::objects[Object::button2], 720, 541);
		spawn(Config::objects[Object::button3], 280, 320);

		// Levers
		spawn(Config::objects[Object::lever1], 550, 297);
		spawn(Config::objects[Object::lever2], 400, 520);
		spawn(Config::objects[Object::lever3], 6000, 700);

		// Chickens
		spawn(Config::objects[Object::chicken1], 850, 250);
		spawn(Config::objects[Object::chicken2], 800, 800);
		spawn(Config::objects[Object::chicken3], 40, 450);

		/* Players */
		// Small Player

		s_obj.position = { 0, 0 };
		s_player.setPosition(s_obj.position);

		// Big Player
		b_obj.position = { 0, 900 };
		b_player.setPosition(b_obj.position);

		// Endgame
		end.setPosition(850, 500 - ground.getGlobalBounds().height + 37);

		Config::lv1_spawned = true;
	}

	if (Config::loaded && !Config::game_music_playing)
	{
		game_music.play();
		game_music.setVolume(100);

		Config::game_music_playing = true;
	}

	// elevator (1) motion
	if ((((check_lever(*Config::players[0], *Config::objects[Object::lever1]) ||
		   check_lever(*players[1], *Config::objects[Object::lever1]))) ||
		 Config::lever1_pushed) &&
		objects[Object::elevator1]->obj->position.y >= 550)
	{
		objects[Object::elevator1]->obj->position.y -= .8f;
		objects[Object::elevator1]->shape->setPosition(Config::objects[Object::elevator1]->obj->position
		);
	}

	// elevator (1) stops
	if (objects[Object::elevator1]->obj->position.y <= 550)
	{
		play_sfx(SoundIndex::elevator1_stop);
	}

	// elevator (2) motion
	if ((((check_lever(*Config::players[0], *Config::objects[Object::lever2]) ||
		   check_lever(*players[1], *Config::objects[Object::lever2]))) ||
		 Config::lever2_pushed) &&
		objects[Object::elevator2]->obj->position.y <= 550)
	{
		objects[Object::elevator2]->obj->position.y += .8f;
		objects[Object::elevator2]->shape->setPosition(Config::objects[Object::elevator2]->obj->position
		);
	}

	// elevator (2) stops
	if (objects[Object::elevator2]->obj->position.y >= 550)
	{
		play_sfx(SoundIndex::elevator2_stop);
	}

	// checking if the level is over
	if (Config::game_status == 1 && Config::chicken_num == 3 &&
		players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) &&
		players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && Config::loaded)
	{
		Config::loaded		   = false;

		// reset the loading screen
		pLoading.obj->anim_ind = 0;

		// animate the loading screen
		animate(pLoading);

		Config::chicken_num = 0;
		Config::game_status = 2;

		// update the chicken counter
		animate(pChicken_counter);

		// mute the level music
		Config::game_music_playing = false;
		game_music.setVolume(0);
		play_sfx(SoundIndex::level_complete);
		return;
	}
}

void level_two()
{
	using Config::objects, Config::players;

	// animate the loading screen
	animate(pLoading);

	// run once at the start of the level
	if (!Config::lv2_spawned)
	{
		// reset all object attributes and booleans
		reset();

		play_bgm(MusicIndex::game_music_index);

		// sound only plays once
		game_music.stop();

		spawn(Config::objects[Object::platform1], 416, -45, 90);
		spawn(Config::objects[Object::platform2], 435, 360);
		spawn(Config::objects[Object::platform3], 234, 360);
		spawn(Config::objects[Object::platform4], 704, 620);
		spawn(Config::objects[Object::platform5], 0, 620);
		spawn(Config::objects[Object::platform6], 508, 620);
		spawn(Config::objects[Object::platform7], 493, -45, 90);
		spawn(Config::objects[Object::platform8], 5000, 620);
		spawn(Config::objects[Object::platform9], 4000, 65000);
		spawn(Config::objects[Object::platform10], 60000, 7000);

		// Elevators
		spawn(Config::objects[Object::elevator1], 195.5, 881);
		spawn(Config::objects[Object::elevator2], 90, 612);
		spawn(Config::objects[Object::elevator3], 700, 612);

		// Box
		spawn(Config::objects[Object::box], 195.5, 880);

		// Doors
		spawn(Config::objects[Object::door1], 380, 150, 0, door1_obj.scale * 1.2, door1_obj.scale * 1.2);
		spawn(Config::objects[Object::door2], 5000, 3600);
		spawn(Config::objects[Object::door3], 600, 720, 0, door3_obj.scale * 1.2, door3_obj.scale * 1.2);

		// Buttons
		spawn(Config::objects[Object::button1], 5, 611);
		spawn(Config::objects[Object::button2], 700, 5400);
		spawn(Config::objects[Object::button3], 540, 611);

		// Levers
		spawn(Config::objects[Object::lever1], 600, 588);
		spawn(Config::objects[Object::lever2], 550, 328);
		spawn(Config::objects[Object::lever3], 50, 588);

		// Chickens
		spawn(Config::objects[Object::chicken1], 750, 250);
		spawn(Config::objects[Object::chicken2], 800, 800);
		spawn(Config::objects[Object::chicken3], 140, 450);

		/* Players */
		// Small Player
		s_obj.position = { 80, 900 };
		s_player.setPosition(s_obj.position);

		// Big Player
		b_obj.position = { 0, 900 };
		b_player.setPosition(b_obj.position);

		// Endgame
		end.setPosition(520, 327);

		Config::lv2_spawned = true;
	}

	if (Config::loaded && !Config::game_music_playing)
	{
		game_music.play();
		game_music.setVolume(100);
		Config::game_music_playing = true;
	}

	// elevator (1) motion
	if ((((check_lever(*Config::players[0], *Config::objects[Object::lever1]) ||
		   check_lever(*players[1], *Config::objects[Object::lever1]))) ||
		 Config::lever1_pushed) &&
		objects[Object::elevator1]->obj->position.y >= 620)
	{
		objects[Object::elevator1]->obj->position.y -= .8f;
		objects[Object::elevator1]->shape->setPosition(Config::objects[Object::elevator1]->obj->position
		);
	}

	// elevator (1) stops
	if (objects[Object::elevator1]->obj->position.y <= 620)
	{
		play_sfx(SoundIndex::elevator1_stop);
	}

	// elevator (2) motion
	if ((((check_lever(*Config::players[0], *Config::objects[Object::lever2]) ||
		   check_lever(*players[1], *Config::objects[Object::lever2]))) ||
		 Config::lever2_pushed) &&
		objects[Object::elevator2]->obj->position.y >= 360)
	{
		objects[Object::elevator2]->obj->position.y -= .8f;
		objects[Object::elevator2]->shape->setPosition(Config::objects[Object::elevator2]->obj->position
		);
	}

	// elevator (2) stops
	if (objects[Object::elevator2]->obj->position.y <= 360)
	{
		play_sfx(SoundIndex::elevator2_stop);
	}

	// elevator (3) motion
	if ((((check_lever(*Config::players[0], *Config::objects[Object::lever3]) ||
		   check_lever(*players[1], *Config::objects[Object::lever3]))) ||
		 Config::lever3_pushed) &&
		objects[Object::elevator3]->obj->position.y >= 360)
	{
		objects[Object::elevator3]->obj->position.y -= .8f;
		objects[Object::elevator3]->shape->setPosition(Config::objects[Object::elevator3]->obj->position
		);
	}

	// elevator (3) stops
	if (objects[Object::elevator3]->obj->position.y <= 360)
	{
		play_sfx(SoundIndex::elevator3_stop);
	}

	if (Config::game_status == 2 && Config::chicken_num == 3 &&
		players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) &&
		players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && Config::loaded)
	{
		Config::loaded		   = false;

		// reset the loading screen
		pLoading.obj->anim_ind = 0;

		// animate the loading screen
		animate(pLoading);

		Config::chicken_num = 0;
		Config::game_status = 3;

		// update the chicken counter
		animate(pChicken_counter);

		// mute the level music
		Config::game_music_playing = false;
		game_music.setVolume(0);
		play_sfx(SoundIndex::level_complete);
		return;
	}
}

void level_three()
{
	using Config::objects, Config::players;

	// animate the loading screen
	animate(pLoading);

	// run once at the start of the level
	if (!Config::lv3_spawned)
	{
		// reset all object attributes and booleans
		reset();

		play_bgm(MusicIndex::game_music_index);

		// sound only plays once
		game_music.stop();

		// platforms
		spawn(Config::objects[Object::platform1], 600, 30, 90, 3, 3);
		spawn(Config::objects[Object::platform2], 600, 670, 90, 3, 3);
		spawn(Config::objects[Object::platform3], 750, 870, 90, 3, 3);
		spawn(Config::objects[Object::platform4], 155, 220, 0, 2.5, 2.5);
		spawn(Config::objects[Object::platform5], 0, 450, 0, 2.5, 2.5);
		spawn(Config::objects[Object::platform6], 307, 680, 0, 2.5, 2.5);
		spawn(Config::objects[Object::platform7], 750, -57, 90, 3, 3);
		spawn(Config::objects[Object::platform8], 355, 220, 0, 2.5, 2.5);
		spawn(Config::objects[Object::platform9], 600, 325, 90, 3, 3);
		spawn(Config::objects[Object::platform10], 750, 525, 90, 3, 3);

		// Elevators
		spawn(Config::objects[Object::elevator1], 0, 220, 0, 1.5, 1.5);
		spawn(Config::objects[Object::elevator2], 800, 881);
		spawn(Config::objects[Object::elevator3], 599, 525);

		// Box
		spawn(Config::objects[Object::box], 120, 140, 0, 2.5, 2.5);

		// Doors
		spawn(Config::objects[Object::door1], 555, 449, 90, 1.3, 4.85);
		spawn(Config::objects[Object::door2], 310, 679, 90, 1.3, 4.85);
		spawn(Config::objects[Object::door3], 702, 225, 0, 1.5, 4.85);

		// Buttons
		spawn(Config::objects[Object::button1], 770, 879);
		spawn(Config::objects[Object::button2], 759, 120, 90);
		spawn(Config::objects[Object::button3], 40, 441);

		// Levers
		spawn(Config::objects[Object::lever1], 632, 395, 90);
		spawn(Config::objects[Object::lever2], 180, 420);
		spawn(Config::objects[Object::lever3], 400, 848);

		// Chickens
		spawn(Config::objects[Object::chicken1], 850, 200);
		spawn(Config::objects[Object::chicken2], 630, 480);
		spawn(Config::objects[Object::chicken3], 250, 850);

		/* Players */
		// Small Player
		s_obj.position = { 0, 0 };
		s_player.setPosition(s_obj.position);

		// Big Player
		b_obj.position = { 0, 0 };
		b_player.setPosition(b_obj.position);

		// Endgame
		end.setPosition(100, 847);

		Config::lv3_spawned = true;
	}

	if (Config::loaded && !Config::game_music_playing)
	{
		game_music.play();
		game_music.setVolume(100);
		Config::game_music_playing = true;
	}

	// elevator (1) motion
	if ((((check_lever(*Config::players[0], *Config::objects[Object::lever1]) ||
		   check_lever(*players[1], *Config::objects[Object::lever1]))) ||
		 Config::lever1_pushed) &&
		objects[Object::elevator1]->obj->position.x <= 155)
	{
		objects[Object::elevator1]->obj->position.x += .5f;
		objects[Object::elevator1]->shape->setPosition(objects[Object::elevator1]->obj->position);
	}

	// elevator (1) stops
	if (objects[Object::elevator1]->obj->position.x >= 155)
	{
		play_sfx(SoundIndex::elevator1_stop);
	}

	// elevator (2) motion
	if ((((check_lever(*Config::players[0], *Config::objects[Object::lever2]) ||
		   check_lever(*players[1], *Config::objects[Object::lever2]))) ||
		 Config::lever2_pushed) &&
		objects[Object::elevator2]->obj->position.y >= 150)
	{
		objects[Object::elevator2]->obj->position.y -= 1.f;
		objects[Object::elevator2]->shape->setPosition(objects[Object::elevator2]->obj->position);
	}

	// elevator (2) stops
	if (objects[Object::elevator2]->obj->position.y <= 150)
	{
		play_sfx(SoundIndex::elevator2_stop);
	}

	// elevator (3) motion
	if ((((check_lever(*Config::players[0], *Config::objects[Object::lever3]) ||
		   check_lever(*players[1], *Config::objects[Object::lever3]))) ||
		 Config::lever3_pushed) &&
		objects[Object::elevator3]->obj->position.y >= 90)
	{
		objects[Object::elevator3]->obj->position.y -= 1.f;
		objects[Object::elevator3]->shape->setPosition(objects[Object::elevator3]->obj->position);
	}

	// elevator (3) stops
	if (objects[Object::elevator3]->obj->position.y <= 90)
	{
		play_sfx(SoundIndex::elevator3_stop);
	}

	if (Config::game_status == 3 && Config::chicken_num == 3 &&
		players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) &&
		players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()))
	{
		Config::loaded		   = false;

		// reset the loading screen
		pLoading.obj->anim_ind = 0;
		Config::game_status	   = 4;

		Config::chicken_num	   = 0;

		// update the chicken counter
		animate(pChicken_counter);

		// mute the level music
		Config::game_music_playing = false;
		game_music.setVolume(0);
		play_sfx(SoundIndex::level_complete);

		// game over screen!
		window.draw(game_end);
		return;
	}
}
