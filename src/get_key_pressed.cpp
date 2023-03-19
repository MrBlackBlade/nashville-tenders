#include <get_key_pressed.hpp>

Keyboard::Key get_key_pressed_b()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
		return Keyboard::W;
	if (Keyboard::isKeyPressed(Keyboard::A))
		return Keyboard::A;
	if (Keyboard::isKeyPressed(Keyboard::S))
		return Keyboard::S;
	if (Keyboard::isKeyPressed(Keyboard::D))
		return Keyboard::D;
}

Keyboard::Key get_key_pressed_s()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
		return Keyboard::Up;
	if (Keyboard::isKeyPressed(Keyboard::Left))
		return Keyboard::Left;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		return Keyboard::Down;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		return Keyboard::Right;
}