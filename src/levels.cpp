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
sf::RectangleShape& renderable,
Object&				renderable_obj,
const float&		x,
const float&		y,
const float&		angle
)
{
	renderable_obj.position = { x, y };
	renderable.setPosition(renderable_obj.position);
	renderable.setRotation(angle);
}

void level_one()
{
	using Config::objects, Config::players;

	animate(pLoading);

	if (!Config::lv1_spawned)
	{
		reset();
		// set positions

		play_bgm(MusicIndex::game_music_index);
		game_music.stop();

		// platforms
		spawn(platform1, platform1_obj, 0, 328);
		spawn(platform2, platform1_obj, 200, 328);
		spawn(platform3, platform1_obj, 400, 328);
		spawn(platform4, platform1_obj, 600, 328);
		spawn(platform5, platform1_obj, 700, 550);
		spawn(platform6, platform1_obj, 500, 550);
		spawn(platform7, platform1_obj, 300, 550);
		spawn(platform8, platform1_obj, 0, 550);
		spawn(platform9, platform1_obj, 400, 6500);
		spawn(platform10, platform1_obj, 6000, 700);

		// Elevators
		spawn(elevator1, elevator1_obj, 195.5, 881);
		spawn(elevator2, elevator2_obj, 795, 328);
		spawn(elevator3, elevator3_obj, 6000, 700);

		// Box
		spawn(box, box_obj, 6000, 700);

		// Doors

		spawn(door1, door1_obj, 600, 0);
		door1.setScale(door1_obj.scale * 1.8, door1_obj.scale * 1.8);

		spawn(door2, door2_obj, 500, 360);
		door2.setScale(door2_obj.scale * 1, door2_obj.scale * 1);

		spawn(door3, door3_obj, 600, 700);
		door3.setScale(door3_obj.scale * 1.6, door3_obj.scale * 1.6);

		// Buttons
		spawn(button1, button1_obj, 85, 541);
		spawn(button2, button2_obj, 720, 541);
		spawn(button3, button3_obj, 280, 320);

		// Levers
		spawn(lever1, lever1_obj, 550, 297);
		spawn(lever2, lever2_obj, 400, 520);
		spawn(lever3, lever3_obj, 6000, 700);

		// Chickens
		spawn(chicken1, chicken1_obj, 850, 250);
		spawn(chicken2, chicken2_obj, 800, 800);
		spawn(chicken3, chicken3_obj, 40, 450);

		// Players
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

	if ((((check_lever(
			   *Config::players[0],
			   *Config::objects[Object::lever1]
		   ) ||
		   check_lever(*players[1], *Config::objects[Object::lever1]))) ||
		 Config::lever1_pushed) &&
		objects[Object::elevator1]->obj->position.y >= 550)
	{
		objects[Object::elevator1]->obj->position.y -= .8f;
		objects[Object::elevator1]->shape->setPosition(
		Config::objects[Object::elevator1]->obj->position
		);
	}

	if (objects[Object::elevator1]->obj->position.y <= 550)
	{
		play_sfx(SoundIndex::elevator1_stop);
	}

	if ((((check_lever(
			   *Config::players[0],
			   *Config::objects[Object::lever2]
		   ) ||
		   check_lever(*players[1], *Config::objects[Object::lever2]))) ||
		 Config::lever2_pushed) &&
		objects[Object::elevator2]->obj->position.y <= 550)
	{
		objects[Object::elevator2]->obj->position.y += .8f;
		objects[Object::elevator2]->shape->setPosition(
		Config::objects[Object::elevator2]->obj->position
		);
	}

	if (objects[Object::elevator2]->obj->position.y >= 550)
	{
		play_sfx(SoundIndex::elevator2_stop);
	}

	if (Config::game_status == 1 && Config::chicken_num == 3 &&
		players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()
		) &&
		players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()
		) &&
		Config::loaded)
	{
		Config::loaded		   = false;
		pLoading.obj->anim_ind = 0;

		animate(pLoading);

		Config::chicken_num	  = 0;
		Config::game_status	  = 2;

		chicken1_obj.position = { 500.f,
								  ground.getGlobalBounds().top -
								  chicken1.getGlobalBounds().height };
		chicken1.setPosition(chicken1_obj.position);

		chicken2_obj.position = { 550.f,
								  ground.getGlobalBounds().top -
								  chicken2.getGlobalBounds().height };
		chicken2.setPosition(chicken2_obj.position);

		chicken3_obj.position = { 600.f,
								  ground.getGlobalBounds().top -
								  chicken3.getGlobalBounds().height };
		chicken3.setPosition(chicken3_obj.position);

		animate(pChicken_counter);
		Config::game_music_playing = false;
		game_music.setVolume(0);
		play_sfx(SoundIndex::level_complete);
		return;
	}
}

void level_two()
{

	using Config::objects, Config::players;

	animate(pLoading);

	if (!Config::lv2_spawned)
	{
		reset();
		// set positions

		play_bgm(MusicIndex::game_music_index);

		// platforms
		platform1.setRotation(90);
		platform1.setScale(platform1_obj.scale, platform1_obj.scale);
		platform1_obj.position = {
			416.f,
			-45.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		platform1.setPosition(platform1_obj.position);

		platform7.setRotation(90);
		platform7.setScale(platform7_obj.scale, platform7_obj.scale);
		platform7_obj.position = {
			493.f,
			-45.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		platform7.setPosition(platform7_obj.position);

		spawn(platform2, platform2_obj, 435, 360);
		spawn(platform3, platform3_obj, 234, 360);
		spawn(platform4, platform4_obj, 704, 620);
		spawn(platform5, platform5_obj, 0, 620);
		spawn(platform6, platform6_obj, 508, 620);
		spawn(platform8, platform8_obj, 5000, 620);
		spawn(platform9, platform9_obj, 4000, 65000);
		spawn(platform10, platform10_obj, 60000, 7000);

		// Elevators
		spawn(elevator1, elevator1_obj, 195.5, 881);
		spawn(elevator2, elevator2_obj, 90, 612);
		spawn(elevator3, elevator3_obj, 700, 612);

		// Box
		spawn(box, box_obj, 195.5, 880);

		// Doors

		spawn(door1, door1_obj, 380, 150);
		door1.setScale(door1_obj.scale * 1.2, door1_obj.scale * 1.2);

		spawn(door2, door2_obj, 5000, 3600);
		door2.setScale(door2_obj.scale * 1, door2_obj.scale * 1);

		spawn(door3, door3_obj, 600, 720);
		door3.setScale(door3_obj.scale * 1.2, door3_obj.scale * 1.2);

		// Buttons
		spawn(button1, button1_obj, 5, 611);
		spawn(button2, button2_obj, 700, 5400);
		spawn(button3, button3_obj, 540, 611);

		// Levers
		spawn(lever1, lever1_obj, 600, 588);
		spawn(lever2, lever2_obj, 550, 328);
		spawn(lever3, lever3_obj, 50, 588);

		// Chickens
		spawn(chicken1, chicken1_obj, 750, 250);
		spawn(chicken2, chicken2_obj, 800, 800);
		spawn(chicken3, chicken3_obj, 140, 450);

		// Players
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

	if ((((check_lever(
			   *Config::players[0],
			   *Config::objects[Object::lever1]
		   ) ||
		   check_lever(*players[1], *Config::objects[Object::lever1]))) ||
		 Config::lever1_pushed) &&
		objects[Object::elevator1]->obj->position.y >= 620)
	{
		objects[Object::elevator1]->obj->position.y -= .8f;
		objects[Object::elevator1]->shape->setPosition(
		Config::objects[Object::elevator1]->obj->position
		);
	}
	if (objects[Object::elevator1]->obj->position.y <= 620)
	{
		play_sfx(SoundIndex::elevator1_stop);
	}

	if ((((check_lever(
			   *Config::players[0],
			   *Config::objects[Object::lever2]
		   ) ||
		   check_lever(*players[1], *Config::objects[Object::lever2]))) ||
		 Config::lever2_pushed) &&
		objects[Object::elevator2]->obj->position.y >= 360)
	{
		objects[Object::elevator2]->obj->position.y -= .8f;
		objects[Object::elevator2]->shape->setPosition(
		Config::objects[Object::elevator2]->obj->position
		);
	}
	if (objects[Object::elevator2]->obj->position.y <= 360)
	{
		play_sfx(SoundIndex::elevator2_stop);
	}

	if ((((check_lever(
			   *Config::players[0],
			   *Config::objects[Object::lever3]
		   ) ||
		   check_lever(*players[1], *Config::objects[Object::lever3]))) ||
		 Config::lever3_pushed) &&
		objects[Object::elevator3]->obj->position.y >= 360)
	{
		objects[Object::elevator3]->obj->position.y -= .8f;
		objects[Object::elevator3]->shape->setPosition(
		Config::objects[Object::elevator3]->obj->position
		);
	}
	if (objects[Object::elevator3]->obj->position.y <= 360)
	{
		play_sfx(SoundIndex::elevator3_stop);
	}

	if (Config::game_status == 2 && Config::chicken_num == 3 &&
		players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()
		) &&
		players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()
		) &&
		Config::loaded)
	{
		Config::loaded		   = false;
		pLoading.obj->anim_ind = 0;

		animate(pLoading);

		Config::chicken_num	  = 0;
		Config::game_status	  = 3;

		chicken1_obj.position = { 500.f,
								  ground.getGlobalBounds().top -
								  chicken1.getGlobalBounds().height };
		chicken1.setPosition(chicken1_obj.position);

		chicken2_obj.position = { 550.f,
								  ground.getGlobalBounds().top -
								  chicken2.getGlobalBounds().height };
		chicken2.setPosition(chicken2_obj.position);

		chicken3_obj.position = { 600.f,
								  ground.getGlobalBounds().top -
								  chicken3.getGlobalBounds().height };
		chicken3.setPosition(chicken3_obj.position);

		animate(pChicken_counter);
		Config::game_music_playing = false;
		game_music.setVolume(0);
		play_sfx(SoundIndex::level_complete);
		return;
	}
}

void level_three()
{
	using Config::objects, Config::players;

	animate(pLoading);

	if (!Config::lv3_spawned)
	{
		reset();
		// set positions

		play_bgm(MusicIndex::game_music_index);

		// set positions

		// platforms
		platform1.setRotation(90);
		platform1.setScale(3, 3);
		platform1_obj.position = {
			600.f,
			30.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		platform1.setPosition(platform1_obj.position);

		platform7.setRotation(90);
		platform7.setScale(3, 3);
		platform7_obj.position = {
			750.f,
			-57.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		platform7.setPosition(platform7_obj.position);

		platform9.setRotation(90);
		platform9.setScale(3, 3);
		platform9_obj.position = {
			600.f,
			325.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		platform9.setPosition(platform9_obj.position);

		platform10.setRotation(90);
		platform10.setScale(3, 3);
		platform10_obj.position = {
			750.f,
			525.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		platform10.setPosition(platform10_obj.position);

		platform2.setRotation(90);
		platform2.setScale(3, 3);
		platform2_obj.position = {
			600.f,
			670.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		platform2.setPosition(platform2_obj.position);

		platform3.setRotation(90);
		platform3.setScale(3, 3);
		platform3_obj.position = {
			750.f,
			870.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		platform3.setPosition(platform3_obj.position);

		spawn(platform4, platform4_obj, 155, 220);
		platform4.setScale(2.5, 2.5);
		spawn(platform5, platform5_obj, 0, 450);
		platform5.setScale(2.5, 2.5);
		spawn(platform6, platform6_obj, 307, 680);
		platform6.setScale(2.5, 2.5);
		spawn(platform8, platform8_obj, 355, 220);
		platform8.setScale(2.5, 2.5);

		// Elevators
		spawn(elevator1, elevator1_obj, 0, 220);
		elevator1.setScale(1.5, 1.5);
		spawn(elevator2, elevator2_obj, 800, 881);
		spawn(elevator3, elevator3_obj, 599, 525);

		// Box
		spawn(box, box_obj, 120, 140);
		box.setScale(2.5, 2.5);

		// Doors
		door1.setRotation(90);
		door1.setScale(1.3, 4.85);
		door1_obj.position = {
			555.f,
			449.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		door1.setPosition(door1_obj.position);

		door2.setRotation(90);
		door2.setScale(1.3, 4.85);
		door2_obj.position = {
			310.f,
			679.f /*Config::RES_SIZE / 2.f + 30.f*/
		};
		door2.setPosition(door2_obj.position);

		spawn(door3, door3_obj, 702, 225);
		door3.setScale(1.5, 4.85);

		// Buttons
		spawn(button1, button1_obj, 770, 879);
		spawn(button2, button2_obj, 759, 120);
		button2.setRotation(90);
		spawn(button3, button3_obj, 40, 441);

		// Levers
		spawn(lever1, lever1_obj, 632, 395);
		lever1.setRotation(90);
		spawn(lever2, lever2_obj, 180, 420);
		spawn(lever3, lever3_obj, 400, 848);

		// Chickens
		spawn(chicken1, chicken1_obj, 850, 200);
		spawn(chicken2, chicken2_obj, 630, 480);
		spawn(chicken3, chicken3_obj, 250, 850);

		// Players
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

	// moving the elevator
	if ((((check_lever(
			   *Config::players[0],
			   *Config::objects[Object::lever1]
		   ) ||
		   check_lever(*players[1], *Config::objects[Object::lever1]))) ||
		 Config::lever1_pushed) &&
		objects[Object::elevator1]->obj->position.x <= 155)
	{
		objects[Object::elevator1]->obj->position.x += .5f;
		objects[Object::elevator1]->shape->setPosition(
		objects[Object::elevator1]->obj->position
		);
	}
	if (objects[Object::elevator1]->obj->position.x >= 155)
	{
		play_sfx(SoundIndex::elevator1_stop);
	}

	if ((((check_lever(
			   *Config::players[0],
			   *Config::objects[Object::lever2]
		   ) ||
		   check_lever(*players[1], *Config::objects[Object::lever2]))) ||
		 Config::lever2_pushed) &&
		objects[Object::elevator2]->obj->position.y >= 150)
	{
		objects[Object::elevator2]->obj->position.y -= 1.f;
		objects[Object::elevator2]->shape->setPosition(
		objects[Object::elevator1]->obj->position
		);
	}
	if (objects[Object::elevator2]->obj->position.y <= 150)
	{
		play_sfx(SoundIndex::elevator2_stop);
	}

	if ((((check_lever(
			   *Config::players[0],
			   *Config::objects[Object::lever3]
		   ) ||
		   check_lever(*players[1], *Config::objects[Object::lever3]))) ||
		 Config::lever3_pushed) &&
		objects[Object::elevator3]->obj->position.y >= 90)
	{
		objects[Object::elevator3]->obj->position.y -= 1.f;
		objects[Object::elevator3]->shape->setPosition(
		objects[Object::elevator3]->obj->position
		);
	}
	if (objects[Object::elevator3]->obj->position.y <= 90)
	{
		play_sfx(SoundIndex::elevator3_stop);
	}

	if (Config::game_status == 3 && Config::chicken_num == 3 &&
		players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()
		) &&
		players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()
		))
	{
		Config::loaded		   = false;
		pLoading.obj->anim_ind = 0;
		Config::game_status	   = 4;

		Config::chicken_num	   = 0;

		chicken1_obj.position  = { 500.f,
								   ground.getGlobalBounds().top -
								   chicken1.getGlobalBounds().height - 20.f };
		chicken1.setPosition(chicken1_obj.position);

		chicken2_obj.position = { 550.f,
								  ground.getGlobalBounds().top -
								  chicken2.getGlobalBounds().height - 20.f };
		chicken2.setPosition(chicken2_obj.position);

		chicken3_obj.position = { 600.f,
								  ground.getGlobalBounds().top -
								  chicken3.getGlobalBounds().height - 20.f };
		chicken3.setPosition(chicken3_obj.position);

		animate(pChicken_counter);

		Config::game_music_playing = false;
		game_music.setVolume(0);
		window.draw(game_end);
		play_sfx(SoundIndex::level_complete);
		return;
	}
}
