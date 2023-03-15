#pragma once

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <cstdint>
#include <Player.hpp>
#include <get_key_pressed.hpp>

using namespace sf;
using namespace Config;

void check_idle(Sprite&, Player&);