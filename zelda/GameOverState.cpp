#include "GameOverState.h"

GameOverState::GameOverState()
{
    //ctor
    mInput=InputManager::Instance();
    //
    title=new Texture("zelda.otf","GAME OVER",64*3.4,color);
    title->SetXY(title->mGraphics->SCREEN_WIDTH/2 - title->mWidth/2,
                    SCREEN_HEIGHT/2-(52*3));
}

GameOverState::~GameOverState()
{
    //dtor
    delete title;
}
void GameOverState::Set_new_playscreen(SCREENS &mCurrentScreen,PlayScreen*mPlayScreen)
{
    if(mPlayScreen!=NULL)
    {
    mPlayScreen->ClearScreen();
    mPlayScreen->init();
    //mCurrentScreen=walking;
    }
}
void GameOverState::Update(SCREENS &mCurrentScreen,PlayScreen*mPlayScreen)
{
    //mInput->UpdatePrevInput();
     if(mPlayScreen->mInput->KeyPressed(SDL_SCANCODE_SPACE)==false)
     {
    if(mPlayScreen->mInput->KeyPressed(SDL_SCANCODE_RETURN))
       //it does't work if not separate keyPressed with else statement
    {
     mCurrentScreen=walking;
     //Set_new_playscreen(mCurrentScreen,mPlayScreen);
    }else if(mInput->KeyPressed(SDL_SCANCODE_KP_ENTER))
    {
     //Set_new_playscreen(mCurrentScreen,mPlayScreen);
    }
     }
}
void GameOverState::Render()
{
 title->Render();
}
