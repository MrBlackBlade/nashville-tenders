#include "..\include\get_key_pressed.hpp"

Keyboard::Key get_key_pressed()
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