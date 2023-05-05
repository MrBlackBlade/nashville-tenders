#include <collect.hpp>

bool collect(Pair_Player& p_pair, Pair_Object& o_pair)
{
    auto& player = *p_pair.sprite;
    auto& obj    = *p_pair.obj;
    auto& shape  = *o_pair.shape;
    auto& obj2   = *o_pair.obj;

    if (obj2.id != Object::chicken1 && obj2.id != Object::chicken2 && obj2.id != Object::chicken3)
        return false;

    if ( player.getGlobalBounds().intersects( shape.getGlobalBounds() ) )
    {
        if (Config::game_status <= 1)
            Config::lv1_chicken_count++;

        else if (Config::game_status <= 2)
            Config::lv2_chicken_count++;

        else if (Config::game_status <= 3)
            Config::lv3_chicken_count++;

        // temporary way to remove chicken from render
        obj2.position.x += 5000;
        shape.setPosition(obj2.position);

        return true;
    }

    return false;
}





