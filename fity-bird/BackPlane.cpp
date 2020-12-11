#include "BackPlane.h"

BackPlane::BackPlane()
{
    //ctor
    background=new Texture("background.png");
    ground=new Texture("ground.png");

  ground->mRenderRect.w=ground->mRenderRect.w*ic;
  ground->mRenderRect.h=ground->mRenderRect.h*ic;
  background->mRenderRect.w=background->mRenderRect.w*ic;
  background->mRenderRect.h=background->mRenderRect.h*ic;

ground->mRenderRect.y=ground->mGraphics->SCREEN_HEIGHT-ground->mRenderRect.h;
}
void BackPlane::Update(SCREENS &mCurrentScreen)
{
    backgroundScroll-=BACKGROUND_SCROLL_SPEED;

    if(background->mRenderRect.x<=BACKGROUND_LOOPING_POINT)
    {
     backgroundScroll=0;
    }
    background->mRenderRect.x= backgroundScroll ;
    //scroll ground
    groundScroll-=GROUND_SCROLL_SPEED;

    if(ground->mRenderRect.x<=-ground->mWidth)
    {
     groundScroll=0;
    }
    ground->mRenderRect.x= groundScroll ;
}
void BackPlane::Render()
{
    background->Render();
    ground->Render();
}
BackPlane::~BackPlane()
{
    //dtor
    delete background;
    background=NULL;
    delete ground;
    ground=NULL;
}
