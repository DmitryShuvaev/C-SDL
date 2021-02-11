#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H
#include <vector>
#include <iostream>
#include <memory>
#include "Texture.h"
#include "Collision.h"
#include "AudioManager.h"
#include <cstring>
#include "InputManager.h"
#include "Character.h"
#include "LevelMaker.h"
#include "Animation.h"
#include "Snail.h"

using namespace std;

class PlayScreen:Collision
{
    public:
        PlayScreen();
//        void init();

        void Update(SCREENS &mCurrentScreen);
        void Render();
        void clearScreen();
        void moveLeft();
        void moveRight();
        void moveGem();
        void deleteColissnailar();
        void SnailArray(Snail&snail);
        void init();
        void removeSnail(Snail *&original, int &SIZESnail,int &old_size);
        void renderSnailarr();
        bool snailColide(Snail&snail,Character&character );
        void SetscoreText();
        ~PlayScreen();
        //char*conveText(std::string scoreStr);
    protected:

    private:

    const int SIZE=16;
    SDL_Color color[2] = {{255,255,255},{255,0,0}};

        public:
        Texture *pause;
        AudioManager* mAudioMgr;
        InputManager*mInput;
        SDL_Rect gSpriteClips;
        Texture*score;
        Texture*blackscore;
        //score value
        int scoreValue=0;
        std::stringstream scoreText;
        bool paused=false;
        bool animLeft=false;
        Character*character=NULL;
        LevelMaker *lmaker;
        Animation*mAnimation;
        float characterDY=0.0;
        float JUMP_VELOCITY=-70;
        float GRAVITY = 2;
        bool jumped=false;
        bool activeJump=false;
        int c=0;
        float dx=0;
        //
        float PLAYER_WALK_SPEED=6;
        Texture *background;
        SDL_Rect backgroundSpriteClip;
        int backgroundwidth;
        int backgroundhight;
        int backgrX=0;
        int backgrY=-130;
        int backgrX2=256;
        //
        Snail*snail=NULL;
        Texture *snailTexture;
        int SIZESnail=1;int old_size=0;
        int indx=0;
        void spawnEnemies();

        //temp array to check snail collision with caracter
        int sizeSnailColisarr=1;
        int indxsnailcol=0;
        int snailold_size=0;
        Snail*checksnailcolis=NULL;

        //Timer* mTimer;
};

#endif // PLAYSCREEN_H
