#include <collision.hpp>

void collision(sf::Sprite& player, Player& obj, sf::RectangleShape& shape)
{
	if (player.getGlobalBounds().intersects(shape.getGlobalBounds()))
	{
		// collision from top
		obj.position = 
		{
			player.getPosition().x,
			shape.getGlobalBounds().top - player.getGlobalBounds().height
		};
		player.setPosition(obj.position);

		obj.velocity.y = 0;
		obj.jump_ind   = 0;
		obj.jumping    = false;
	}
}

void collision(sf::RectangleShape& shape1, Player& obj, sf::RectangleShape& shape2)
{
	if (shape1.getGlobalBounds().intersects(shape2.getGlobalBounds()))
	{
		// collision from top
		obj.position = 
		{
			shape1.getPosition().x,
			shape2.getGlobalBounds().top - shape1.getGlobalBounds().height
		};
		shape1.setPosition(obj.position);

		obj.velocity.y = 0;
		obj.jump_ind   = 0;
		obj.jumping    = false;
	}
}