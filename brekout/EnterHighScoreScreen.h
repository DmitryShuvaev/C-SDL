#ifndef ENTERHIGHSCORESCREEN_H
#define ENTERHIGHSCORESCREEN_H
#include "Texture.h"
#include "Collision.h"
#include "InputManager.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
class EnterHighScoreScreen:public Collision
{
    public:
        EnterHighScoreScreen();
        virtual ~EnterHighScoreScreen();
        void Update(SCREENS &mCurrentScreen, HighScores *mHighScores,int&highScoreIndex,int &score);
        void Render();
        const int FONT_SIZE=32*3;
        InputManager*mInput;
        Texture*title;
        Texture*char1;
        Texture*char2;
        Texture*char3;
        Texture*yourscoreText;
        int chars[3]={65,66,67};
        std::stringstream scoreText;
    private:
       int highlightedChar = 0;
       bool ifHighlited=false;
};

#endif // ENTERHIGHSCORESCREEN_H
