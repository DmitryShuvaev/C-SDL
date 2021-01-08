#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Texture.h"

#include "Collision.h"

class Background:public Collision
{
    public:
        Background();
        void Render();
         ~Background();
    private:
        float backgroundScalex=4.3;
        float backgroundScaley=5.7;
        Texture*background;
};

#endif // BACKGROUND_H
