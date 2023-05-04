#pragma once
#ifndef _COLLISION_TYPE_HPP
#define _COLLISION_TYPE_HPP

enum class CollisionType
{
	box,
	button,	// double checking for the player pressing the button		// double checking for the box pressing the button
	door,
	player_chicken,
	
	null,
};

#endif // #ifndef _COLLISION_TYPE_HPP