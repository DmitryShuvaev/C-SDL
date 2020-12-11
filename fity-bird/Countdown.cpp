#include "Countdown.h"

Countdown::Countdown()
{
    //ctor
    mTimer = Timer::Instance();
    mCountText=new Texture("flappy.ttf"," ",56*ic,color[0]);
    mCountText->SetXY(mCountText->mGraphics->SCREEN_WIDTH/2 - mCountText->mWidth/2,
                120*ic);
//   mCountText->mRenderRect.w=mCountText->mRenderRect.w*ic;
//  mCountText->mRenderRect.h=mCountText->mRenderRect.h*ic;
}

Countdown::~Countdown()
{
    //dtor
}
void Countdown::Reset()
{
      count=3;
     mAnimationTimer=1.f;

}
void Countdown::Update(SCREENS &mCurrentScreen,bool &scrolling)
{
mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/1.0f>=1)
{
    if(count==0)
    {
        mCurrentScreen=play;
        scrolling=true;
        Reset();
    }
    std::string str=std::to_string(count);
    mCountText->SetText(strdup(str.c_str()));
     cout<<count<<endl;
     count--;
     mAnimationTimer=0.0f;
}



}//
void Countdown::Render()
{
 mCountText->Render()  ;
}
