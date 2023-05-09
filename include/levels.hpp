#pragma once
#ifndef _LEVELS_HPP
#define _LEVELS_HPP

#include <check_lever.hpp>
#include <collect.hpp>
#include <collision.hpp>
#include <CollisionType.hpp>
#include <Config.hpp>
#include <sound_system.hpp>

void caller();
void spawn(sf::RectangleShape&, Object&, const float&, const float&, const float& angle = 0);
void level_one();
void level_two();
void level_three();

#endif // #ifndef _LEVELS__HPP