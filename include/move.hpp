#pragma once
#ifndef _MOVE_HPP
#define _MOVE_HPP

#include <animate.hpp>
#include <Animation.hpp>
#include <Config.hpp>
#include <get_key_pressed.hpp>
#include <out_of_bounds.hpp>
#include <Pair.hpp>
#include <SFML/Graphics.hpp>

void apply_motion(Pair_Player&);
void apply_motion(Pair_Object&);
void move(Pair_Player&);

#endif // #ifndef _MOVE_HPP