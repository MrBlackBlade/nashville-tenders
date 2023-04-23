#include <animate.hpp>

// small player
extern sf::Texture s_player_texture_jump;
extern sf::Texture s_player_texture_idle;
extern sf::Texture s_player_texture_run;

// big player
extern sf::Texture b_player_texture_jump;
extern sf::Texture b_player_texture_idle;
extern sf::Texture b_player_texture_run;

void animate ( sf::Sprite& player, Player& obj, const Animation& anim )
{
    switch ( anim )
    {
    case Animation::run:
        if ( Config::frame_counter % ( obj.id == 0 ? 14 : 14 ) == 0 )
        {
            player.setTexture
            (
                obj.id == 0 ? s_player_texture_run : b_player_texture_run
            );

            player.setTextureRect
            (
                sf::IntRect
                (
                obj.run_ind * obj.size_run_x, 0,
                obj.size_run_x - (obj.id == 0 ? .5f : 0.f), obj.size_run_y
                )
            );

            obj.run_ind++;
            obj.run_ind %= obj.anims_run;
        }

        return;

    case Animation::idle:
        if ( Config::frame_counter % ( obj.id == 0 ? 14 : 14 ) == 0 )
        {
            player.setTexture
            (
                obj.id == 0 ? s_player_texture_idle : b_player_texture_idle
            );

            player.setTextureRect
            (
                sf::IntRect
                (
                obj.idle_ind * obj.size_idle_x, 0,
                obj.size_idle_x, obj.size_idle_y
                )
            );

            obj.idle_ind++;
            obj.idle_ind %= obj.anims_idle;
        }

        return;

    case Animation::jump:
        if ( Config::frame_counter % ( obj.id == 0 ? 14 : 14 ) == 0 )
        {
            player.setTexture
            (
                obj.id == 0 ? s_player_texture_jump : b_player_texture_jump
            );

            player.setTextureRect
            (
                sf::IntRect
                (
                obj.jump_ind * obj.size_jump_x, 0,
                obj.size_jump_x, obj.size_jump_y
                )
            );

            obj.jump_ind++;
            obj.jump_ind %= obj.anims_jump;
        }

        return;
	}
}