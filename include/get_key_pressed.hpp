#pragma once
#ifndef _GET_KEY_PRESSED_HPP
#define _GET_KEY_PRESSED_HPP

#include <SFML\Graphics.hpp>
#include <Config.hpp>

using namespace sf; 
using namespace Config;

Keyboard::Key get_key_pressed_s();
Keyboard::Key get_key_pressed_b();

#endif // #ifndef _GET_KEY_PRESSED_HPP