#pragma once
#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <SFML/Graphics.hpp>

struct Object
{
	enum ObjectEnum
	{
		ground,
		button1,
		button2,
		button3,
		box,
		chicken1,
		chicken2,
		chicken3,
		door1,
		door2,
		door3,
		elevator1,
		elevator2,
		elevator3,
		lever1,
		lever2,
		lever3,
		platform,
		loading,
		chicken_counter,

		object_max,
	};

	ObjectEnum	 id;

	sf::Vector2f velocity, velocity_max, acceleration, position;

	// 0 for first sprite, 1 for second etc...
	sf::Uint16 anim_ind;

	// sprite measurements
	float	   scale;

	sf::Uint16 size_x, size_y,

		anims; // no of diff animation frames
};

#endif // #ifndef _OBJECT_HPP