#include <sound_system.hpp>

void play_bgm(int index) {
	if (index == 1) {
		main_menu_music.play();
		main_menu_music.setLoop(true);
	}
}