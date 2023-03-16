#pragma once
#ifndef _CHECK_IDLE_HPP
#define _CHECK_IDLE_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <get_key_pressed.hpp>
#include <cstdint>

using namespace sf;
using namespace Config;

void check_idle(Sprite&, Player&);

#endif // #ifndef _CHECK_IDLE_HPP