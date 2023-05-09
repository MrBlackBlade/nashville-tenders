#pragma once
#ifndef _COLLISION_HPP
#define _COLLISION_HPP

#include <CollisionType.hpp>
#include <Config.hpp>
#include <door_open.hpp>
#include <get_key_pressed.hpp>
#include <Object.hpp>
#include <Pair.hpp>
#include <Player.hpp>
#include <push.hpp>
#include <SFML/Graphics.hpp>

CollisionType collision(Pair_Player&, Pair_Object&);
CollisionType collision(Pair_Object&, Pair_Object&);

#endif // #ifndef _COLLISION_HPP