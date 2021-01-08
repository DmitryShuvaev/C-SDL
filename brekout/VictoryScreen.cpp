#include "VictoryScreen.h"

VictoryScreen::VictoryScreen()
{
    //ctor
    mInput=InputManager::Instance();
    title=new Texture("fonts/font.ttf","Press Enter to serve!",FONT_SIZE,{255,255,255});
    title->SetXY(title->mGraphics->WINDOW_WIDTH/2 - title->mWidth/2,
                    title->mGraphics->WINDOW_HEIGHT/2 );
                    //
    levelText=new Texture("fonts/font.ttf","",32*3,{255,255,255});
    levelText->SetXY(levelText->mGraphics->WINDOW_WIDTH/2 - levelText->mWidth/2,
                    levelText->mGraphics->WINDOW_HEIGHT/4 );


}

VictoryScreen::~VictoryScreen()
{
    //dtor
    delete title;
    title=NULL;
    mInput=NULL;
}
//update
void VictoryScreen::Update(SCREENS &mCurrentScreen,int &scorevalue,PlayScreen &mPlayScreen,Health &health,int&level)
{
 mInput->Update();
         levelSText.str( "" );
         levelSText << "Level "<<level<<" complete!";
         levelText->SetText(levelSText.str().c_str(),{255, 255, 255});
         levelText->SetXY(levelText->mGraphics->WINDOW_WIDTH/2 - levelText->mWidth/2,
                    levelText->mGraphics->WINDOW_HEIGHT/4 );
 if(mInput->KeyPressed(SDL_SCANCODE_RETURN))
 {
   level++;
   mPlayScreen.clearScreen();
   scorevalue=0;
   health.health=3;
   mCurrentScreen=serve;
 }
  mPlayScreen.padlle->Update();
  mPlayScreen.ball->x=mPlayScreen.padlle->x + (mPlayScreen.padlle->width / 2) - mPlayScreen.ball->width/2;
  mPlayScreen.ball->y=mPlayScreen.padlle->y-mPlayScreen.ball->hight;
}
//
void VictoryScreen::Render(PlayScreen&mPlayScreen)
{
 title->Render();
 levelText->Render();
 mPlayScreen.padlle->Render();
 mPlayScreen.ball->Render();

}
