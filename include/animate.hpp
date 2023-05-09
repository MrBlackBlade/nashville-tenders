#pragma once
#ifndef _ANIMATE_HPP
#define _ANIMATE_HPP

#include <Animation.hpp>
#include <check_lever.hpp>
#include <collision.hpp>
#include <Config.hpp>
#include <Pair.hpp>
#include <Player.hpp>
#include <SFML/Graphics.hpp>
#include <sound_system.hpp>

void animate(Pair_Player&, const Animation&);
void animate(Pair_Object&);

#endif // #ifndef _ANIMATE_HPP