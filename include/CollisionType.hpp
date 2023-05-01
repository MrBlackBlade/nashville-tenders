#pragma once
#ifndef _COLLISION_TYPE_HPP
#define _COLLISION_TYPE_HPP

enum class CollisionType
{
	box,
	player_button,	// double checking for the player pressing the button
	box_button,		// double checking for the box pressing the button
	door,
	
	null,
};

#endif // #ifndef _COLLISION_TYPE_HPP