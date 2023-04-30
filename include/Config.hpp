#pragma once
#ifndef _CONFIG_HPP
#define _CONFIG_HPP

#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <Object.hpp>
#include <Pair.hpp>

constexpr auto OBJECTS = 2;
constexpr auto PLAYERS = 2;

namespace Config
{
	extern const sf::Uint16 RES_SIZE;

	extern sf::Uint16 frame_counter;

	extern const sf::Keyboard::Key keybinds[2][4];
	
	extern Pair_Object*				  objects[OBJECTS];
	extern Pair_Player*               players[PLAYERS];	
};

/* All the externs outside of Config */

// platforms and obstacles
extern sf::Texture			bg_texture;
extern sf::Sprite			background;
extern sf::Texture			ground_texture;
extern sf::RectangleShape	ground;
extern sf::Texture			box_texture;
extern sf::RectangleShape   box;
extern Object				box_obj;
extern Object				ground_obj;

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
extern sf::Sprite			b_player;
extern Player				b_obj;

// window
extern sf::RenderWindow		window;

#endif // #ifndef _CONFIG_HPP