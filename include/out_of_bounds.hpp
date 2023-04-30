#pragma once
#ifndef _OUT_OF_BOUNDS_HPP

#include <SFML/Graphics.hpp>
#include <animate.hpp>
#include <Animation.hpp>
#include <check_idle.hpp>
#include <collision.hpp>
#include <Config.hpp>
#include <get_key_pressed.hpp>
#include <push.hpp>
#include <move.hpp>
#include <Player.hpp>
#include <Pair.hpp>
#include <Object.hpp>
#include <render.hpp>
#include <setup.hpp>

bool out_of_bounds(Pair_Player&);
bool out_of_bounds(Pair_Object&);

#endif // #ifndef _OUT_OF_BOUNDS_HPP