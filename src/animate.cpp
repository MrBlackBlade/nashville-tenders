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
        if (Config::frame_counter % (obj.id == 0 ? 12 : 14) == 0)
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

    // door animations
    if (obj.id == Object::door)
    {
        if (Config::objects[Object::button]->obj->anim_ind == 1 && !Config::door_opened)
        {
            if (Config::frame_counter % 12 == 0 && obj.anims)
            {
                shape.setTextureRect
                (
                    sf::IntRect
                    (
                        obj.anim_ind * obj.size_x, 0,
                        obj.size_x, obj.size_y
                    )
                );

                // door opened
                if (obj.anim_ind == 4) 
                {
                    Config::door_opened = true;
                    return;
                }


                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }

        return;
    }

    else if (obj.id == Object::button)
    {
        if (collision(*Config::players[0], pair) == CollisionType::player_button || collision(*Config::players[1], pair) == CollisionType::player_button
            || collision(*Config::objects[Object::box],*Config::objects[Object::button]) == CollisionType::box_button)
        {
            if (Config::frame_counter % 6 == 0 )
            {
                shape.setTextureRect
                (
                    sf::IntRect
                    (
                        obj.anim_ind * obj.size_x, 0,
                        obj.size_x, obj.size_y
                    )
                );

                // button pressed
                if (obj.anim_ind == 1)
                    return;

                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }
    }

    else if (obj.id == Object::lever)
    {
        if (elevator_move(*Config::players[0], pair)|| elevator_move(*Config::players[1], pair) && !Config::lever_pushed)
        {
            if (Config::frame_counter % 4 == 0)
            {
                shape.setTextureRect
                (
                    sf::IntRect
                    (
                        obj.anim_ind * obj.size_x, 0,
                        obj.size_x, obj.size_y
                    )
                );

                // lever pushed
                if (obj.anim_ind == 2)
                {
                    Config::lever_pushed = true;
                    return;
                }

                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }
    }
        // other objects
    else
    {
        if (Config::frame_counter % 12 == 0 && obj.anims)
        {
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
}