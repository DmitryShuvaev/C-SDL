#ifndef BRICK_H
#define BRICK_H
#include "Texture.h"
#include "AudioManager.h"
#include "Gem.h"
class Brick
{
    public:
        Brick();
        Brick(const int x,const int y,const int w,const int h);
        virtual ~Brick();
        void Update();
        void Render();
        void hit();
        void move();
        void initLevel();
        void renderParticles();
        bool gemColide(int xA,int yA,int w,int h);
        bool fallColide(int xA,int yA,int Aw,int Ah);
        float Scalex=5;
    float Scaley=5;
    int x;
    int y;
    int width;
    int hight;
    Texture*brick;
SDL_Rect gSpriteClip;
AudioManager* mAudioMgr;
bool inPlay;
bool solid;
SDL_Rect gSpriteClips[6];
bool topper=false;
bool jump_blocks=false;
int randx_jumpBlock;
int randy_jumpBlock;
Gem*gem=NULL;
int gemx;
int gemy;
bool isGem=false;
bool startAnimation=false;
bool consumad=false;
    private:
};

#endif // BRICK_H
