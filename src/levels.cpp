#include <levels.hpp>


void caller()
{
    if (Config::game_status == 1)      level_one();
    else if (Config::game_status == 2) level_two();
    else if (Config::game_status == 3) level_three();
}

void spawn( sf::RectangleShape& platform, Object& platform_obj, const float& x, const float& y )
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
        
        play_bgm(MusicIndex::game_music_index);

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
        spawn(elevator1, elevator1_obj, 195.5,  881);
        spawn(elevator2, elevator2_obj, 795  ,  328);
        spawn(elevator3, elevator3_obj, 6000 ,  700);

        

        // Box
        spawn(box, box_obj, 6000, 700);

        // Doors
   
        spawn(door1, door1_obj, 600,  0);
        door1.setScale(door1_obj.scale * 1.8, door1_obj.scale * 1.8);

        spawn(door2, door2_obj, 500, 360);
        door2.setScale(door2_obj.scale * 1, door2_obj.scale * 1);

        spawn(door3, door3_obj, 600, 700);
        door3.setScale(door3_obj.scale * 1.6, door3_obj.scale * 1.6);


        // Buttons
        spawn(button1, button1_obj, 85,  541);
        spawn(button2, button2_obj, 720, 541);
        spawn(button3, button3_obj, 280, 320);

        // Levers
        spawn(lever1, lever1_obj, 550,  295);
        spawn(lever2, lever2_obj, 400,  520);
        spawn(lever3, lever3_obj, 6000, 700);

        // Chickens
        spawn(chicken1, chicken1_obj, 850, 250);
        spawn(chicken2, chicken2_obj, 800, 800);
        spawn(chicken3, chicken3_obj, 40 , 450);



        // Players
            // Small Player

        s_obj.position = {0,0};
        s_player.setPosition(s_obj.position);

        // Big Player
        b_obj.position = {0,900};
        b_player.setPosition(b_obj.position);


        // Endgame
        end.setPosition(850, 500 - ground.getGlobalBounds().height + 37);

        Config::lv1_spawned = true;
        reset();

    }


        if ((((check_lever(*Config::players[0], *Config::objects[Object::lever1]) || check_lever(*players[1], *Config::objects[Object::lever1]))) || Config::lever1_pushed) && objects[Object::elevator1]->obj->position.y >= 550 )
        {
            objects[Object::elevator1]->obj->position.y -= .8f;
            objects[Object::elevator1]->shape->setPosition(Config::objects[Object::elevator1]->obj->position);
        }


        if ((((check_lever(*Config::players[0], *Config::objects[Object::lever2]) || check_lever(*players[1], *Config::objects[Object::lever2]))) || Config::lever2_pushed) && objects[Object::elevator2]->obj->position.y <= 550 )
        {
            objects[Object::elevator2]->obj->position.y += .8f;
            objects[Object::elevator2]->shape->setPosition(Config::objects[Object::elevator2]->obj->position);
        }

    if (Config::game_status == 1 && Config::chicken_num == 3 && players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && Config:: loaded)
    {
        Config::loaded = false;
        pLoading.obj->anim_ind = 0;

        animate(pLoading);

        Config::chicken_num = 0;
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


        animate(pChicken_counter);
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

        play_bgm(MusicIndex::game_music_index);

        // set positions

        // platforms
        platform1.setRotation(90);
        platform1.setScale(platform1_obj.scale, platform1_obj.scale);
        platform1_obj.position =
        {
            416.f,
            -45.f/*Config::RES_SIZE / 2.f + 30.f*/
        };
        platform1.setPosition(platform1_obj.position);

        platform7.setRotation(90);
        platform7.setScale(platform7_obj.scale, platform7_obj.scale);
        platform7_obj.position =
        {
            493.f,
            -45.f/*Config::RES_SIZE / 2.f + 30.f*/
        };
        platform7.setPosition(platform7_obj.position);

        spawn(platform2, platform2_obj, 435, 360);
        spawn(platform3, platform3_obj, 234, 360);
        spawn(platform4, platform4_obj, 704, 620);
        spawn(platform5, platform5_obj, 0, 620);
        spawn(platform6, platform6_obj, 508, 620);

        spawn(platform8, platform8_obj, 10000, 5500);
        spawn(platform9, platform9_obj, 4000, 65000);
        spawn(platform10,platform10_obj, 60000,7000);


        // Elevators
        spawn(elevator1, elevator1_obj, 195.5, 881);
        spawn(elevator2, elevator2_obj, 90,    612);
        spawn(elevator3, elevator3_obj, 700,   612);



        // Box
        spawn(box, box_obj, 195.5, 880);

        // Doors

        spawn(door1, door1_obj, 380, 150);
        door1.setScale(door1_obj.scale * 1.2, door1_obj.scale * 1.2);

        spawn(door2, door2_obj, 5000, 3600);
        door2.setScale(door2_obj.scale * 1, door2_obj.scale * 1);

        spawn(door3, door3_obj, 600, 720);
        door3.setScale(door3_obj.scale * 1.2, door3_obj.scale * 1.2);


        // Buttons
        spawn(button1, button1_obj, 5, 611);
        spawn(button2, button2_obj, 700, 5400);
        spawn(button3, button3_obj, 540, 611);

        // Levers
        spawn(lever1, lever1_obj, 600, 588);
        spawn(lever2, lever2_obj, 550, 328);
        spawn(lever3, lever3_obj, 50, 588);

        // Chickens
        spawn(chicken1, chicken1_obj, 750, 250);
        spawn(chicken2, chicken2_obj, 800, 800);
        spawn(chicken3, chicken3_obj, 140, 450);



        // Players
            // Small Player

        s_obj.position = { 80,900 };
        s_player.setPosition(s_obj.position);

        // Big Player
        b_obj.position = { 0,900 };
        b_player.setPosition(b_obj.position);


        // Endgame
        end.setPosition(520,327);

        Config::lv2_spawned = true;
        reset();

    }


    if ((((check_lever(*Config::players[0], *Config::objects[Object::lever1]) || check_lever(*players[1], *Config::objects[Object::lever1]))) || Config::lever1_pushed) && objects[Object::elevator1]->obj->position.y >= 620)
    {
        objects[Object::elevator1]->obj->position.y -= .8f;
        objects[Object::elevator1]->shape->setPosition(Config::objects[Object::elevator1]->obj->position);
    }


    if ((((check_lever(*Config::players[0], *Config::objects[Object::lever2]) || check_lever(*players[1], *Config::objects[Object::lever2]))) || Config::lever2_pushed) && objects[Object::elevator2]->obj->position.y >= 360)
    {
        objects[Object::elevator2]->obj->position.y -= .8f;
        objects[Object::elevator2]->shape->setPosition(Config::objects[Object::elevator2]->obj->position);
    }

    if ((((check_lever(*Config::players[0], *Config::objects[Object::lever3]) || check_lever(*players[1], *Config::objects[Object::lever3]))) || Config::lever3_pushed) && objects[Object::elevator3]->obj->position.y >= 360)
    {
        objects[Object::elevator3]->obj->position.y -= .8f;
        objects[Object::elevator3]->shape->setPosition(Config::objects[Object::elevator3]->obj->position);
    }

    if (Config::game_status == 1 && Config::chicken_num == 3 && players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && Config::loaded)
    {
        Config::loaded = false;
        pLoading.obj->anim_ind = 0;

        animate(pLoading);

        Config::chicken_num = 0;
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


        animate(pChicken_counter);
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
    if (((check_lever(*players[0], *objects[Object::lever1]) || check_lever(*players[1], *objects[Object::lever1]))) || Config::lever1_pushed && Config::loaded)
    {
        objects[Object::elevator1]->obj->position.x += .5f;
        objects[Object::elevator1]->shape->setPosition(objects[Object::elevator1]->obj->position);

        if (collision(*players[0], *objects[Object::elevator1]) == CollisionType::elevator1)
        {
            players[0]->obj->position.x += 3.5f;
            players[0]->sprite->setPosition(players[0]->obj->position);
        }
    }

    if (Config::game_status == 3 && Config::chicken_num == 3 && players[0]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()) && players[1]->sprite->getGlobalBounds().intersects(end.getGlobalBounds()))
    {
        Config::loaded = false;
        pLoading.obj->anim_ind = 0;

        animate(pLoading);

        Config::chicken_num = 0;

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

        animate(pChicken_counter);

        std::cout << "Level 3 complete...\n";
        //window.close();
        return;
    }
}
