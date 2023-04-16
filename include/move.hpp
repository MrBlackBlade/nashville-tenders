#pragma once
#ifndef _MOVE_HPP
#define _MOVE_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <iostream>

void move(sf::Sprite&, Player&, const sf::Keyboard::Key&);

#endif // #ifndef _MOVE_HPP