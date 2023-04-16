#include <collision.hpp>

extern sf::Texture platform_texture;
extern sf::Sprite  platform_s;
extern Player  s_obj;
extern sf::Texture s_player_texture_run;
extern sf::Texture s_player_texture_idle;
extern sf::Texture s_player_texture_jump;
extern sf::Sprite  s_player;
extern Player  b_obj;
extern sf::Texture b_player_texture_run;
extern sf::Texture b_player_texture_idle;
extern sf::Sprite  b_player;
extern float velocity_y;
extern float gravity;

void collision(sf::Sprite& s_player, sf::Sprite& platform_s)
{
	if (b_player.getGlobalBounds().intersects(platform_s.getGlobalBounds()))
	{
		b_player.setPosition(b_player.getPosition().x, Config::RES_SIZE - 84);
	}

	if (s_player.getGlobalBounds().intersects(platform_s.getGlobalBounds()))
	{
		s_player.setPosition(s_player.getPosition().x, Config::RES_SIZE - 70);
		s_obj.jump_ind = 0;
		gravity = 0;
		velocity_y = 0;
	}
	else
	{
		gravity = 0.5;
	}
}