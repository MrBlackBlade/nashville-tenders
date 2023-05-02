#pragma once
#ifndef _CONFIG_HPP
#define _CONFIG_HPP

#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <Object.hpp>
#include <Pair.hpp>

constexpr auto OBJECTS = 10;
constexpr auto PLAYERS = 2;

namespace Config
{
	extern const sf::Uint16 RES_SIZE;

	extern sf::Uint16 frame_counter;
	extern sf::Uint16 chicken_count;

	extern const sf::Keyboard::Key keybinds[2][4];
	
	extern bool door_opened;
	extern bool lever_pushed;

	extern Pair_Object*				  objects[OBJECTS];
	extern Pair_Player*               players[PLAYERS];
};

/* All the externs outside of Config */

// platforms and obstacles
extern sf::Texture			bg_texture;
extern sf::Sprite			background;
extern sf::Texture			ground_texture;
extern sf::RectangleShape	ground;
extern Object				ground_obj;
extern sf::Texture			box_texture;
extern sf::RectangleShape   box;
extern Object				box_obj;
extern sf::Texture			button_texture;
extern sf::RectangleShape	button;
extern Object				button_obj;
extern sf::Texture			chicken_texture;
extern sf::RectangleShape	chicken1;
extern sf::RectangleShape	chicken2;
extern sf::RectangleShape	chicken3;
extern Object				chicken1_obj;
extern Object				chicken2_obj;
extern Object				chicken3_obj;
extern sf::Texture			door_texture;
extern sf::RectangleShape	door;
extern Object				door_obj;
extern sf::Texture			elevator_texture;
extern sf::RectangleShape	elevator;
extern Object				elevator_obj;
extern sf::Texture			lever_texture;
extern sf::RectangleShape	lever;
extern Object				lever_obj;
extern sf::Texture			platform_texture;
extern sf::RectangleShape	platform;
extern Object				platform_obj;

// small player
extern sf::Texture			s_player_texture_jump;
extern sf::Texture			s_player_texture_idle;
extern sf::Texture			s_player_texture_run;
extern sf::Sprite			s_player;
extern Player				s_obj;

// big player
extern sf::Texture			b_player_texture_jump;
extern sf::Texture			b_player_texture_idle;
extern sf::Texture			b_player_texture_run;
extern sf::Texture			b_player_texture_push;
extern sf::Sprite			b_player;
extern Player				b_obj;

// window
extern sf::RenderWindow		window;

#endif // #ifndef _CONFIG_HPP