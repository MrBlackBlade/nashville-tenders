#include <getXposition.hpp>

Vector2f getXposition(Sprite& player)
{
    //while (true)
    
        Vector2f position = player.getPosition();
        std::cout << "Sprite X Position: " << position.x << std::endl;

    return position;
}
