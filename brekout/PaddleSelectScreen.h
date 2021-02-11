#ifndef PADDLESELECTSCREEN_H
#define PADDLESELECTSCREEN_H
#include "Collision.h"
#include "Texture.h"
#include "InputManager.h"
#include "Paddle.h"
#include "PlayScreen.h"
class PaddleSelectScreen:public Collision
{
    public:
        PaddleSelectScreen();
        virtual ~PaddleSelectScreen();
        void Update(SCREENS &mCurrentScreen,PlayScreen &mPlayScreen);
        void Render(PlayScreen &mPlayScree);

    private:
        Texture*title;
        Texture*undertitle;
        //
        SDL_Rect gSpriteClips;
        SDL_Rect gSpriteClips2;
        SDL_Rect gSpriteClipsPadles[4];
        int x,x2;
        int y,y2;
        int width,paddleW;
        int hight,paddleH;
        int currentPaddle;
        Texture*leftArrow;
        Texture*rightArrow;
        //Texture*padleTexture;
        InputManager*mInput;
};

#endif // PADDLESELECTSCREEN_H
