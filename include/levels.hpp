#pragma once
#ifndef _LEVELS_HPP
#define _LEVELS_HPP

#include <Config.hpp>
#include <elevator_move.hpp>
#include <collision.hpp>
#include <CollisionType.hpp>
#include <collect.hpp>

void caller();
void spawn(sf::RectangleShape&, Object&, const float&, const float&);
void level_one();
void level_two();
void level_three();

#endif // #ifndef _LEVELS__HPP