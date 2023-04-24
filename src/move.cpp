#include <move.hpp>

extern sf::Sprite background;

// For sprites
void move(sf::Sprite& player, Player& obj, const sf::Keyboard::Key& key)
{
    // Decrementing the jump
    if ( obj.jumping )
    {
        animate(player, obj, Animation::jump);
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
        if ( key == Config::keybinds[0][0] && !obj.jumping )
        {
            animate(player, obj, Animation::jump);

            obj.jumping = true;
            obj.velocity.y = -10.f;
        }

        // Left
        if (key == Config::keybinds[obj.id][1])
        {
            animate(player, obj, Animation::run);

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
            animate(player, obj, Animation::run);

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
            animate(player, obj, Animation::run);

            obj.acceleration.x = -.2f;
        }

        // decelerate to the right
        if ( obj.velocity.x < 0.f )
        {
            animate(player, obj, Animation::run);

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
        background.move(-.7f, 0.f);
    }

    // Background movement
    if ( obj.velocity.x < 0.f )
    {
        background.move(.7f, 0.f);
    }

    // logging
    if (obj.id == 0 && obj.velocity.x < 0.f)
    {
        std::cout << "Velocity X:\t" << obj.velocity.x << '\n';
        std::cout << "Velocity Y:\t" << obj.velocity.y << "\n\n";
        std::cout << "Position X:\t" << obj.position.x << '\n'; 
        std::cout << "Position Y:\t" << obj.position.y << "\n\n";
    }
}

// For obstacles
void move(sf::RectangleShape& shape, Player& obj)
{
    // Gravity lmao
    obj.acceleration.y = .2f;
        
    // Apply motion
    obj.velocity += obj.acceleration;
    obj.position += obj.velocity;
    shape.setPosition(obj.position);
}