#include "GameManager.h"
GameManager*GameManager::sInstance=NULL;

GameManager*GameManager::Instance()
{
  if(sInstance==NULL)
  {
      sInstance=new GameManager();
  }
  return sInstance;
}
GameManager::GameManager()
{
    //ctor
    mQuit=false;
    //Initialize SDL
    mGraphics = Graphics::Instance();
    mScreenMgr=ScreenManager::Instance();
    mInputMgr=InputManager::Instance();
    mTimer = Timer::Instance();
}
void GameManager::Release() {

    delete sInstance;
    sInstance = NULL;

}//
void GameManager::EarlyUpdate()
{
 mTimer->Reset();
 //mInputMgr->Update();
}
void GameManager::LateUpdate()
{
  mInputMgr ->UpdatePrevInput();
}
void GameManager::Run()
{
//const int frameDelay=1000/FRAME_RATE;
//Uint32 frameStart;
//int frameTime;
 while(!mQuit)
 {
     mTimer->Update();
     //frameStart=SDL_GetTicks();
     while(SDL_PollEvent(&mEvents) != 0) {
     //Checks if the user quit the game
        if(mEvents.type == SDL_QUIT) {

            mQuit = true;
        }



    }
    if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE))
    {
     EarlyUpdate();
     Update();
     LateUpdate();
     Render();
    }

//     frameTime=SDL_GetTicks()-frameStart;
//    if(frameDelay>frameTime)
//    {
//        SDL_Delay(frameDelay-frameTime);
//    }

 }
}//

void GameManager::Update()
{

        if(mScreenMgr->mCurrentScreen==mScreenMgr->SCREENS::start)
        {
            if(mScreenMgr->mStartScreen->colideexit())
            {
                //EarlyUpdate();
                mScreenMgr->mInput->Update();
                mScreenMgr->mStartScreen->exitText->SetColor({255,0,0});
             if(mScreenMgr->mInput->MouseButtonPressed(mScreenMgr->mInput->left))
             {
                     cout<<"quit mouse"<<endl;
              mQuit = true;

             }
            }
            else
           {
            mScreenMgr->mStartScreen->exitText->SetColor({255,255,255});
           }

            if(mScreenMgr->mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
            {
               cout<<"relesed"<<endl;
               mQuit = true;

            }
             //if(mScreenMgr->mInput->KeyReleased(SDL_SCANCODE_ESCAPE))cout<<"relesed"<<endl;
        }
         mScreenMgr->Update();
}//

void GameManager::Render()
{
    //Clears the last frame's render from the back buffer
    mGraphics->ClearBackBuffer();
    mScreenMgr->Render();
    //Renders the current frame
    mGraphics->Render();
}
GameManager::~GameManager()
{
    //dtor
        Graphics::Release();
		mGraphics = NULL;
        InputManager::Release();
        mInputMgr=NULL;
        Timer::Release();
		mTimer = NULL;
}
