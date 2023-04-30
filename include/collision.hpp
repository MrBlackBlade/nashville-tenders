#pragma once
#ifndef _COLLISION_HPP
#define _COLLISION_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <Object.hpp>
#include <Pair.hpp>
#include <get_key_pressed.hpp>
#include <push.hpp>

bool collision(Pair_Player&, Pair_Object&);
bool collision(Pair_Object&, Pair_Object&);

#endif // #ifndef _COLLISION_HPP