#include <render.hpp>

// background and platforms
extern sf::Sprite               background;
extern sf::RectangleShape       ground;
extern sf::RectangleShape       box;

// players
extern sf::Sprite       s_player;
extern sf::Sprite       b_player;

// window
extern sf::RenderWindow window;

void render()
{
    // change the bg color
    window.RenderTarget::clear(sf::Color(55, 68, 110, 255));

    // render the sprites then draw the frame
    window.draw(background);
    window.draw(ground);
    window.draw(box);
    window.draw(b_player);
    window.draw(s_player);
    window.display();

    // for the animation speed
    Config::frame_counter++;

    // closest number to 100 divisible by 16 to prevent overflowing        
    Config::frame_counter %= 96;
}