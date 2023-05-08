#pragma once
#ifndef _AUDIO_INDEX_HPP
#define _AUDIO_INDEX_HPP

enum class SoundIndex
{
	chicken_collect,	// yes
	elevator1_move,
	elevator2_move,
	elevator3_move,		// yes
	elevator1_stop,
	elevator2_stop,
	elevator3_stop,		// yesnt
	lever_pull,			// yes
	door_open,			// eh
	button_press,		// eh
	level_complete,

	SoundIndex_max,
};

enum class MusicIndex
{
	main_menu_music_index,
	game_music_index,

	MusicIndex_max,
};

#endif // #ifndef _AUDIO_INDEX_HPP