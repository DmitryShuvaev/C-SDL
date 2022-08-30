#include "PlayerIdleState.h"

PlayerIdleState::PlayerIdleState()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
}

PlayerIdleState::~PlayerIdleState()
{
    //dtor
}
void PlayerIdleState::Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen,PlayerSwingSwordState&mSwordScreen)
{
    mInput->Update();

    if(mInput->KeyDown(SDL_SCANCODE_LEFT))
    {
          mSwordScreen.anim_start=true;
      mCurrentScreen=walking;
    }
    else if(mInput->KeyDown(SDL_SCANCODE_RIGHT))
    {
            mSwordScreen.anim_start=true;
      mCurrentScreen=walking;
    }
    else if(mInput->KeyDown(SDL_SCANCODE_UP))
    {
          mSwordScreen.anim_start=true;
      mCurrentScreen=walking;
    }
    else if(mInput->KeyDown(SDL_SCANCODE_DOWN))
    {
           mSwordScreen.anim_start=true;
      mCurrentScreen=walking;
    }
    else if(mInput->KeyDown(SDL_SCANCODE_SPACE))
    {
           mCurrentScreen=SwingSwordState;
      mAudioMgr->PlaySFX("sounds/sword.wav",0,1);
    }
    /*
    if(mInput->KeyDown(SDL_SCANCODE_LEFT)||mInput->KeyDown(SDL_SCANCODE_RIGHT)||
       mInput->KeyDown(SDL_SCANCODE_UP)||mInput->KeyDown(SDL_SCANCODE_DOWN))
    {
      mSwordScreen.anim_start=true;
      mCurrentScreen=walking;
    }else if(mInput->KeyDown(SDL_SCANCODE_SPACE))
    {
        mCurrentScreen=SwingSwordState;
        mAudioMgr->PlaySFX("sounds/sword.wav",0,1);
    }
     */
   mPlayScreen.mAnimation->mAnimationTimer=0.2f;
   //cout<<"idlestate"<<endl;

}
