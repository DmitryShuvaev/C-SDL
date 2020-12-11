#include "SDL2SoundEffets.h"

SDL2SoundEffets::SDL2SoundEffets()
{
    //ctor
    SDL_Init(SDL_INIT_AUDIO);
    int audio_rate=22050;
    uint16_t audio_format=AUDIO_S16SYS;
    int audio_channels=2;
    int audio_buffers=4096;
    if(Mix_OpenAudio(audio_rate,audio_format,audio_channels,audio_buffers)!=0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Couldn't init audio: %s",Mix_GetError());
//        exit(-1);
    }
}

SDL2SoundEffets::~SDL2SoundEffets()
{
    //dtor
//Close the SDL_mixer
 Mix_Quit();
 SDL_Quit();
}
void SDL2SoundEffets::addSoundEffect(const char*path)
{
Mix_Chunk*tmpChunk=Mix_LoadWAV(path);
if(tmpChunk!=nullptr)
{
    mSoundEffectBank.push_back(tmpChunk);
    std::cout<<(mSoundEffectBank.size()-1)<<". sound loaded: "<<path<<'\n';
    //Mix_FreeChunk(tmpChunk);
}else
{
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Couldn't init audio: %s",Mix_GetError());

}
}
void SDL2SoundEffets::playSoundEffect(const int which,int loops)const
{
if(which>mSoundEffectBank.size()-1)
{
    std::cout<<"Sound out of range.\n";

}
Mix_PlayChannel(-1,mSoundEffectBank[which],loops);
std::cout<<"Played Sound: "<<which<<'\n';
}
