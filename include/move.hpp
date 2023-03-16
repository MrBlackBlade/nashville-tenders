#pragma once
#ifndef _MOVE_HPP
#define _MOVE_HPP

#include <SFML\Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <cstdint>
#include <iostream>

using namespace sf;
using namespace Config;

void move(Sprite&, Player&, Keyboard::Key);

#endif // #ifndef _MOVE_HPP