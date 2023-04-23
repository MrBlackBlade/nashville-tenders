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

	sf::Uint16
	// 0 for first sprite, 1 for second etc...
	idle_ind,
	run_ind,
	jump_ind,

	// sprite measurements
	scale,

	size_idle_x,
	size_idle_y,

	size_run_x,
	size_run_y,

	size_jump_x,
	size_jump_y,

	// no of diff animation frames
	anims_idle,
	anims_run,
	anims_jump,

	// player id
	id;

	bool
	jumping,
	idle;
};

#endif // #ifndef _PLAYER_HPP