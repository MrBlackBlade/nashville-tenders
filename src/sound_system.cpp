#include <sound_system.hpp>

void play_bgm(const MusicIndex& index) {
	using enum MusicIndex;
	switch (index) {
	case main_menu_music_index:
		main_menu_music.setVolume(20.f);
		main_menu_music.play();
		main_menu_music.setLoop(true);
		return;
	case game_music_index:
		main_menu_music.stop();
		game_music.setVolume(20.f);
		game_music.play();
		game_music.setLoop(true);
		return;
	}
}

void play_sfx(const SoundIndex & index) {
	using enum SoundIndex;
	switch (index) {
	case chicken_collect:
		chicken_collect_sound.setVolume(100.f);
		chicken_collect_sound.play();
		return;
	case lever_pull:
		main_menu_music.stop();
		game_music.play();
		game_music.setLoop(true);
		return;
	}
}