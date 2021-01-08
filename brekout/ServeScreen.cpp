#include "ServeScreen.h"

ServeScreen::ServeScreen()
{
    //ctor
    mInput=InputManager::Instance();
        title=new Texture("fonts/font.ttf","Press Enter to serve!",FONT_SIZE,{255,255,255});
    title->SetXY(title->mGraphics->WINDOW_WIDTH/2 - title->mWidth/2,
                    title->mGraphics->WINDOW_HEIGHT/2 );
}

ServeScreen::~ServeScreen()
{
    //dtor
    delete title;
    title=NULL;
    mInput=NULL;
}
void ServeScreen::Update(SCREENS &mCurrentScreen,PlayScreen &mPlayScreen)
{
 mInput->Update();

 if(mInput->KeyPressed(SDL_SCANCODE_RETURN))
 {
   mCurrentScreen=play;
 }
 mPlayScreen.padlle->Update();
  mPlayScreen.ball->x=mPlayScreen.padlle->x + (mPlayScreen.padlle->width / 2) - mPlayScreen.ball->width/2;
  mPlayScreen.ball->y=mPlayScreen.padlle->y-mPlayScreen.ball->hight;
}//

void ServeScreen::Render(PlayScreen&mPlayScreen)
{
 title->Render();
 mPlayScreen.Render();
}
