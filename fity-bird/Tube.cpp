#include "Tube.h"

Tube::Tube()
{
    //ctor

lower=new Texture("pipe.png");
lower->mRenderRect.w=lower->mRenderRect.w*ic;
lower->mRenderRect.h=lower->mRenderRect.h*ic;
lower->mWidth=lower->mRenderRect.w;
lower->mHeight=lower->mRenderRect.h;
float randv=rand() % (lower->mGraphics->SCREEN_HEIGHT - 200 - 350 ) + 400;
//cout<<randv<<endl;
lower->SetXY(lower->mGraphics->SCREEN_WIDTH,randv);
dx=lower->mGraphics->SCREEN_WIDTH;
//upper pipe
upper=new Texture("pipe.png");
upper->mRenderRect.w=upper->mRenderRect.w*ic;
upper->mRenderRect.h=upper->mRenderRect.h*ic;
upper->mWidth=upper->mRenderRect.w;
upper->mHeight=upper->mRenderRect.h;
upper->SetXY(upper->mGraphics->SCREEN_WIDTH,randv-upper->mHeight-GAP_HEIGHT);
x=upper->mRenderRect.x;
PIPE_WIDTH=upper->mRenderRect.w;
}

Tube::~Tube()
{
    //dtor
    delete lower;
    lower=NULL;
    delete upper;
    upper=NULL;
}
void Tube::Update()
{
    dx=dx+PIPE_SCROLL;
    x=dx;
    lower->mRenderRect.x=dx;
    upper->mRenderRect.x=dx;
}
void Tube::Render()
{
lower->Render();
upper->RenderFlipped();
}
