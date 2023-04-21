#pragma once
#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>

struct Player
{
	sf::Vector2f
		velocity,
		velocity_max,
		acceleration,
		position;

	sf::Int32
		// 0 for first sprite, 1 for second etc...
		idle_ind,
		run_ind,
		jump_ind,

		// sprite measurements
		player_scale,

		sprite_size_idle,
		sprite_sizeH_idle,

		sprite_size_run,
		sprite_sizeH_run,

		sprite_size_jump,
		sprite_sizeH_jump,

		// no of diff animations
		anims_idle,
		anims_run,
		anims_jump;

		// player speed	
		//velocity,
		//velocity_max;

	sf::Int16 id;

	bool
		jumping,
		idle;
};

#endif // #ifndef _PLAYER_HPP