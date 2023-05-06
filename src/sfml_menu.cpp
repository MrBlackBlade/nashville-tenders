#include <menu.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


	if (Config::menu_status == 1)
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					break;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Up)
						moveUp();
					if (event.key.code == sf::Keyboard::Down)
						moveDown();

					if (event.key.code == sf::Keyboard::Enter)
					{
						if (Config::menu_selection == 0)
							Config::menu_status = 0;

						if (Config::menu_selection == 1)
							Config::menu_status = -1;
					}

				}
			}
			window.clear();

			if (Config::menu_status != 1)
				break;

			window.draw(bg);
			draw_menu();
			window.display();

		}
		if (Config::menu_status == -1)
		{
			window.close();
		}

		if (Config::menu_status == 0)
		{

		}
	}