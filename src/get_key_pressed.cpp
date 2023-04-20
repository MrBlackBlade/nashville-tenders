#include <get_key_pressed.hpp>

sf::Keyboard::Key get_key_pressed(const Player& obj)
{
	// big player
	if (obj.id)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			return sf::Keyboard::W;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			return sf::Keyboard::A;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			return sf::Keyboard::S;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			return sf::Keyboard::D;
		return sf::Keyboard::Unknown;
	}

	// small player
	else 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			return sf::Keyboard::Up;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			return sf::Keyboard::Left;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			return sf::Keyboard::Down;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			return sf::Keyboard::Right;	
		return sf::Keyboard::Unknown;
	}
}