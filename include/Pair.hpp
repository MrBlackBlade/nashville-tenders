#pragma once
#ifndef _PAIR_HPP

#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <Object.hpp>

//Players
struct Pair_Player
{
	sf::Sprite* sprite = nullptr;
	Player*     obj = nullptr;
};


//Objects
struct Pair_Object
{
	sf::RectangleShape* shape = nullptr;
	Object*				obj = nullptr;
};


#endif // #ifndef _PAIR_HPP
