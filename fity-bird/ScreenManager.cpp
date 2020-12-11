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
    if(scrolling)mBacplane->Update(mCurrentScreen);
 switch(mCurrentScreen)
 {
 case start:
    mStartScreen->Update(mCurrentScreen);

   if(mStartScreen->colidecontinue())
   {
       mStartScreen->continueText->SetColor({255,0,0});
        if(mInput->MouseButtonPressed(mInput->left))
        {
                     cout<<"left mouse"<<endl;
           mCurrentScreen=CountdownState;
           mStartScreen->continueText->SetColor({0,204,0});
        }

   }
   else
   {
    mStartScreen->continueText->SetColor({255,255,255});
   }

    break;
 case play:
   scoreState->ifUpdate=true;

    mPlayScreen->Update(mCurrentScreen,scoreValue,scrolling);
    if(mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
    {
      mCurrentScreen=start;


    }
    break;
 case score:


    scoreState->Update(mCurrentScreen,scoreValue);
    break;
 case CountdownState:

    mCountScreen->Update(mCurrentScreen,scrolling) ;
    break;
 }
}//

void ScreenManager::Render()
{

    mBacplane->Render();
 switch(mCurrentScreen)
 {
 case start:

    mStartScreen->Render();
    break;
 case play:

    mPlayScreen->Render();
    break;
 case score:

   scoreState->Render();
    break;
 case CountdownState:

    mCountScreen->Render() ;
    break;
 }
}
ScreenManager::ScreenManager()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
    mBacplane=new BackPlane();
    mStartScreen=new StartScreen();
    mCurrentScreen=start;
    mPlayScreen=new PlayScreen();
    scoreState=new Score();
    mCountScreen=new Countdown();
//    sound=new SDL2SoundEffets();
//    sound->addSoundEffect("marios_way.mp3");
//    sound->playSoundEffect(0,-1);
 mAudioMgr->PlaySFX("marios_way.mp3",-1);
}

ScreenManager::~ScreenManager()
{
    //dtor
    mInput=NULL;
    delete mStartScreen;
    mStartScreen=NULL;
    delete mPlayScreen;
    mPlayScreen=NULL;
    delete scoreState;
    scoreState=NULL;
    delete mCountScreen;
    mCountScreen=NULL;
    delete mBacplane;
    mBacplane=NULL;
//    delete sound;
//    sound=NULL;
}
