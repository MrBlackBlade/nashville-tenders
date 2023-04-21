#include <animate.hpp>

extern sf::Texture s_player_texture_jump;
extern sf::Texture s_player_texture_idle;
extern sf::Texture s_player_texture_run;
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
                obj.run_ind * obj.sprite_size_run, 0,
                obj.sprite_size_run - (obj.id == 0 ? .5f : 0.f), obj.sprite_sizeH_run
                )
            );

            obj.run_ind++;
            obj.run_ind %= obj.anims_run;
        }
        break;

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
                obj.idle_ind * obj.sprite_size_idle, 0,
                obj.sprite_size_idle, obj.sprite_sizeH_idle
                )
            );

            obj.idle_ind++;
            obj.idle_ind %= obj.anims_idle;
        }
        break;

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
                obj.jump_ind * obj.sprite_size_jump, 0,
                obj.sprite_size_jump, obj.sprite_sizeH_jump
                )
            );

            obj.jump_ind++;
            obj.jump_ind %= obj.anims_jump;
        }
        break;
	}
}