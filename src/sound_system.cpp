#include <sound_system.hpp>

void play_bgm(const MusicIndex& index) {
	using enum MusicIndex;
	switch (index) {
	case main_menu_music_index:
		main_menu_music.play();
		main_menu_music.setLoop(true);
		return;
	case game_music_index:
		main_menu_music.stop();
		game_music.play();
		game_music.setLoop(true);
		return;
	}
	
	/*if (index == 1) {
		main_menu_music.play();
		main_menu_music.setLoop(true);
	}
	if (index == 2) {
		game_music.play();
		game_music.setLoop(true);
	}*/
}