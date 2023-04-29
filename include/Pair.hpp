#pragma once
#ifndef _PAIR_HPP

#include <SFML/Graphics.hpp>
#include <Player.hpp>

struct Pair
{
	sf::Sprite* sprite = nullptr;
	Player*     obj = nullptr;
};

#endif // #ifndef _PAIR_HPP
