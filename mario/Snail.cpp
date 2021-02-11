#include "Snail.h"

Snail::Snail()
{
    //ctor
        gSpriteClip.x =  0;
		gSpriteClip.y =  96;
		gSpriteClip.w = 16;
		gSpriteClip.h = 16;
        width=gSpriteClip.w *Scalex;
        hight=gSpriteClip.h*Scaley;
        x=width;
        y=hight;
        //
    mTimer = Timer::Instance();
    mAnimationTimer=0.2f;
    //
    mTimer2 = Timer::Instance();
}

Snail::~Snail()
{
    //dtor
}
void Snail::Render()
{
//Snail->render( x, y, &gSpriteClip,width,hight );
//render( backgrX, backgrY, &backgroundSpriteClip,backgroundwidth,backgroundhight );

}
void Snail::RenderFlipped()
{

   // Snail->RenderFlipped( x, y, &gSpriteClip,width,hight );
}
//------------------------------------------------------------------------------
void Snail::movinAnimation(float t)
{

mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/t>=1)
{
    if(count==2)
    {
     gSpriteClip.x =  0;
      count=0;
      mAnimationTimer=0.f;
    }
    else if (count==1)
    {
      gSpriteClip.x =  16;
    }
     count++;
     mAnimationTimer=0.0f;
}

}
//------------------------------------------------------------------------------
void Snail::idleAnimation()
{
    gSpriteClip.x =  32;
    mAnimationTimer += mTimer->DeltaTime();

    if(mAnimationTimer/1.f>=1)
    {
        if(count==5)
        {

          count=0;
          mAnimationTimer=0.f;
          state=moving;
          gSpriteClip.x =  0;
        }

         count++;
         mAnimationTimer=0.0f;
    }

}
