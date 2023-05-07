#include <menu.hpp>

void setup_menu()
{
    play_bgm(1);

    font.loadFromFile("resources/Minecraft.ttf");

    main_menu[0].setFont(font);
    main_menu[0].setFillColor(sf::Color::Yellow);
    main_menu[0].setString("PLAY");
    main_menu[0].setCharacterSize(70);
    main_menu[0].setPosition(sf::Vector2f(353.f, 550.f));

    main_menu[1].setFont(font);
    main_menu[1].setFillColor(sf::Color::White);
    main_menu[1].setString("QUIT");
    main_menu[1].setCharacterSize(70);
    main_menu[1].setPosition(sf::Vector2f(353.f, 645.f));
}

void moveDown() {
    if (Config::menu_selection + 1 <= 2) // play
    {
       main_menu[Config::menu_selection].setFillColor(sf::Color::White);
       Config::menu_selection++;
       if (Config::menu_selection == 2)
       {
           Config::menu_selection = 0;
       }
       main_menu[Config::menu_selection].setFillColor(sf::Color::Yellow);
    }
}

void moveUp() {
    if (Config::menu_selection - 1 >= -1) // quit
    {
        main_menu[Config::menu_selection].setFillColor(sf::Color::White);
        Config::menu_selection--;
        if (Config::menu_selection == -1)
        {
            Config::menu_selection = 1;
        }
        main_menu[Config::menu_selection].setFillColor(sf::Color::Yellow);
    }
}

