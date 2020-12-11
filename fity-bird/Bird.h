#ifndef BIRD_H
#define BIRD_H
//#include "Texture.h"
#include "Tube.h"
#include "InputManager.h"
#include "AudioManager.h"
class Bird
{
    public:
        Bird();
        virtual ~Bird();
        void Update();
        void Render();
bool collides(const Tube &pipe);
const float GRAVITY = 0.2;
    float ic=2.5;
    float dy=1;
    Texture*bird;
    InputManager*mInput;
//    SDL2SoundEffets *sound;
AudioManager* mAudioMgr;
};

#endif // BIRD_H
