#include <collision.hpp>

extern sf::Texture  platform_texture;
extern sf::Sprite   platform_s;
extern Player	    s_obj;
extern sf::Texture  s_player_texture_run;
extern sf::Texture  s_player_texture_idle;
extern sf::Texture  s_player_texture_jump;
extern sf::Sprite   s_player;
extern Player	    b_obj;
extern sf::Texture  b_player_texture_run;
extern sf::Texture  b_player_texture_idle;
extern sf::Sprite   b_player;

void collision(sf::Sprite& player, Player& obj, sf::Sprite& ground)
{
	if (player.getGlobalBounds().intersects(ground.getGlobalBounds()))
	{
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