#pragma once

#include <SFML\Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <cstdint>
#include <iostream>

using namespace sf;
using namespace Config;

void move(Sprite&, Player&, Keyboard::Key);