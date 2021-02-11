#include "PlayerIdleState.h"

PlayerIdleState::PlayerIdleState()
{
    //ctor
    mInput=InputManager::Instance();
}

PlayerIdleState::~PlayerIdleState()
{
    //dtor
}
void PlayerIdleState::Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen)
{
    mInput->Update();
    //cout<<"Idle"<<endl;
    if(mInput->KeyDown(SDL_SCANCODE_LEFT)||mInput->KeyDown(SDL_SCANCODE_RIGHT))
    {
      mCurrentScreen=walking;
    }
    else if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
   {
    //cout<<characterDY<<endl;
    mPlayScreen.character->gSpriteClip.x =32;
    mPlayScreen.characterDY = mPlayScreen.JUMP_VELOCITY;
      //jumped=false;
    mCurrentScreen=jump;

   }
  // mPlayScreen.animLeft=false;
   //mPlayScreen.character->gSpriteClip.x =0;
   mPlayScreen.mAnimation->mAnimationTimer=0.2f;
//check if we've collided with any entities and die if so
    for (int i = 0; i < mPlayScreen.old_size; i++)
    {
        if(mPlayScreen.snail[i].x>=0&&mPlayScreen.snail[i].x<=WINDOW_WIDTH)
        if(mPlayScreen.snailColide(mPlayScreen.snail[i],*mPlayScreen.character))
        {
            if(!mPlayScreen.snail[i].consumad)
            mCurrentScreen=start;
        }
    }
}
