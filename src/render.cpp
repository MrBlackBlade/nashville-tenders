#include <render.hpp>

void render()
{
    // change the bg color
    window.RenderTarget::clear(sf::Color(55, 68, 110, 255));

    // render the background
    window.draw(background_1);
    window.draw(background_2);
    window.draw(background_3);
    window.draw(background_4);

    // render the players 
    window.draw(b_player);
    window.draw(s_player);

    // render the objects
    for (auto& object : Config::objects)
        window.draw(*object->shape);

    // draw the frame
    window.display();

    // for the animation speed
    Config::frame_counter++;

    // closest number to 100 divisible by 16 to prevent overflowing        
    Config::frame_counter %= 96;
}