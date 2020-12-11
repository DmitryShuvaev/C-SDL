#ifndef SDL2SOUNDEFFETS_H
#define SDL2SOUNDEFFETS_H
#include "SDL_mixer.h"
#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include <vector>

class SDL2SoundEffets
{
    public:
        SDL2SoundEffets();
        virtual ~SDL2SoundEffets();
void addSoundEffect(const char*path);
void playSoundEffect(const int which,int loops=0)const;//-1 infinit loop


    private:
        std::vector<Mix_Chunk*>mSoundEffectBank;
};

#endif // SDL2SOUNDEFFETS_H
