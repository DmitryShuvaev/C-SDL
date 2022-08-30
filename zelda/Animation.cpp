#include "Animation.h"

Animation::Animation()
{
    //ctor
    mTimer = Timer::Instance();
    mAnimationTimer=0.12f;
    mgemTimeanim=Timer::Instance();

}

Animation::~Animation()
{
    //dtor

}
void Animation::movinAnimation_Left(Player & mcharacter)
{

mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/0.12f>=1)
{
    if(count==4)
    {
     mcharacter.gSpriteClip.x =  1;
     mcharacter.gSpriteClip.y =  102;
        Reset();
    }
    else if (count==3)
    {
      mcharacter.gSpriteClip.x =  17;
      mcharacter.gSpriteClip.y =  102;
    }
        else if (count==2)
    {
      mcharacter.gSpriteClip.x =  33;
      mcharacter.gSpriteClip.y =  102;
    }
            else if (count==1)
    {
      mcharacter.gSpriteClip.x =  49;
      mcharacter.gSpriteClip.y =  102;
    }
     count++;
     mAnimationTimer=0.0f;
}

}
void Animation::movinAnimation_Right(Player&mcharacter)
{
mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/0.12f>=1)
{
    if(count==4)
    {
     mcharacter.gSpriteClip.x =  2;
     mcharacter.gSpriteClip.y =  38;
        Reset();
    }
    else if (count==3)
    {
      mcharacter.gSpriteClip.x =  18;
      mcharacter.gSpriteClip.y =  38;
    }
        else if (count==2)
    {
      mcharacter.gSpriteClip.x =  34;
      mcharacter.gSpriteClip.y =  38;
    }
            else if (count==1)
    {
      mcharacter.gSpriteClip.x =  50;
      mcharacter.gSpriteClip.y =  38;
    }
     count++;
     mAnimationTimer=0.0f;
}
}
void Animation::movinAnimation_Up(Player & mcharacter)
{

mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/0.12f>=1)
{
    if(count==4)
    {
     mcharacter.gSpriteClip.x =  0;
     mcharacter.gSpriteClip.y =  70;

        Reset();
    }
    else if (count==3)
    {
      mcharacter.gSpriteClip.x =  16;
      mcharacter.gSpriteClip.y =  70;
    }
    else if (count==2)
    {
      mcharacter.gSpriteClip.x =  32;
      mcharacter.gSpriteClip.y =  70;
    }
    else if (count==1)
    {
      mcharacter.gSpriteClip.x =  48;
      mcharacter.gSpriteClip.y =  70;
    }
     count++;
     mAnimationTimer=0.0f;
}


}
void Animation::movinAnimation_Down(Player & mcharacter)
{

mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/0.12f>=1)
{
    if(count==4)
    {
     mcharacter.gSpriteClip.x =  1;
     mcharacter.gSpriteClip.y =  6;
        Reset();
    }
    else if (count==3)
    {
      mcharacter.gSpriteClip.x =  17;
      mcharacter.gSpriteClip.y =  6;
    }
    else if (count==2)
    {
      mcharacter.gSpriteClip.x =  33;
      mcharacter.gSpriteClip.y =  6;
    }
    else if (count==1)
    {
      mcharacter.gSpriteClip.x =  49;
      mcharacter.gSpriteClip.y =  6;
    }
    else if (count==0)
    {
      mcharacter.gSpriteClip.x =  1;
      mcharacter.gSpriteClip.y =  6;
    }
     count++;
     mAnimationTimer=0.0f;
}

}
void Animation:: setIdle(Player & mcharacter)
{
 switch(curentanim)
 {
 case left:
    mcharacter.gSpriteClip.x =  1;
    mcharacter.gSpriteClip.y =  102;
    break;
 case right:
    mcharacter.gSpriteClip.x =  2;
    mcharacter.gSpriteClip.y =  38;
    break;
 case up:
    mcharacter.gSpriteClip.x =  0;
    mcharacter.gSpriteClip.y =  69;
    break;
 case down:
    mcharacter.gSpriteClip.x =  1;
    mcharacter.gSpriteClip.y =  6;
    break;
 }
}

void Animation::Reset()
{
      count=0;
      mAnimationTimer=0.f;
     anim_start=false;
}
//Dungeon animation
void Animation::movinAnimation_Up_dungeon(Player & mcharacter)
{

mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/0.12f>=1)
{
    if(count==32)
    {
     mcharacter.gSpriteClip.x =  0;
     mcharacter.gSpriteClip.y =  70;

        Reset();
    }
    else if (count==24)
    {
      mcharacter.gSpriteClip.x =  16;
      mcharacter.gSpriteClip.y =  70;
    }
    else if (count==16)
    {
      mcharacter.gSpriteClip.x =  32;
      mcharacter.gSpriteClip.y =  70;
    }
    else if (count==8)
    {
      mcharacter.gSpriteClip.x =  48;
      mcharacter.gSpriteClip.y =  70;
    }
     count++;
     mAnimationTimer=0.0f;
}


}

