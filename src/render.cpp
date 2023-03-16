#include <render.hpp>

void render(RenderWindow& window, Sprite& s_player, Sprite& b_player)
{
	// change the bg color
	window.RenderTarget::clear(Color(130, 130, 150, 255));

	// render the sprites then draw the frame
	window.draw(s_player);
	window.draw(b_player);
	window.display();

	// for the animation speed
	frame_counter++;

	// closest number to 100 divisible by 16 to prevent overflowing		
	frame_counter %= 96;
}
