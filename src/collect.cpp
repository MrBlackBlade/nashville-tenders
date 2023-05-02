#include <collect.hpp>

bool collect(Pair_Player& p_pair, Pair_Object& o_pair)
{
    auto& player = *p_pair.sprite;
    auto& obj = *p_pair.obj;
    auto& shape = *o_pair.shape;
    auto& obj2 = *o_pair.obj;

    if (obj2.id != Object::chicken)

        return false;

    if (player.getGlobalBounds().intersects(shape.getGlobalBounds()))
    {
        //temporary way to remove chicken from render
        obj2.position.x += 5000;
        shape.setPosition(obj2.position);

        std::cout << ++Config::chicken_count << "\n";
        return true;
    }


    return false;
}





