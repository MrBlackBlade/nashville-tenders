#include <move.hpp>

// For sprites
void move(Pair_Player& pair)
{
    auto& player = *pair.sprite;
    auto& obj = *pair.obj;
    const auto key = get_key_pressed(pair);

    // Decrementing the jump
    if ( obj.jumping )
    {
        animate(pair, Animation::jump);
        obj.acceleration.y = .2f;
        
        // Apply motion
        obj.velocity += obj.acceleration;
        obj.position += obj.velocity;
        player.setPosition(obj.position);
    }

    // Pressing a button
    if (sf::Keyboard::isKeyPressed(key))
    {
        // Up
        if ( key == Config::keybinds[obj.id][0] && !obj.jumping )
        {
            animate(pair, Animation::jump);

            obj.jumping = true;
            obj.velocity.y = obj.id ? -2.f : -8.f ;
        }

        // Left
        if (key == Config::keybinds[obj.id][1])
        {
            animate(pair, Animation::run);

            obj.acceleration.x = -.2f;

            // Rotate player to the left
            player.setScale(-obj.scale, obj.scale);
            player.setOrigin(player.getLocalBounds().width, 0);
        }

        // Down
            // mfish down lmao

        // Right
        if ( key == Config::keybinds[obj.id][3] )
        {
            animate(pair, Animation::run);

            obj.acceleration.x = .2f;

            // Rotate player to the right
            player.setScale(obj.scale, obj.scale);
            player.setOrigin(0, 0);
        }

        // Capping the velocity.x (+ve)
        if (obj.velocity.x > obj.velocity_max.x)
        {
            obj.velocity.x = obj.velocity_max.x;
        }

        // Capping the velocity.x (-ve)
        if (obj.velocity.x < -obj.velocity_max.x)
        {
            obj.velocity.x = -obj.velocity_max.x;
        }

        // Capping the acceleration (+ve)
        if ( obj.acceleration.x > .2f )
        {
           obj.acceleration.x = .2f;
        }

        // Capping the acceleration (-ve)
        if ( obj.acceleration.x < -.2f )
        {
           obj.acceleration.x = -.2f;
        }

        // Apply motion
        obj.velocity += obj.acceleration;
        obj.position += obj.velocity;
        player.setPosition(obj.position);
    }

    // Not pressing a button
    if ( !sf::Keyboard::isKeyPressed(key) )
    {
        // decelerate to the left
        if ( obj.velocity.x > 0.f )
        {
            animate(pair, Animation::run);

            obj.acceleration.x = -.2f;
        }

        // decelerate to the right
        if ( obj.velocity.x < 0.f )
        {
            animate(pair, Animation::run);

            obj.acceleration.x = .2f;
        }

        //  1.f is a tolerance value to check if the player "stopped" motion
        if ( std::fabs ( obj.velocity.x ) < 1.f )
        {
            obj.velocity.x     = 0.f;
            obj.acceleration.x = 0.f;
            obj.idle = true;
        }

        // Apply motion
        obj.velocity += obj.acceleration;
        obj.position += obj.velocity;
        player.setPosition(obj.position);
    }

    // Background movement
    if ( obj.velocity.x > .5f )
    {
        background_1.move(-.2f, 0.f);
        background_2.move(-.3f, 0.f);
        background_3.move(-.5f, 0.f);
        background_4.move(-.7f, 0.f);
    }

    // Background movement
    if ( obj.velocity.x < -.5f )
    {
        background_1.move(.2f, 0.f);
        background_2.move(.3f, 0.f);
        background_3.move(.5f, 0.f);
        background_4.move(.7f, 0.f);
    }

    // Keep the player in bounds (right)
    if (out_of_bounds(pair) && obj.velocity.x > 5.f && obj.position.x > Config::RES_SIZE / 2)
    {
        obj.position.x = Config::RES_SIZE - player.getGlobalBounds().width;

        // Apply motion
        obj.velocity += obj.acceleration;
        obj.position += obj.velocity;
        player.setPosition(obj.position);
    }

    // Keep the player in bounds (left)
    if (out_of_bounds(pair) && obj.velocity.x < 5.f && obj.position.x < Config::RES_SIZE / 2)
    {
        obj.position.x = 0;

        // Apply motion
        obj.velocity += obj.acceleration;
        obj.position += obj.velocity;
        player.setPosition(obj.position);
    }

    // Keep the player in bounds (down)
    if (obj.position.y > Config::RES_SIZE)
    {
        obj.position.y = Config::RES_SIZE - 50;
        obj.velocity.y = 0;
    
        // Apply motion
        obj.velocity += obj.acceleration;
        obj.position += obj.velocity;
        player.setPosition(obj.position);
    }
}

// For obstacles
void move(Pair_Object& pair)
{
    animate(pair);

    auto& shape = *pair.shape;
    auto& obj = *pair.obj;


    if (pair.obj->id == Object::ground || pair.obj->id == Object::button || pair.obj->id == Object::lever || pair.obj->id == Object::platform || pair.obj->id == Object::door)
        return;
    
    if (((elevator_move(*Config::players[0], *Config::objects[Object::lever]) || elevator_move(*Config::players[1], *Config::objects[Object::lever])) && pair.obj->id == Object::elevator) || Config::lever_pushed)
    {
        // Gravity lmaoo
        Config::objects[Object::elevator]->obj->position.y -= .5f;
        shape.setPosition(obj.position);
        // limit upper bound
        return;
    }

    // Gravity lmaoo
    obj.acceleration.y = .2f;
      
    // Apply motion
    obj.velocity += obj.acceleration;
    obj.position += obj.velocity;
    shape.setPosition(obj.position);
}