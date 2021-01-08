#include "Paddle.h"

Paddle::Paddle()
{
    //ctor
    mInput=InputManager::Instance();
    padle=new Texture("graphics/breakout.png");

        gSpriteClips.x =  32;
		gSpriteClips.y =  64;
		gSpriteClips.w = 64;
		gSpriteClips.h = 16;
//		        gSpriteClips2.x =  32;
//		gSpriteClips2.y =  96;
//		gSpriteClips2.w = 64;
//		gSpriteClips2.h = 16;
        x=WINDOW_WIDTH/2-32*Scalex;
        y=WINDOW_HEIGHT-32*Scaley;
        //
        width=gSpriteClips.w *Scalex;
        hight=gSpriteClips.h*Scaley;
        //

}

Paddle::~Paddle()
{
    //dtor
    mInput=NULL;
    delete padle;
    padle=NULL;
}
void Paddle::Update()
{
    mInput->Update();
    ifmove=false;
    if(mInput->KeyDown(SDL_SCANCODE_LEFT))
    {
    if(x>0)
    {
      dx=-PADDLE_SPEED;
      x =x  +dx;
    }
    ifmove=true;
    }
    else if(mInput->KeyDown(SDL_SCANCODE_RIGHT))
    {
     if(x+width<WINDOW_WIDTH)
     {
      dx=PADDLE_SPEED;
      x =x +dx;
     }
     ifmove=true;
    }
//    if(x<0)
//    {
//       // x=0;
//    }
//    else if(x+width>WINDOW_WIDTH)
//    {
//        //x=WINDOW_WIDTH-width;
//    }

}
void Paddle::Render()
{
padle->render( x, y, &gSpriteClips,width,hight );
//padle->render( x, y-100, &gSpriteClips2,Scalex,Scaley );
}
