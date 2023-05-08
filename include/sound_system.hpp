#pragma once
#ifndef _SOUND_SYSTEM_HPP
#define _SOUND_SYSTEM_HPP

#include <SFML/Audio.hpp>
#include <Config.hpp>
#include <AudioIndex.hpp>

void play_bgm(const MusicIndex&);
void play_sfx(const SoundIndex&);

#endif // #ifndef _SOUND_SYSTEM_HPP
