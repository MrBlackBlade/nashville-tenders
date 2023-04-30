#pragma once
#ifndef _PUSH_HPP
#define _PUSH_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <Object.hpp>
#include <animate.hpp>
#include <Animation.hpp>
#include <collision.hpp>
#include <get_key_pressed.hpp>

bool push(Pair_Player&, Pair_Object&);

#endif // #ifndef _PUSH_HPP