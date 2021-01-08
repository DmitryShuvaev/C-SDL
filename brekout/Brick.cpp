#include "Brick.h"

Brick::Brick()
{
    //ctor
        mAudioMgr = AudioManager::Instance();
        brick=new Texture("graphics/breakout.png");

        gSpriteClip.x =  0;
		gSpriteClip.y =  0;
		gSpriteClip.w = 32;
		gSpriteClip.h = 16;
        width=gSpriteClip.w *Scalex;
        hight=gSpriteClip.h*Scaley;
        x=width;
        y=hight;
        inPlay = true;
        initLevel();
        //Initialize particles
    for( int i = 0; i < TOTAL_PARTICLES; ++i )
    {
        particles[ i ] = new Particle( x, y );
    }
}
void Brick::renderParticles()
{

    int i = 0;
    int counterp=0;
    for( i; i < TOTAL_PARTICLES; ++i )
    {
        if(particles[ i ]->isDead())
         counterp++;
    }
    if(counterp==TOTAL_PARTICLES)np=true;
    if(np){
     renderParticle=false;

     return;
    }
    else
    {
     	//Go through particles
    for( int i = 0; i < TOTAL_PARTICLES; ++i )
    {
        //Delete and replace dead particles
//        if( particles[ i ]->isDead() )
//        {
//            delete particles[ i ];
//            //particles[ i ] = new Particle( x, y );
//        }
        //else particles[ i ]->render();
        particles[ i ]->render();
    }
    }



    //Show particles
//    for( int i = 0; i < TOTAL_PARTICLES; ++i )
//    {
//        particles[ i ]->render();
//    }
}
Brick::~Brick()
{
    //dtor
    delete brick;
    brick=NULL;
    AudioManager::Release();
    mAudioMgr = NULL;
        //Delete particles
    for( int i = 0; i < TOTAL_PARTICLES; ++i )
    {
        delete particles[ i ];
    }
}
void Brick::Update()
{
 //renderParticles();
}
void Brick::Render()
{

    if(inPlay)
    brick->render( x, y, &gSpriteClip,width,hight );
//    renderParticleTime--;
//    if(renderParticle)
//    {
//     renderParticles();
//    }

}
//

void Brick::hit()
{
    mAudioMgr->PlaySFX("sounds/brick-hit-2.wav",0,1);
    for( int i = 0; i < TOTAL_PARTICLES; ++i )
    {
        particles[ i ]->mPosX=(x+( rand() % 50 ))+width/4;
        particles[ i ]->mPosY=(y+( rand() % 50 ))+hight/2;

        particles[ i ]->mFrame = rand() % 5;
        particles[ i ]->mTexture->SetXY(particles[ i ]->mPosX,particles[ i ]->mPosY);
        particles[ i ]->gShimmerTexture->SetXY(particles[ i ]->mPosX,particles[ i ]->mPosY);
        particles[ i ]->mTexture->setAlpha(255);
        particles[ i ]->gShimmerTexture->setAlpha(255);
        particles[ i ]->renderParticleTime=255;
    }
renderParticle=true;
np=false;
 if(color==0)
 {
  mAudioMgr->PlaySFX("sounds/brick-hit-1.wav",0,1);
  inPlay = false;
 }else
 {
        color--;

        gSpriteClip.x = gSpriteClips[color].x;
		gSpriteClip.y =  gSpriteClips[color].y;
		gSpriteClip.w = gSpriteClips[color].w;
		gSpriteClip.h = gSpriteClips[color].h;
		//brick->render( x, y, &gSpriteClip,width,hight );

 }
}
//
Brick::Brick(const int x,const int y,const int w,const int h)
{
         mAudioMgr = AudioManager::Instance();
        brick=new Texture("graphics/breakout.png");

        gSpriteClip.x =  x;
		gSpriteClip.y =  y;
		gSpriteClip.w = w;
		gSpriteClip.h = h;
        width=gSpriteClip.w *Scalex;
        hight=gSpriteClip.h*Scaley;
        this->x=width;
        this->y=hight;
        inPlay = true;
        initLevel();
                //Initialize particles
    for( int i = 0; i < TOTAL_PARTICLES; ++i )
    {
        particles[ i ] = new Particle( x, y );

    }
}
//
void Brick::initLevel()
{
    for(int i=0;i<6;i++)
    {
        if(i==0)
        {
        gSpriteClips[i].x =  0;
		gSpriteClips[i].y =  0;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==1)
        {
        gSpriteClips[i].x =  128;
		gSpriteClips[i].y =  0;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==2)
        {
        gSpriteClips[i].x =  64;
		gSpriteClips[i].y =  16;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==3)
        {
        gSpriteClips[i].x =  0;
		gSpriteClips[i].y =  32;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==4)
        {
        gSpriteClips[i].x =  128;
		gSpriteClips[i].y =  32;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==5)
        {
        gSpriteClips[i].x =  64;
		gSpriteClips[i].y =  48;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }

    }

}
