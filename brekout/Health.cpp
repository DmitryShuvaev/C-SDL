#include "Health.h"

Health::Health()
{
    //ctor
        mhealth=new Texture("graphics/breakout.png");

        gSpriteClips[0].x =  128;
		gSpriteClips[0].y =  48;
		gSpriteClips[0].w = 10;
		gSpriteClips[0].h = 10;
        width=gSpriteClips[0].w *Scalex;
        hight=gSpriteClips[0].h*Scaley;
        //
        gSpriteClips[1].x =  138;
		gSpriteClips[1].y =  48;
		gSpriteClips[1].w = 10;
		gSpriteClips[1].h = 10;
//        width=gSpriteClips[1].w *Scalex;
//        hight=gSpriteClips[1].h*Scaley;
        healthX=1280-100*Scalex;
        y=4*Scaley;
}

Health::~Health()
{
    //dtor
}
void Health::Update()
{

}
void Health::Render()
{
    int x=healthX;
    for(int i=0;i<health;i++)
    {
      mhealth->render( x, y, &gSpriteClips[0],width,hight );
      x = x+width;
    }

    for(int i=0;i<3 - health;i++)
    {
      mhealth->render( x, y, &gSpriteClips[1],width,hight );
      x = x+width;
    }
}
