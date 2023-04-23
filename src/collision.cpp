#include <collision.hpp>

void collision(sf::Sprite& player, Player& obj, sf::Sprite& ground)
{
	if (player.getGlobalBounds().intersects(ground.getGlobalBounds()))
	{
		// collision from top
		obj.position = 
		{
			player.getPosition().x,
			ground.getGlobalBounds().top - player.getGlobalBounds().height
		};
		player.setPosition(obj.position);

		obj.velocity.y = 0;
		obj.jump_ind   = 0;
		obj.jumping    = false;
	}
}