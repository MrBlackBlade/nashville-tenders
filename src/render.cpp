#include"..\include\render.hpp"
void render(RenderWindow& window,Sprite& player)
{

	// change the bg color
	window.RenderTarget::clear(Color(130, 130, 150, 255));

	window.draw(player);
	window.display();

	// for the animation speed
	frame_counter++;
	// closest divisible number by 16 to 100		
	frame_counter %= 96;

}
