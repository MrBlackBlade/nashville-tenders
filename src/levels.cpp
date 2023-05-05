#include <levels.hpp>

void caller()
{
    if (Config::game_status == 1) level_one();
    else if (Config::game_status == 2) level_two();
    else if (Config::game_status == 3) level_three();
}

void level_one()
{
    using Config::objects, Config::players;

    /* loading screen sprite msln idk */

    // moving the elevator
    if (((elevator_move(*players[0], *objects[Object::lever1]) || elevator_move(*players[1], *objects[Object::lever1]))) || Config::lever1_pushed)
    {
        objects[Object::elevator1]->obj->position.x += .5f;
        objects[Object::elevator1]->shape->setPosition(objects[Object::elevator1]->obj->position);

        if (collision(*players[0], *objects[Object::elevator1]) == CollisionType::elevator1)
        {
            players[0]->obj->position.x += 3.5f; 
            players[0]->sprite->setPosition(players[0]->obj->position);
        }
    }

    if (Config::game_status == 1 && Config::lv1_chicken_count == 3 && players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()))
    {
        Config::lv1_chicken_count = 0;
        Config::game_status = 2;

        chicken1_obj.position =
        {
            500.f,
            ground.getGlobalBounds().top - chicken1.getGlobalBounds().height
        };
        chicken1.setPosition(chicken1_obj.position);

        chicken2_obj.position =
        {
            550.f,
            ground.getGlobalBounds().top - chicken2.getGlobalBounds().height
        };
        chicken2.setPosition(chicken2_obj.position);

        chicken3_obj.position =
        {
            600.f,
            ground.getGlobalBounds().top - chicken3.getGlobalBounds().height
        };
        chicken3.setPosition(chicken3_obj.position);

        std::cout << "Level 1 complete...\n";
        return;
    }
}

void level_two()
{
    using Config::objects, Config::players;

    /* loading screen sprite msln idk */

    // moving the elevator
    if (((elevator_move(*players[0], *objects[Object::lever1]) || elevator_move(*players[1], *objects[Object::lever1]))) || Config::lever1_pushed)
    {
        objects[Object::elevator1]->obj->position.x += .5f;
        objects[Object::elevator1]->shape->setPosition(objects[Object::elevator1]->obj->position);

        if (collision(*players[0], *objects[Object::elevator1]) == CollisionType::elevator1)
        {
            players[0]->obj->position.x += 3.5f;
            players[0]->sprite->setPosition(players[0]->obj->position);
        }
    }

    if (Config::game_status == 2 && Config::lv2_chicken_count == 3 && players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()))
    {   
        Config::lv2_chicken_count = 0;
        Config::game_status = 3;

        chicken1_obj.position =
        {
            500.f,
            ground.getGlobalBounds().top - chicken1.getGlobalBounds().height - 20.f
        };
        chicken1.setPosition(chicken1_obj.position);

        chicken2_obj.position =
        {
            550.f,
            ground.getGlobalBounds().top - chicken2.getGlobalBounds().height - 20.f
        };
        chicken2.setPosition(chicken2_obj.position);

        chicken3_obj.position =
        {
            600.f,
            ground.getGlobalBounds().top - chicken3.getGlobalBounds().height - 20.f
        };
        chicken3.setPosition(chicken3_obj.position);

        std::cout << "Level 2 complete...\n";
        return;
    }
}

void level_three()
{
    using Config::objects, Config::players;

    /* loading screen sprite msln idk */

    // moving the elevator
    if (((elevator_move(*players[0], *objects[Object::lever1]) || elevator_move(*players[1], *objects[Object::lever1]))) || Config::lever1_pushed)
    {
        objects[Object::elevator1]->obj->position.x += .5f;
        objects[Object::elevator1]->shape->setPosition(objects[Object::elevator1]->obj->position);

        if (collision(*players[0], *objects[Object::elevator1]) == CollisionType::elevator1)
        {
            players[0]->obj->position.x += 3.5f;
            players[0]->sprite->setPosition(players[0]->obj->position);
        }
    }

    if (Config::game_status == 3 && Config::lv3_chicken_count == 3 && players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()))
    {
        Config::lv3_chicken_count = 0;

        chicken1_obj.position =
        {
            500.f,
            ground.getGlobalBounds().top - chicken1.getGlobalBounds().height - 20.f
        };
        chicken1.setPosition(chicken1_obj.position);

        chicken2_obj.position =
        {
            550.f,
            ground.getGlobalBounds().top - chicken2.getGlobalBounds().height - 20.f
        };
        chicken2.setPosition(chicken2_obj.position);

        chicken3_obj.position =
        {
            600.f,
            ground.getGlobalBounds().top - chicken3.getGlobalBounds().height - 20.f
        };
        chicken3.setPosition(chicken3_obj.position);

        std::cout << "Level 3 complete...\n";
        window.close();
        return;
    }
}