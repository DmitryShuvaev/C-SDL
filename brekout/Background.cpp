#include "Background.h"

Background::Background()
{
    //ctor
     background=new Texture("graphics/background.png");
     background->mRenderRect.w=background->mRenderRect.w*backgroundScalex;
     background->mRenderRect.h=background->mRenderRect.h*backgroundScaley;
}

Background::~Background()
{
    //dtor
    delete background;
    background=NULL;
}
void Background::Render()
{
    background->Render();

}
