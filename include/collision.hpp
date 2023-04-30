#pragma once
#ifndef _COLLISION_HPP
#define _COLLISION_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <Object.hpp>
#include <Pair.hpp>

void collision(Pair_Player&, Pair_Object&);
void collision(Pair_Object&, Pair_Object&);

#endif // #ifndef _COLLISION_HPP