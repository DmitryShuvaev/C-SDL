#ifndef GEM_H
#define GEM_H
#include "Timer.h"
#include <math.h>
class Gem
{
    public:
        Gem();
        virtual ~Gem();
    void gemAnimation(int &y);
Timer* mgemTimeanim;
float mgemAnimationTimer=0.0f;
bool startanim=false;
SDL_Rect gemSpriteClip;
};

#endif // GEM_H
