#pragma once
#ifndef _COLLISION_HPP
#define _COLLISION_HPP

#include <SFML\Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>

void collision(sf::Sprite&, Player&, sf::RectangleShape&);
void collision(sf::RectangleShape&, Player&, sf::RectangleShape&);

#endif // #ifndef _COLLISION_HPP