#ifndef PADDLE_H
#define PADDLE_H
#include "Texture.h"
#include "InputManager.h"

class Paddle:public Collision
{
    public:
        Paddle();
        virtual ~Paddle();
        void Update();
        void Render();
    Texture*padle;
    float Scalex=3;
    float Scaley=3;
    const int PADDLE_SPEED=8;
    SDL_Rect gSpriteClips;
    //SDL_Rect gSpriteClips2;
    InputManager*mInput;
    bool ifmove;
    int x;
    int y;
    int width;
    int hight;
    int dx;
    private:
};

#endif // PADDLE_H
