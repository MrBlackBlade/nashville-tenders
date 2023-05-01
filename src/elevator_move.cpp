#include <elevator_move.hpp>

bool elevator_move(Pair_Player& p_pair, Pair_Object& o_pair )
{
    auto& player = *p_pair.sprite;
    auto& obj    = *p_pair.obj;
    auto& shape  = *o_pair.shape;
    auto& obj2   = *o_pair.obj;

    const auto key = get_key_pressed(p_pair);

    if (obj2.id != Object::lever)

        return false;
  
    if (player.getGlobalBounds().intersects(shape.getGlobalBounds()))
    {  
        std::cout << "AUUUGHHHHHHHHH" << "\n";
        return true;
    }


    return false;
}




