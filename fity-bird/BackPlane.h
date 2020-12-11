#ifndef BACKPLANE_H
#define BACKPLANE_H
#include "Collision.h"
#include "Texture.h"

class BackPlane:public Collision
{
    public:
        BackPlane();
        virtual ~BackPlane();
        void Update(SCREENS &mCurrentScreen);
        void Render();
    float dy=1;
    float ic=2.5;
        int BACKGROUND_LOOPING_POINT = -413*ic;
    float BACKGROUND_SCROLL_SPEED = 0.5;
    float GROUND_SCROLL_SPEED = 1;
    float backgroundScroll=0;
    float groundScroll=0;
        Texture*background;
        Texture*ground;

    private:
};

#endif // BACKPLANE_H
