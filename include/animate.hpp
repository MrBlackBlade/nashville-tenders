#pragma once
#ifndef _ANIMATE_HPP
#define	_ANIMATE_HPP

#include <SFML\Graphics.hpp>
#include <Config.hpp>
#include <Animation.hpp>

void animate(sf::Sprite&, Player&, const Animation&);

#endif // #ifndef _ANIMATE_HPP