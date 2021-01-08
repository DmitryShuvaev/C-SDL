#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H
#include "Texture.h"
#include "InputManager.h"
#include "Collision.h"
#include "PlayScreen.h"
#include <sstream>
class VictoryScreen:public Collision
{
    public:
        VictoryScreen();
        virtual ~VictoryScreen();
        void Update(SCREENS &mCurrentScreen,int &scorevalue,PlayScreen&mPlayScreen,Health &health,int&level);
        void Render(PlayScreen&mPlayScreen);
        const int FONT_SIZE=16*3;
 Texture*title;
 Texture*levelText;
 InputManager*mInput;
 std::stringstream levelSText;
    protected:

    private:
};

#endif // VICTORYSCREEN_H
