#ifndef HEALTH_H
#define HEALTH_H
#include "Texture.h"

class Health
{
    public:
        Health();
        virtual ~Health();
        void Update();
        void Render();
    float Scalex=3;
    float Scaley=3;
    int healthX;
    int y;
    int width;
    int hight;
    int health=3;
    Texture *mhealth;
SDL_Rect gSpriteClips[3];
    private:
};

#endif // HEALTH_H
