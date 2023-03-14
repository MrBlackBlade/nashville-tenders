#pragma once

#include <SFML\Graphics.hpp>
#include <Config.hpp>
#include <cstdint>

using namespace sf;
using namespace Config;

void move_s(Sprite&, Keyboard::Key);
void move_b(Sprite&, Keyboard::Key);