#include <move.hpp>

//acc += raqm
//vel += acc
//pos += vel
//setposition(pos)

void move(sf::Sprite& player, Player& obj, const sf::Keyboard::Key& key)
{
    // Pressing a button
    if (sf::Keyboard::isKeyPressed(key))
    {
        // Up
        if ( key == Config::keybinds[obj.id][0] && !obj.jumping )
        {
            // jump logic
        }

        // Left
        else if (key == Config::keybinds[obj.id][1])
        {
            obj.acceleration.x = -.2;

            animate(player, obj, Animation::run);

            player.setScale(-obj.player_scale, obj.player_scale);
            player.setOrigin(player.getLocalBounds().width, 0);
        }

        // Down
            // mfish down lmao

        // Right
        else if ( key == Config::keybinds[obj.id][3] )
        {
            obj.acceleration.x = .2;

            animate(player, obj, Animation::run);

            player.setScale(obj.player_scale, obj.player_scale);
            player.setOrigin(0, 0);
        }

        // Capping the acceleration (+ve)
        if ( obj.acceleration.x > .2 )
        {
           obj.acceleration.x = .2;
        }

        // Capping the acceleration (-ve)
        if ( obj.acceleration.x < -.2 )
        {
           obj.acceleration.x = -.2;
        }
        
        // Apply motion
        obj.velocity += obj.acceleration;
        obj.position += obj.velocity;
        player.setPosition(obj.position);
    }

    // Not pressing a button
    else
    {
        // decelerate to the left
        if ( obj.velocity.x > 0.f )
        {
            animate(player, obj, Animation::run);
            obj.acceleration.x = -.2;
        }

        // decelerate to the right
        else if ( obj.velocity.x < 0.f )
        {
            animate(player, obj, Animation::run);
            obj.acceleration.x = .2;
        }

        //  1.f is a tolerance value to check if the player "stopped" motion
        if ( std::fabs ( obj.velocity.x ) < 1.f )
        {
            obj.velocity     = {0.f, 0.f};
            obj.acceleration = {0.f, 0.f};
            obj.idle = true;
        }

        // apply the motion
        obj.velocity += obj.acceleration;
        obj.position += obj.velocity;
        player.setPosition(obj.position);

        // logging
        std::cout << "Velocity:    \t" <<obj.velocity.x << std::endl;
        std::cout << "Acceleration:\t" <<obj.acceleration.x << std::endl;
        std::cout << "Position:    \t" <<obj.position.x << std::endl;
    }
}