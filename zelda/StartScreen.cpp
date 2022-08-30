#include "StartScreen.h"

StartScreen::StartScreen()
{
    //ctor
    mInput=InputManager::Instance();

//
background=new Texture("background.png");
//  background->mRenderRect.w=background->mRenderRect.w*ic;
//  background->mRenderRect.h=background->mRenderRect.h*ic;
title=new Texture("zelda.otf","Legend of 50",64*ic,color[2]);
title->SetXY(title->mGraphics->SCREEN_WIDTH/2 - title->mWidth/2,
                SCREEN_HEIGHT/2-(32*ic));
titlelow=new Texture("zelda.otf","Legend of 50",64*ic,color[3]);
titlelow->SetXY(titlelow->mGraphics->SCREEN_WIDTH/2 - titlelow->mWidth/2,
                SCREEN_HEIGHT/2-(30*ic));
presEnter=new Texture("zelda.otf","Press Enter",32*ic,color[0]);
presEnter->SetXY(presEnter->mGraphics->SCREEN_WIDTH/2 - presEnter->mWidth/2,
                SCREEN_HEIGHT/2+(64*ic));

}
void StartScreen:: drawMenuTex(SDL_Surface* menu,SDL_Rect &p)
{

}//

void StartScreen::Update(SCREENS &mCurrentScreen,PlayScreen*mPlayScreen)
{

    mInput->Update();
    if(mPlayScreen->mInput->KeyPressed(SDL_SCANCODE_RETURN))
    {
               //cout<<"enter"<<endl;
     mCurrentScreen=walking;
    }
    else if(mPlayScreen->mInput->KeyPressed(SDL_SCANCODE_KP_ENTER))
    {
               //cout<<"enterkp"<<endl;
     mCurrentScreen=walking;
    }
}//end update
void StartScreen::Render()
{
    background->Render();
    titlelow->Render();
    title->Render();

    presEnter->Render();
}
StartScreen::~StartScreen()
{
    //dtor

    mInput=NULL;
    delete background;
    background=NULL;
    delete title;
    title=NULL;
    delete presEnter;
    presEnter=NULL;
}
