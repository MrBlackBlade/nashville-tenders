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
#include <CollisionType.hpp>
#include <door_open.hpp>

CollisionType collision(Pair_Player&, Pair_Object&);
CollisionType collision(Pair_Object&, Pair_Object&);

#endif // #ifndef _COLLISION_HPP