#include <collision.hpp>

extern Texture platform_texture;
extern Sprite platfrom_s;

extern Player  s_obj;
extern Texture s_player_texture_run;
extern Texture s_player_texture_idle;
extern Texture s_player_texture_jump;
extern Sprite  s_player;

extern Player  b_obj;
extern Texture b_player_texture_run;
extern Texture b_player_texture_idle;
extern Sprite  b_player;

extern float velocity_y;
extern float gravity;
extern bool  isJumping;

void collision(Sprite& s_player, Sprite& platform_s)
{
	getXposition(s_player);

	if (b_player.getGlobalBounds().intersects(platform_s.getGlobalBounds()))
	{
		b_player.setPosition(getXposition(b_player).x, RES_SIZE - 84);
	}

	if (s_player.getGlobalBounds().intersects(platform_s.getGlobalBounds()))
	{
		s_player.setPosition(getXposition(s_player).x, RES_SIZE - 70);
		s_obj.jump_ind = 0;
		gravity = 0;
		velocity_y = 0;
	}
	else
	{
		gravity = 0.5;
	}
}