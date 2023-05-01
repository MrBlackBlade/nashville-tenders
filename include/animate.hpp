#pragma once
#ifndef _ANIMATE_HPP
#define	_ANIMATE_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Animation.hpp>
#include <Player.hpp>
#include <Pair.hpp>
#include <collision.hpp>

void animate(Pair_Player&, const Animation&);
void animate(Pair_Object&);

#endif // #ifndef _ANIMATE_HPP