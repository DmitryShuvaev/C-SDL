#include "StartScreen.h"

StartScreen::StartScreen()
{
    //ctor
    mInput=InputManager::Instance();
continueText=new Texture("flappy.ttf","Continue",FONT_SIZE,color[0]);
exitText=new Texture("Peepo.ttf","Exit",FONT_SIZE,color[0]);
continueText->SetXY(continueText->mGraphics->SCREEN_WIDTH/2 - continueText->mWidth/2,continueText->mGraphics->SCREEN_HEIGHT/2 - continueText->mHeight);
exitText->SetXY(exitText->mGraphics->SCREEN_WIDTH/2 - exitText->mWidth/2,
                (exitText->mGraphics->SCREEN_HEIGHT/2 - exitText->mHeight)+SIZE*3);

//
title=new Texture("flappy.ttf","Fifty Bird",28*ic,color[0]);
title->SetXY(title->mGraphics->SCREEN_WIDTH/2 - title->mWidth/2,
                64*ic);
presEnter=new Texture("flappy.ttf","Press Enter",14*ic,color[0]);
presEnter->SetXY(presEnter->mGraphics->SCREEN_WIDTH/2 - presEnter->mWidth/2,
                100*ic);

}
void StartScreen:: drawMenuTex(SDL_Surface* menu,SDL_Rect &p)
{

}//
bool StartScreen::colidecontinue()
{
 if(mInput->mMouseXPos>=continueText->mRenderRect.x && mInput->mMouseXPos<=continueText->mRenderRect.x+continueText->mWidth &&
   mInput->mMouseYPos>=continueText->mRenderRect.y && mInput->mMouseYPos<=continueText->mRenderRect.y+continueText->mHeight)
   return true;
   return false;
}
bool StartScreen::colideexit()
{
 if(mInput->mMouseXPos>=exitText->mRenderRect.x && mInput->mMouseXPos<=exitText->mRenderRect.x+exitText->mWidth &&
   mInput->mMouseYPos>=exitText->mRenderRect.y && mInput->mMouseYPos<=exitText->mRenderRect.y+exitText->mHeight)
   return true;
   return false;
}
void StartScreen::Update(SCREENS &mCurrentScreen)
{

    mInput->Update();


    if(mInput->KeyPressed(SDL_SCANCODE_KP_ENTER))
    {
               cout<<"enter"<<endl;
     mCurrentScreen=play;
    }
}//end update
void StartScreen::Render()
{

    continueText->Render();
    exitText->Render();
    title->Render();
    presEnter->Render();
}
StartScreen::~StartScreen()
{
    //dtor
    delete continueText;
    continueText=NULL;
    delete exitText;
    exitText=NULL;
    mInput=NULL;

    delete title;
    title=NULL;
    delete presEnter;
    presEnter=NULL;
}
