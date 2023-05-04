#pragma once
#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <SFML/Graphics.hpp>

struct Object
{
	enum ObjectEnum
	{
		ground,
		button,
		box,
		chicken1,
		chicken2,
		chicken3,
		door,
		elevator,
		lever,
		platform,

		object_max,
	};

	ObjectEnum id;

	sf::Vector2f
		velocity,
		velocity_max,
		acceleration,
		position;

	sf::Uint16
		// 0 for first sprite, 1 for second etc...
		anim_ind;

	float
		// sprite measurements
		scale;

	sf::Uint16
		size_x,
		size_y,

		// no of diff animation frames
		anims;
};

#endif // #ifndef _OBJECT_HPP