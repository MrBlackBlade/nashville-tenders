#include <render.hpp>

void render()
{

	window.draw(menu);

	if (Config::menu_status == 1)
	{
		for (int i = 0; i < 2; i++)
		{
			window.draw(main_menu[i]);
		}
	}

	else if (Config::menu_status == -1)
	{
		window.close();
	}

	else if (Config::menu_status == 0)
	{
		if (Config::loaded)
		{
			//render the background
			window.draw(background_1);
			window.draw(background_2);
			window.draw(background_3);
			window.draw(background_4);
			window.draw(chicken_counter);

			// render the players
			window.draw(b_player);
			window.draw(s_player);

			// render the objects
			for (auto& object : Config::objects)
				window.draw(*object->shape);

			// render the end
			window.draw(end);
		}

		else
		{
			if (Config::game_status == 4)
			{
				window.draw(game_end);
			}

			else
			{
				window.draw(lv_comp);
				window.draw(loading);
			}
		}
	}

	// draw the frame
	window.display();

	// for the animation speed
	Config::frame_counter++;

	// closest number to 100 divisible by 16 to prevent overflowing
	Config::frame_counter %= 96;
}