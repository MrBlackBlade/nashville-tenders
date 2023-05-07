#include <levels.hpp>


void caller()
{
    if (Config::game_status == 1) level_one();
    else if (Config::game_status == 2) level_two();
    else if (Config::game_status == 3) level_three();
}

void spawn( sf::RectangleShape &platform, Object &platform_obj, const float &x, const float &y )
{
    platform_obj.position =
    {
        x,
        y/*Config::RES_SIZE / 2.f + 30.f*/
    };
    platform.setPosition(platform_obj.position);
}


void level_one()
{
    using Config::objects, Config::players;

    animate(pLoading);
     
    if (!Config::lv1_spawned)
    {
        reset();
        // set positions
        
        // platforms
        spawn(platform1,  platform1_obj,  0,    328);
        spawn(platform2,  platform1_obj,  200,  328);
        spawn(platform3,  platform1_obj,  400,  328);
        spawn(platform4,  platform1_obj,  600,  328);
        spawn(platform5,  platform1_obj,  700,  550);
        spawn(platform6,  platform1_obj,  500,  550);
        spawn(platform7,  platform1_obj,  300,  550);
        spawn(platform8,  platform1_obj,  0,    550);
        spawn(platform9,  platform1_obj,  400,  6500);
        spawn(platform10, platform1_obj,  6000, 700);


        // Elevators
        spawn(elevator1, elevator1_obj, 800, 348);

        spawn(elevator2, elevator2_obj, 195, 865);
        if (((elevator_move(*players[0], *objects[Object::lever2]) || elevator_move(*players[1], *objects[Object::lever2]))) || Config::lever2_pushed)
        {
            objects[Object::elevator2]->obj->position.y -= .5f;
            objects[Object::elevator2]->shape->setPosition(objects[Object::elevator2]->obj->position);

            /*if (collision(*players[0], *objects[Object::elevator1]) == CollisionType::elevator1)
            {
                players[0]->obj->position.x += 3.5f;
                players[0]->sprite->setPosition(players[0]->obj->position);
            }*/
        }

        spawn(elevator3, elevator3_obj, 6000, 700);

        

        // Box
        spawn(box, box_obj, 6000, 700);

        // Doors
   
        spawn(door1, door1_obj, 600,  0);
        door1.setScale(door1_obj.scale * 1.8, door1_obj.scale * 1.8);

        spawn(door2, door2_obj, 500, 360);

        spawn(door3, door3_obj, 600, 700);
        door3.setScale(door3_obj.scale * 1.6, door3_obj.scale * 1.6);


        // Buttons
        spawn(button1, button1_obj, 85,    540);
        spawn(button2, button2_obj, 780, 540);
        spawn(button3, button3_obj, 280, 320);

        // Levers
        spawn(lever1, lever1_obj, 400,  520);

        spawn(lever2, lever2_obj, 550,  300);
        

        spawn(lever3, lever3_obj, 6000, 700);

        // Chickens
        spawn(chicken1, chicken1_obj, 850, 250);
        spawn(chicken2, chicken2_obj, 800, 800);
        spawn(chicken3, chicken3_obj, 40, 450);



        // Players
            // Small Player

        s_obj.position = {0,0};
        s_player.setPosition(s_obj.position);

            // Big Player
        b_obj.position = {0,900};
        b_player.setPosition(b_obj.position);


        // Endgame
        end.setPosition(850, 500 - ground.getGlobalBounds().height + 30);

        Config::lv1_spawned = true;


    }

  




    // moving the elevator
    if (((elevator_move(*players[0], *objects[Object::lever1]) || elevator_move(*players[1], *objects[Object::lever1]))) || Config::lever1_pushed)
    {
        objects[Object::elevator1]->obj->position.y -= .5f;
        objects[Object::elevator1]->shape->setPosition(objects[Object::elevator1]->obj->position);
        
        /*if (collision(*players[0], *objects[Object::elevator1]) == CollisionType::elevator1)
        {
            players[0]->obj->position.x += 3.5f;
            players[0]->sprite->setPosition(players[0]->obj->position);
        }*/
    }

    if (Config::game_status == 1 && Config::lv1_chicken_count == 3 && players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && Config:: loaded)
    {
        Config::loaded = false;
        pLoading.obj->anim_ind = 0;

        animate(pLoading);

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

    animate(pLoading);

    if (!Config::lv2_spawned)
    {
        reset();
        // set positions

        Config::lv2_spawned = true;
    }

    // moving the elevator
    if (((elevator_move(*players[0], *objects[Object::lever1]) || elevator_move(*players[1], *objects[Object::lever1]))) || Config::lever1_pushed && Config::loaded)
    {
        objects[Object::elevator1]->obj->position.y += .5f;
        objects[Object::elevator1]->shape->setPosition(objects[Object::elevator1]->obj->position);

        if (collision(*players[0], *objects[Object::elevator1]) == CollisionType::elevator1)
        {
            players[0]->obj->position.x += 3.5f;
            players[0]->sprite->setPosition(players[0]->obj->position);
        }
    }

    if (Config::game_status == 2 && Config::lv2_chicken_count == 3 && players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()))
    {   

        Config::loaded = false;
        pLoading.obj->anim_ind = 0;

        animate(pLoading);

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

    animate(pLoading);

    if (!Config::lv3_spawned)
    {
        reset();
        // set positions

        Config::lv3_spawned = true;
    }

    // moving the elevator
    if (((elevator_move(*players[0], *objects[Object::lever1]) || elevator_move(*players[1], *objects[Object::lever1]))) || Config::lever1_pushed && Config::loaded)
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
        Config::loaded = false;
        pLoading.obj->anim_ind = 0;

        animate(pLoading);

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
        //window.close();
        return;
    }
}
