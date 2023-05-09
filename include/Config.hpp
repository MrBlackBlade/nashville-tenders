#pragma once
#ifndef _CONFIG_HPP
#define _CONFIG_HPP

#include <Object.hpp>
#include <Pair.hpp>
#include <Player.hpp>
#include <reset.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

constexpr auto OBJECTS = 27;
constexpr auto PLAYERS = 2;

namespace Config
{
extern const sf::Uint16		   RES_SIZE;
extern sf::Uint16			   frame_counter;
extern sf::Uint16			   game_status;
extern sf::Uint16			   chicken_num;

extern sf::Int32			   menu_selection;
extern sf::Int32			   menu_status;

extern const sf::Keyboard::Key keybinds[2][4];

extern bool					   loaded;

extern bool					   door1_opened;
extern bool					   door2_opened;
extern bool					   door3_opened;

extern bool					   lever1_pushed;
extern bool					   lever2_pushed;
extern bool					   lever3_pushed;

extern bool					   button1_pushed;
extern bool					   button2_pushed;
extern bool					   button3_pushed;

extern bool					   lv1_spawned;
extern bool					   lv2_spawned;
extern bool					   lv3_spawned;

extern bool					   game_music_playing;

extern Pair_Object*			   objects[OBJECTS];
extern Pair_Player*			   players[PLAYERS];
};

/* All the externs outside of Config */

// menu
extern sf::Text			  main_menu[2];
extern sf::Font			  font;
extern sf::Texture		  menu_texture;
extern sf::RectangleShape menu;
extern sf::Texture		  chicken_counter_texture;
extern sf::RectangleShape chicken_counter;
extern Object			  chicken_counter_obj;
extern Pair_Object		  pChicken_counter;

// music and sound
extern sf::Music	   main_menu_music;
extern sf::Music	   game_music;

extern sf::SoundBuffer chicken_collect_sound_buffer;
extern sf::Sound	   chicken_collect_sound;
extern sf::SoundBuffer elevator1_move_sound_buffer;
extern sf::SoundBuffer elevator2_move_sound_buffer;
extern sf::SoundBuffer elevator3_move_sound_buffer;
extern sf::Sound	   elevator1_move_sound;
extern sf::Sound	   elevator2_move_sound;
extern sf::Sound	   elevator3_move_sound;
extern sf::SoundBuffer lever_pull_sound_buffer;
extern sf::Sound	   lever_pull_sound;
extern sf::SoundBuffer button_push_sound_buffer;
extern sf::Sound	   button_push_sound;
extern sf::SoundBuffer door_open_sound_buffer;
extern sf::Sound	   door_open_sound;
extern sf::SoundBuffer level_complete_sound_buffer;
extern sf::Sound	   level_complete_sound;

// platforms and obstacles
extern sf::Texture		  game_end_texture;
extern sf::Sprite		  game_end;

extern sf::Texture		  loading_texture;
extern sf::RectangleShape loading;
extern Object			  loading_obj;
extern Pair_Object		  pLoading;

extern sf::Texture		  bg_texture;
extern sf::Sprite		  background_1;
extern sf::Sprite		  background_2;
extern sf::Sprite		  background_3;
extern sf::Sprite		  background_4;

extern sf::Texture		  ground_texture;
extern sf::RectangleShape ground;
extern Object			  ground_obj;

extern sf::Texture		  box_texture;
extern sf::RectangleShape box;
extern Object			  box_obj;

extern sf::RectangleShape lv_comp;
extern sf::Texture		  lv_comp_texture;
extern Object			  lv_comp_obj;

extern sf::Texture		  button_texture;
extern sf::RectangleShape button1;
extern sf::RectangleShape button2;
extern sf::RectangleShape button3;
extern Object			  button1_obj;
extern Object			  button2_obj;
extern Object			  button3_obj;

extern sf::Texture		  chicken_texture;
extern sf::RectangleShape chicken1;
extern sf::RectangleShape chicken2;
extern sf::RectangleShape chicken3;
extern Object			  chicken1_obj;
extern Object			  chicken2_obj;
extern Object			  chicken3_obj;

extern sf::Texture		  door_texture;
extern sf::RectangleShape door1;
extern sf::RectangleShape door2;
extern sf::RectangleShape door3;
extern Object			  door1_obj;
extern Object			  door2_obj;
extern Object			  door3_obj;

extern sf::Texture		  elevator_texture;
extern sf::RectangleShape elevator1;
extern sf::RectangleShape elevator2;
extern sf::RectangleShape elevator3;
extern Object			  elevator1_obj;
extern Object			  elevator2_obj;
extern Object			  elevator3_obj;

extern sf::Texture		  lever_texture;
extern sf::RectangleShape lever1;
extern sf::RectangleShape lever2;
extern sf::RectangleShape lever3;
extern Object			  lever1_obj;
extern Object			  lever2_obj;
extern Object			  lever3_obj;

extern sf::Texture		  platform_texture;
extern sf::RectangleShape platform1;
extern sf::RectangleShape platform2;
extern sf::RectangleShape platform3;
extern sf::RectangleShape platform4;
extern sf::RectangleShape platform5;
extern sf::RectangleShape platform6;
extern sf::RectangleShape platform7;
extern sf::RectangleShape platform8;
extern sf::RectangleShape platform9;
extern sf::RectangleShape platform10;
extern Object			  platform1_obj;
extern Object			  platform2_obj;
extern Object			  platform3_obj;
extern Object			  platform4_obj;
extern Object			  platform5_obj;
extern Object			  platform6_obj;
extern Object			  platform7_obj;
extern Object			  platform8_obj;
extern Object			  platform9_obj;
extern Object			  platform10_obj;

extern sf::Texture		  end_texture;
extern sf::RectangleShape end;

// small player
extern sf::Texture s_player_texture_jump;
extern sf::Texture s_player_texture_idle;
extern sf::Texture s_player_texture_run;
extern sf::Sprite  s_player;
extern Player	   s_obj;

// big player
extern sf::Texture b_player_texture_jump;
extern sf::Texture b_player_texture_idle;
extern sf::Texture b_player_texture_run;
extern sf::Texture b_player_texture_push;
extern sf::Sprite  b_player;
extern Player	   b_obj;

// window
extern sf::RenderWindow window;

#endif // #ifndef _CONFIG_HPP