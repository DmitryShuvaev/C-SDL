#include "StartScreen.h"

StartScreen::StartScreen()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
    title=new Texture("fonts/ArcadeAlternate.ttf","Super 50 Bros.",FONT_SIZE,{255,255,255});
    title->SetXY((title->mGraphics->WINDOW_WIDTH/2 - title->mWidth/2)-5,
                    title->mGraphics->WINDOW_HEIGHT/2 -41*5);
    titlelow=new Texture("fonts/ArcadeAlternate.ttf","Super 50 Bros.",FONT_SIZE,{0,0,0});
    titlelow->SetXY(titlelow->mGraphics->WINDOW_WIDTH/2 - titlelow->mWidth/2,
                    titlelow->mGraphics->WINDOW_HEIGHT/2 -40*5);
    pressEntertext=new Texture("fonts/ArcadeAlternate.ttf","Press Enter",FONT_SIZE/2,{255,255,255});
    pressEntertext->SetXY((pressEntertext->mGraphics->WINDOW_WIDTH/2 - pressEntertext->mWidth/2)-5,
                    pressEntertext->mGraphics->WINDOW_HEIGHT/2 +16*5);
    pressEntertextlow=new Texture("fonts/ArcadeAlternate.ttf","Press Enter",FONT_SIZE/2,{0,0,0});
    pressEntertextlow->SetXY(pressEntertextlow->mGraphics->WINDOW_WIDTH/2 - pressEntertextlow->mWidth/2,
                    pressEntertextlow->mGraphics->WINDOW_HEIGHT/2 +17*5);
    int randy[] = {0,128,256};
    background=new Texture("graphics/backgrounds.png");
        backgroundSpriteClip.x =  0;
		backgroundSpriteClip.y = randy[rand()%3];
		backgroundSpriteClip.w = background->mRenderRect.w;
		backgroundSpriteClip.h = 128;
        backgroundwidth=backgroundSpriteClip.w *5;
        backgroundhight=backgroundSpriteClip.h *7;
}


void StartScreen::Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen)
{

    mInput->Update();
    if(mInput->KeyPressed(SDL_SCANCODE_RETURN))
    {
      //mAudioMgr->PlaySFX("sounds/confirm.wav",0,1);
      mPlayScreen.clearScreen();
      mPlayScreen.init();
      mCurrentScreen=falling;
    }
    else if(mInput->KeyPressed(SDL_SCANCODE_KP_ENTER))
    {
        //mAudioMgr->PlaySFX("sounds/confirm.wav",0,1);
     //mCurrentScreen=falling;
    }


}//end update
void StartScreen::Render(PlayScreen&mPlayScreen)
{
background->render( 0, 0, &backgroundSpriteClip,backgroundwidth,backgroundhight );
mPlayScreen.lmaker->mTileMap->Render();
 titlelow->Render();
 title->Render();
 pressEntertextlow->Render();
 pressEntertext->Render();
}
StartScreen::~StartScreen()
{
    //dtor

    mInput=NULL;
    AudioManager::Release();
    mAudioMgr = NULL;
    delete title;
    title=NULL;
}
