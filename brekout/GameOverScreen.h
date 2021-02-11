#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H
#include "Texture.h"
#include "InputManager.h"
#include "Collision.h"
#include "PlayScreen.h"
#include <sstream>
#include "HighScoreScreen.h"
class GameOverScreen:public Collision
{
    public:
        GameOverScreen();
        virtual ~GameOverScreen();

        void Update(SCREENS &mCurrentScreen,PlayScreen &mPlayScreen,int &score,Health &health,int&level,HighScores *mHighScores,int&highScoreIndex);
        void Render();
const int FONT_SIZE=32*3;
std::stringstream scoreText;
 Texture*title;
 Texture*finalScore;
 Texture*presEnter;
 InputManager*mInput;

    private:
};

#endif // GAMEOVERSCREEN_H
