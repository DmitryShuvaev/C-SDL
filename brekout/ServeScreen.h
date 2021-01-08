#ifndef SERVESCREEN_H
#define SERVESCREEN_H
#include "Texture.h"
#include "Collision.h"
#include "PlayScreen.h"
#include "InputManager.h"
class ServeScreen:public Collision
{
    public:
        ServeScreen();
        virtual ~ServeScreen();

        void Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen);
        void Render(PlayScreen&mPlayScreen);
        const int FONT_SIZE=16*3;
 Texture*title;
 InputManager*mInput;
    private:
};

#endif // SERVESCREEN_H
