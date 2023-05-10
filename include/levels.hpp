#pragma once
#ifndef _LEVELS_HPP
#define _LEVELS_HPP

#include <check_lever.hpp>
#include <Config.hpp>
#include <sound_system.hpp>

void caller();
void spawn(Pair_Object*, const float&, const float&, const float& = 0.f, float = -1.f, float = -1.f);
void level_one();
void level_two();
void level_three();

#endif // #ifndef _LEVELS__HPP