#include "Animation.h"

Animation::Animation()
{
    //ctor
    mTimer = Timer::Instance();
    mAnimationTimer=0.2f;
    mgemTimeanim=Timer::Instance();

}

Animation::~Animation()
{
    //dtor

}
void Animation::movinAnimation(Character & mcharacter)
{

mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/0.2f>=1)
{
    if(count==2)
    {
     mcharacter.gSpriteClip.x =  160;
        Reset();
    }
    else if (count==1)
    {
      mcharacter.gSpriteClip.x =  144;
    }
     count++;
     mAnimationTimer=0.0f;
}

}
//jump animation
void Animation::jumpAnimation(Character & mcharacter)
{

mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/0.2f>=1)
{

    if(count==1)
    {
      mcharacter.gSpriteClip.x =  32;
      count=0;
      mAnimationTimer=0.f;
    }
     count++;
     mAnimationTimer=0.0f;
}

}
void Animation::gemAnimation(int &y)
{
mgemAnimationTimer += mgemTimeanim->DeltaTime();
//gemcounter++;

 if(mgemAnimationTimer/1.f>=1)
 {
     mgemAnimationTimer=0.0f;
     startanim=false;
 }else
 {
  y-=gemcounter;
 }
}
void Animation::Reset()
{
      count=0;
      mAnimationTimer=0.f;

}
