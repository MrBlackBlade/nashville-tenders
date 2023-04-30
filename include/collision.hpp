#pragma once
#ifndef _COLLISION_HPP
#define _COLLISION_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <Object.hpp>

void collision(Pair&, sf::RectangleShape&);
void collision(sf::RectangleShape&, Object&, sf::RectangleShape&);

#endif // #ifndef _COLLISION_HPP