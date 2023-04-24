#pragma once
#ifndef _MOVE_HPP
#define _MOVE_HPP

#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <animate.hpp>
#include <Animation.hpp>
#include <iostream>

void move(sf::Sprite&, Player&, const sf::Keyboard::Key&);
void move(sf::RectangleShape&, Player&);

#endif // #ifndef _MOVE_HPP