#pragma once
#ifndef _MOVE_HPP
#define _MOVE_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Pair.hpp>
#include <animate.hpp>
#include <Animation.hpp>
#include <iostream>

void move(Pair&, const sf::Keyboard::Key&);
void move(sf::RectangleShape&, Object&);

#endif // #ifndef _MOVE_HPP