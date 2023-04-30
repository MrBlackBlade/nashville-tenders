#pragma once
#ifndef _MOVE_HPP
#define _MOVE_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Pair.hpp>
#include <animate.hpp>
#include <Animation.hpp>
#include <iostream>
#include <get_key_pressed.hpp>

void move(Pair_Player&);
void move(Pair_Object&);

#endif // #ifndef _MOVE_HPP