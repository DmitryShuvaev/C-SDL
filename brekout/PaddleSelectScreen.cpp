#include "PaddleSelectScreen.h"

PaddleSelectScreen::PaddleSelectScreen()
{
    //ctor
        mInput=InputManager::Instance();
        title=new Texture("fonts/font.ttf","Select your paddle with left and right!",16*3,{255,255,255});
        title->SetXY(WINDOW_WIDTH/2- title->mWidth/2,WINDOW_HEIGHT/4);
        undertitle=new Texture("fonts/font.ttf","(Press Enter to continue!)",8*3,{255,255,255});
        undertitle->SetXY(WINDOW_WIDTH/2- undertitle->mWidth/2,WINDOW_HEIGHT/3);
//
leftArrow=new Texture("graphics/arrows.png");
        gSpriteClips.x =  0;
		gSpriteClips.y =  0;
		gSpriteClips.w = 24;
		gSpriteClips.h = 24;
        width=gSpriteClips.w *3;
        hight=gSpriteClips.h*3;
        x=WINDOW_WIDTH/4-width;
        y=WINDOW_HEIGHT-WINDOW_HEIGHT/3;
        //
rightArrow=new Texture("graphics/arrows.png");
        gSpriteClips2.x =  24;
		gSpriteClips2.y =  0;
		gSpriteClips2.w = 24;
		gSpriteClips2.h = 24;
        x2=WINDOW_WIDTH-WINDOW_WIDTH/4;
        y2=WINDOW_HEIGHT-WINDOW_HEIGHT/3;
//
//padleTexture=new Texture("graphics/breakout.png");
       for(int i=0;i<4;i++)
       {
        gSpriteClipsPadles[i].x = 32;
		gSpriteClipsPadles[i].y = 64+(i*32);
		gSpriteClipsPadles[i].w = 64;
		gSpriteClipsPadles[i].h = 16;
       }
		paddleW=gSpriteClipsPadles[0].w*3;
		paddleH=gSpriteClipsPadles[0].h*3;
    // the paddle we're highlighting; will be passed to the ServeState
    // when we press Enter
        currentPaddle = 0;
}

PaddleSelectScreen::~PaddleSelectScreen()
{
    //dtor
    delete title;
    title=NULL;
    delete undertitle;
    undertitle=NULL;
    delete leftArrow;
    leftArrow=NULL;
    delete rightArrow;
    rightArrow=NULL;
    //delete padleTexture;
    //padleTexture=NULL;
}
void PaddleSelectScreen::Update(SCREENS &mCurrentScreen,PlayScreen &mPlayScreen)
{
    mInput->Update();
    if(mInput->KeyPressed(SDL_SCANCODE_LEFT))
    {
    if(currentPaddle==0)
    {

    }
    else
     currentPaddle--;
    }
    else if(mInput->KeyPressed(SDL_SCANCODE_RIGHT))
    {
    if(currentPaddle==3)
    {

    }
    else
     currentPaddle ++;
    }
    mPlayScreen.padlle->gSpriteClips=gSpriteClipsPadles[currentPaddle];
    mPlayScreen.padlle->x=WINDOW_WIDTH/2- paddleW/2;
    mPlayScreen.padlle->y=y;
    if(mInput->KeyPressed(SDL_SCANCODE_RETURN))
    {
        mCurrentScreen=serve;
        mPlayScreen.padlle->x=WINDOW_WIDTH/2-32*mPlayScreen.padlle->Scalex;
        mPlayScreen.padlle->y=WINDOW_HEIGHT-32*mPlayScreen.padlle->Scalex;
    }
}
void PaddleSelectScreen::Render(PlayScreen &mPlayScree)
{
 leftArrow->render( x, y, &gSpriteClips,width,hight );
 rightArrow->render( x2, y2, &gSpriteClips2,width,hight );
 title->Render();
 undertitle->Render();
 mPlayScree.padlle->Render();
 //padleTexture->render(WINDOW_WIDTH/2- paddleW/2, y, &gSpriteClipsPadles[currentPaddle],paddleW,paddleH);
}
