#include "StartScreen.h"

StartScreen::StartScreen()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
    title=new Texture("fonts/font.ttf","BREAKOUT",FONT_SIZE,{255,255,255});
    title->SetXY(title->mGraphics->WINDOW_WIDTH/2 - title->mWidth/2,
                    title->mGraphics->WINDOW_HEIGHT/2 -130);
    start=new Texture("fonts/font.ttf","START",FONT_SIZE/2,{103,255,255});
    start->SetXY(start->mGraphics->WINDOW_WIDTH/2 - start->mWidth/2,
                    start->mGraphics->WINDOW_HEIGHT/2 +200);
    highScore=new Texture("fonts/font.ttf","HIGH SCORES",FONT_SIZE/2,{255,255,255});
    highScore->SetXY(highScore->mGraphics->WINDOW_WIDTH/2 - highScore->mWidth/2,
                    highScore->mGraphics->WINDOW_HEIGHT/2 +260);
    //default highlited is 1
    //start->SetColor({103,255,255});
}


void StartScreen::Update(SCREENS &mCurrentScreen)
{

    mInput->Update();
    if(mInput->KeyPressed(SDL_SCANCODE_RETURN))
    {
        mAudioMgr->PlaySFX("sounds/confirm.wav",0,1);
        if(highlighted==1)
        {

         mCurrentScreen=paddle_select;
        }
        else if(highlighted==2)
        {

         mCurrentScreen=high_scores;
        }

    }
    else if(mInput->KeyPressed(SDL_SCANCODE_KP_ENTER))
    {
        mAudioMgr->PlaySFX("sounds/confirm.wav",0,1);
        if(highlighted==1)
        {

         mCurrentScreen=paddle_select;
        }

    }
    else if(mInput->KeyPressed(SDL_SCANCODE_UP))
    {
     mAudioMgr->PlaySFX("sounds/paddle_hit.wav",0,1);
     highlighted=1;
     ifHighlited=true;
    }
    else if(mInput->KeyPressed(SDL_SCANCODE_DOWN))
    {
     mAudioMgr->PlaySFX("sounds/paddle_hit.wav",0,1);
     highlighted=2;
     ifHighlited=true;
    }
    if(ifHighlited)
    {
        if(highlighted==1)
        {
          start->SetColor({103,255,255});
          highScore->SetColor({255,255,255});
          ifHighlited=false;
        }else if(highlighted==2)
        {
          start->SetColor({255,255,255});
          highScore->SetColor({103,255,255});
          ifHighlited=false;
        }
    }

}//end update
void StartScreen::Render()
{

 title->Render();
 start->Render();
 highScore->Render();
}
StartScreen::~StartScreen()
{
    //dtor

    mInput=NULL;
    AudioManager::Release();
    mAudioMgr = NULL;
}
