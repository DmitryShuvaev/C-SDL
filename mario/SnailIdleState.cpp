#include "SnailIdleState.h"

SnailIdleState::SnailIdleState()
{
    //ctor
    mTimer = Timer::Instance();
    mAnimationTimer=0.2f;
}

SnailIdleState::~SnailIdleState()
{
    //dtor
}
//------------------------------------------------------------------------------
void SnailIdleState::Update(PlayScreen&mPlayScreen,Snail&snail)
{

    snail.idleAnimation();

    if(snail.movingDirection==Snail::DIRECTION::left)
      snail.renderflipp=false;
    else snail.renderflipp=true;
    // calculate difference between snail and player on X axis
    // and only chase if <= 5 tiles
    int diffX = abs(mPlayScreen.character->x - snail.x);
    if(diffX < 5 * TILE_SIZE)
    {
      snail.state=snail.chasing;
      snail.gSpriteClip.x =  0;
      snail.movingTimer=0;
      snail.count=0;
      //cout<<"idlchase"<<endl;
    }
}
//------------------------------------------------------------------------------
void SnailIdleState::idleAnimation(Snail&snail)
{
    snail.gSpriteClip.x =  32;
    mAnimationTimer += mTimer->DeltaTime();

    if(mAnimationTimer/1.f>=1)
    {
        if(count==5)
        {

          count=0;
          mAnimationTimer=0.f;
          snail.state=snail.moving;
          snail.gSpriteClip.x =  0;
        }

         count++;
         mAnimationTimer=0.0f;
    }

}
