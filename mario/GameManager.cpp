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
    timeText.str( "" );
    gFPSTextTexture=new Texture("fonts/font.ttf","",8*3,{0, 255, 0});
    gFPSTextTexture->SetXY(5,5);
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
    LTimer fpsTimer;
    fpsTimer.fpsinit();
 while(!mQuit)
 {
     mTimer->Update();
     while(SDL_PollEvent(&mEvents) != 0) {
     //Checks if the user quit the game
        if(mEvents.type == SDL_QUIT) {

            mQuit = true;
        }
    }

    if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE))
    {
        fpsTimer.fpsthink();
    //Set text to be rendered
     timeText.str( "" );
     timeText << "FPS: " << round(fpsTimer.framespersecond);//FRAME_RATE-(mTimer->DeltaTime()-(1.0f / FRAME_RATE));

     gFPSTextTexture->SetText(timeText.str().c_str(),{0, 255, 0});

     EarlyUpdate();
     Update();
     LateUpdate();
     Render();
    }
 //SDL_Delay(1000/60);
 }
}//

void GameManager::Update()
{

        if(mScreenMgr->mCurrentScreen==mScreenMgr->SCREENS::start)
        {

            if(mScreenMgr->mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
            {
               //cout<<"relesed"<<endl;
               mQuit = true;

            }

        }
         mScreenMgr->Update();
}//

void GameManager::Render()
{
    //Clears the last frame's render from the back buffer
    mGraphics->ClearBackBuffer();
    mScreenMgr->Render();
gFPSTextTexture->Render();
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
//

