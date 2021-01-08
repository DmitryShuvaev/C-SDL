#include "Particle.h"

Particle::Particle()
{
    //ctor
}
Particle::Particle( int x, int y )
{
    //Set offsets
   // mPosX = x - 5 + ( rand() % 50 );
   // mPosY = y - 5 + ( rand() % 50 );
    mPosX=x+( rand() % 50 );
    mPosY=y+( rand() % 50 );
    //Initialize animation
    mFrame = rand() % 5;

    //Set type
//    switch( rand() % 3 )
//    {
//        case 0: mTexture = &gRedTexture; break;
//        case 1: mTexture = &gGreenTexture; break;
//        case 2: mTexture = &gBlueTexture; break;
//    }
    mTexture=new Texture("graphics/green.bmp");
    mTexture->mRenderRect.w=mTexture->mRenderRect.w*1;
    mTexture->mRenderRect.h=mTexture->mRenderRect.h*1;
    mTexture->SetXY(mPosX,mPosY);
    gShimmerTexture=new Texture("graphics/shimmer.bmp");
    gShimmerTexture->mRenderRect.w=gShimmerTexture->mRenderRect.w*2;
    gShimmerTexture->mRenderRect.h=gShimmerTexture->mRenderRect.h*2;
    gShimmerTexture->SetXY(mPosX,mPosY);
    //mTexture->setAlpha(255);
}
void Particle::update()
{
     mTexture->mRenderRect.x=mPosX;
    mTexture->mRenderRect.y=mPosY;
    //Show image

	//mTexture->render( x, y, &gSpriteClip,width,hight );
    //mPosX+=1;
    mPosY+=1;


    //Animate
    mFrame++;
    renderParticleTime-=5;
    if(renderParticleTime>0)
    {
      mTexture->setAlpha(renderParticleTime);
      gShimmerTexture->setAlpha(renderParticleTime);
    }

}
void Particle::render()
{
        update();

//if(renderParticleTime>0)
{
  mTexture->Render( );
      //Show shimmer
    if( mFrame % 2 == 0 )
    {
		gShimmerTexture->Render();
    }
}
}

bool Particle::isDead()
{
    return mFrame > 100;
}
Particle::~Particle()
{
    //dtor
    delete mTexture;
    mTexture=NULL;
    delete gShimmerTexture;
    gShimmerTexture=NULL;
}
