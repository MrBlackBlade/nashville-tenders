#pragma once
#ifndef _MOVE_HPP
#define _MOVE_HPP

#include <animate.hpp>
#include <Animation.hpp>
#include <collision.hpp>
#include <Config.hpp>
#include <get_key_pressed.hpp>
#include <iostream>
#include <out_of_bounds.hpp>
#include <Pair.hpp>
#include <SFML/Graphics.hpp>

void move(Pair_Player&);
void move(Pair_Object&);

#endif // #ifndef _MOVE_HPP