#include "Brick.h"

Brick::Brick()
{
    //ctor
        mAudioMgr = AudioManager::Instance();
        //brick=new Texture("graphics/breakout.png");

        gSpriteClip.x =  0;
		gSpriteClip.y =  0;
		gSpriteClip.w = 16;
		gSpriteClip.h = 16;
        width=gSpriteClip.w *Scalex;
        hight=gSpriteClip.h*Scaley;
        x=width;
        y=hight;
        inPlay = true;
        initLevel();

}
void Brick::move()
{

}
Brick::~Brick()
{
    //dtor
    if(brick!=NULL)
    {
     delete brick;
     brick=NULL;
    }
    if(gem!=NULL)
    {
     delete gem;
     gem=NULL;
    }

    AudioManager::Release();
    mAudioMgr = NULL;

}
void Brick::Update()
{

}
void Brick::Render()
{

    brick->render( x, y, &gSpriteClip,width,hight );


}
//
bool Brick::gemColide(int xA,int yA,int Aw,int Ah)
{
     if(xA+width>=gemx &&
        gemx+width>=xA &&
        yA+Ah>=gemy &&
        gemy+hight>=yA)
     {
         return true;
     }
     return false;
}
bool Brick::fallColide(int xA,int yA,int Aw,int Ah)
{
     if(xA+Aw>=x &&
        x+width>=xA &&
        yA+Ah>=y &&
        y+hight>=yA)
     {
         return true;
     }
     return false;
}
//
Brick::Brick(const int x,const int y,const int w,const int h)
{
         mAudioMgr = AudioManager::Instance();
        //brick=new Texture("graphics/tiles.png");

        gSpriteClip.x =  x;
		gSpriteClip.y =  y;
		gSpriteClip.w = w;
		gSpriteClip.h = h;
        width=gSpriteClip.w *Scalex;
        hight=gSpriteClip.h *Scaley;
        this->x=width;
        this->y=hight;
        inPlay = true;
        initLevel();

}
//
void Brick::initLevel()
{


}
