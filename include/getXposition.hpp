#pragma once
#ifndef _GETXPOSITION_HPP
#define _GETXPOSITION_HPP

#include <SFML\Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <cstdint>
#include <iostream>

using namespace sf;
using namespace Config;
Vector2f getXposition(Sprite&);

#endif // #ifndef _GETXPOSITION_HPP