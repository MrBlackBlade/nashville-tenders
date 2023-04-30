#pragma once
#ifndef _GET_KEY_PRESSED_HPP
#define _GET_KEY_PRESSED_HPP

#include <SFML/Graphics.hpp>
#include <Config.hpp>
#include <Player.hpp>
#include <Pair.hpp>


sf::Keyboard::Key get_key_pressed(const Pair_Player&);

#endif // #ifndef _GET_KEY_PRESSED_HPP