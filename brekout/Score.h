#ifndef SCORE_H
#define SCORE_H
#include "Texture.h"
#include "Collision.h"
#include "InputManager.h"
#include <cstring>

class Score:public Collision
{
    public:
        Score();
        Score(int scorev);
        void init();
        virtual ~Score();
SDL_Color color[2] = {{255,255,255},{255,0,0}};
float ic=2.5;
int scoreValue=0;
        void Update(SCREENS &mCurrentScreen,int &scorev);
        void Update(SCREENS &mCurrentScreen);
        void Render();
        void SetTextValue(int &scorev);
char*conveText(std::string scoreStr);
bool ifUpdate=false;
    private:
        Texture*score;
        Texture*title;
        Texture*presEnt;
        InputManager*mInput=NULL;

};

#endif // SCORE_H
