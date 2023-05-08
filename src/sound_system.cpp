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
}

void play_sfx(const SoundIndex & index) {
	using enum SoundIndex;
	switch (index) {
	case chicken_collect:
		chicken_collect_sound.play();
		return;
	case elevator1_move:
		elevator1_move_sound.play();
		return;
	case elevator2_move:
		elevator2_move_sound.play();
		return;
	case elevator3_move:
		elevator3_move_sound.play();
		return;

	case elevator1_stop:
		elevator1_move_sound.stop();
		return;
	case elevator2_stop:
		elevator2_move_sound.stop();
		return;
	case elevator3_stop:
		elevator3_move_sound.stop();
		return;

	case lever_pull:
		lever_pull_sound.play();
		return;
	case button_press:
		button_push_sound.play();
		return;
	case door_open:
		door_open_sound.play();
		return;
	case level_complete:
		level_complete_sound.play();
		return;
	}
}
