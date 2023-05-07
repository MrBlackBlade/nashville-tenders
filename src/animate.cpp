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

void
animate(Pair_Object& pair)
{
    auto& shape = *pair.shape;
    auto& obj = *pair.obj;

    switch (obj.id)
    {
    case Object::door1:
        if (Config::objects[Object::button1]->obj->anim_ind == 1 && !Config::door1_opened)
        {
            if (Config::frame_counter % 12 == 0 && obj.anims)
            {
                shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

                // door opened
                if (obj.anim_ind == 4)
                {
                    Config::door1_opened = true;
                    return;
                }

                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }

        return;
    case Object::door2:
        if (Config::objects[Object::button2]->obj->anim_ind == 1 && !Config::door2_opened)
        {
            if (Config::frame_counter % 12 == 0 && obj.anims)
            {
                shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

                // door opened
                if (obj.anim_ind == 4)
                {
                    Config::door2_opened = true;
                    return;
                }

                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }

        return;
    case Object::door3:
        if (Config::objects[Object::button3]->obj->anim_ind == 1 && !Config::door3_opened)
        {
            if (Config::frame_counter % 12 == 0 && obj.anims)
            {
                shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

                // door opened
                if (obj.anim_ind == 4)
                {
                    Config::door3_opened = true;
                    return;
                }

                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }

        return;
    case Object::button1:
        if (collision(*Config::players[0], pair) == CollisionType::button ||
            collision(*Config::players[1], pair) == CollisionType::button ||
            collision(*Config::objects[Object::box], *Config::objects[Object::button1]) == CollisionType::button)
        {
            shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

            // button pressed
            if (obj.anim_ind == 1) return;

            obj.anim_ind++;
            obj.anim_ind %= obj.anims;
        }

        return;
    case Object::button2:
        if (collision(*Config::players[0], pair) == CollisionType::button ||
            collision(*Config::players[1], pair) == CollisionType::button ||
            collision(*Config::objects[Object::box], *Config::objects[Object::button2]) == CollisionType::button)
        {
            shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

            // button pressed
            if (obj.anim_ind == 1) return;

            obj.anim_ind++;
            obj.anim_ind %= obj.anims;
        }

        return;
    case Object::button3:
        if (collision(*Config::players[0], pair) == CollisionType::button ||
            collision(*Config::players[1], pair) == CollisionType::button ||
            collision(*Config::objects[Object::box], *Config::objects[Object::button3]) == CollisionType::button)
        {
            shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

            // button pressed
            if (obj.anim_ind == 1) return;

            obj.anim_ind++;
            obj.anim_ind %= obj.anims;
        }

        return;
    case Object::lever1:
        if (check_lever(*Config::players[0], pair) ||
            check_lever(*Config::players[1], pair) && !Config::lever1_pushed)
        {
            if (Config::frame_counter % 2 == 0)
            {
                shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

                // lever pushed
                if (obj.anim_ind == 2)
                {
                    Config::lever1_pushed = true;
                    return;
                }

                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }

        return;
    case Object::lever2:
        if (check_lever(*Config::players[0], pair) ||
            check_lever(*Config::players[1], pair) && !Config::lever2_pushed)
        {
            if (Config::frame_counter % 2 == 0)
            {
                shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

                // lever pushed
                if (obj.anim_ind == 2)
                {
                    Config::lever2_pushed = true;
                    return;
                }

                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }

        return;
    case Object::lever3:
        if (check_lever(*Config::players[0], pair) ||
            check_lever(*Config::players[1], pair) && !Config::lever3_pushed)
        {
            if (Config::frame_counter % 2 == 0)
            {
                shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

                // lever pushed
                if (obj.anim_ind == 2)
                {
                    Config::lever3_pushed = true;
                    return;
                }

                obj.anim_ind++;
                obj.anim_ind %= obj.anims;
            }
        }

        return;
    case Object::loading:
        if (Config::frame_counter % 50 == 0 && !Config::loaded)
        {
            shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

            // loaded
            if (obj.anim_ind == 4)
            {
                Config::loaded = true;
                return;
            }

            obj.anim_ind++;
            obj.anim_ind %= obj.anims;
        }

        return;
    default:
        if (Config::frame_counter % 16 == 0 && obj.anims)
        {
            shape.setTextureRect(sf::IntRect(obj.anim_ind * obj.size_x, 0, obj.size_x, obj.size_y));

            obj.anim_ind++;
            obj.anim_ind %= obj.anims;
        }

        return;
    }
}