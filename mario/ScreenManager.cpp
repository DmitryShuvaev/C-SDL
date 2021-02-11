#include "ScreenManager.h"
ScreenManager*ScreenManager::sInstance=NULL;
ScreenManager*ScreenManager::Instance()
{
  if(sInstance==NULL)
  {
      sInstance=new ScreenManager();
  }
  return sInstance;
}
void ScreenManager::Release()
{
    delete sInstance;
    sInstance = NULL;
}//
void ScreenManager::Update()
{

 switch(mCurrentScreen)
 {
 case start:
    mStartScreen->Update(mCurrentScreen,*mPlayScreen);
    break;
 case play:

    mPlayScreen->Update(mCurrentScreen);
    if(mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
    {
      mCurrentScreen=start;
    }

    break;
 case falling:
     mPlayScreen->Update(mCurrentScreen);
    mPlayerFallingState->Update(mCurrentScreen,*mPlayScreen);
    break;
 case walking:
     mPlayScreen->Update(mCurrentScreen);
    mPlayerWalkingState->Update(mCurrentScreen,*mPlayScreen);
    break;
 case idle:
     mPlayScreen->Update(mCurrentScreen);
    mPlayerIdleState->Update(mCurrentScreen,*mPlayScreen);
    break;
 case jump:
     mPlayScreen->Update(mCurrentScreen);
    mPlayerJumpState->Update(mCurrentScreen,*mPlayScreen);
    break;
 }
for (int i = 0; i < mPlayScreen->old_size; i++)
{


 switch(mPlayScreen->snail[i].state)
 {
 case moving:
   smoveanim->Update(*mPlayScreen,mPlayScreen->snail[i]);
   break;
 case idleS:
   msnailIdlestate->Update(*mPlayScreen,mPlayScreen->snail[i]);
 break;
 case chasing:
  msnailChaisestate->Update(*mPlayScreen,mPlayScreen->snail[i]);
 break;
 }
}
}//

void ScreenManager::Render()
{

 //
     switch(mCurrentScreen)
     {
      case start:
        mStartScreen->Render(*mPlayScreen);
        break;
      case play:
      case falling:
      case walking:
      case idle:
      case jump:
        mPlayScreen->Render();
        break;
     }
}
ScreenManager::ScreenManager()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
    mStartScreen=new StartScreen();
    mPlayScreen=new PlayScreen();
    mPlayerFallingState=new PlayerFallingState();
    mPlayerWalkingState=new PlayerWalkingState();
    mPlayerIdleState=new PlayerIdleState();
    mPlayerJumpState=new PlayerJumpState();
    //
    smoveanim=new SnailMovingState();
    msnailIdlestate=new SnailIdleState();
    msnailChaisestate=new SnailChasingState();
    //mCurrentScreen=play;
    //mCurrentScreen=falling;
    mCurrentScreen=start;
}

ScreenManager::~ScreenManager()
{
    //dtor
    mInput=NULL;
    delete mStartScreen;
    mStartScreen=NULL;
    delete mPlayScreen;
    mPlayScreen=NULL;
    delete mPlayerFallingState;
    mPlayerFallingState=NULL;
    delete mPlayerWalkingState;
    mPlayerWalkingState=NULL;
    delete mPlayerIdleState;
    mPlayerIdleState=NULL;
    delete mPlayerJumpState;
    mPlayerJumpState=NULL;
    delete msnailIdlestate;
    msnailIdlestate=NULL;
    delete msnailChaisestate;
    msnailChaisestate=NULL;
}

