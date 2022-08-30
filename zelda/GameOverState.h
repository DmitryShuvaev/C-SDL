#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "Texture.h"
#include "PlayScreen.h"
#include <iostream>
#include "InputManager.h"
#include "Collision.h"
#include <memory>
class GameOverState:public Collision
{
    public:
        GameOverState();
        virtual ~GameOverState();
        void Render();
        void Update(SCREENS &mCurrentScreen,PlayScreen*mPlayScreen);
        void Set_new_playscreen(SCREENS &mCurrentScreen,PlayScreen*mPlayScreen);
        SDL_Color color={175,53,42};
        Texture*title;
        InputManager*mInput;
};

#endif // GAMEOVERSTATE_H
