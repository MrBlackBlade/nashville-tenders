#include <animate.hpp>

void animate ( Pair_Player& pair, const Animation& anim )
{
    auto& player = *pair.sprite;
    auto& obj = *pair.obj;
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
        if (Config::frame_counter % (obj.id == 0 ? 14 : 14) == 0)
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

    case Animation::push:
        if (Config::frame_counter % 14 == 0 && obj.id == 1)
        {
            player.setTexture (b_player_texture_push);

            player.setTextureRect
            (
                sf::IntRect
                (
                    obj.push_ind * obj.size_push_x, 0,
                    obj.size_push_x, obj.size_push_y
                )
            );

            obj.push_ind++;
            obj.push_ind %= obj.anims_push;
        }

        return;
	}
}

void animate ( Pair_Object& pair )
{
    auto& shape = *pair.shape;
    auto& obj = *pair.obj;

    if (Config::frame_counter % 12 == 0 && obj.anims)
    {
        /*switch (obj.id)
        {
        case Object::button:

            return;

        case Object::lever:
            return;

        case Object::door:
            return;

        case Object::chicken:
            return;

        default:
            return;
        }*/

        shape.setTextureRect
        (
            sf::IntRect
            (
                obj.anim_ind * obj.size_x, 0,
                obj.size_x, obj.size_y
            )
        );

        obj.anim_ind++;
        obj.anim_ind %= obj.anims;
    }
}