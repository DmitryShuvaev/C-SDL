#include "Ball.h"

Ball::Ball()
{
    //ctor
    mAudioMgr = AudioManager::Instance();
        ball=new Texture("graphics/breakout.png");

        gSpriteClips.x =  96;
		gSpriteClips.y =  48;
		gSpriteClips.w = 8;
		gSpriteClips.h = 8;
        x=WINDOW_WIDTH/2-4*Scalex;
        y=WINDOW_HEIGHT-41*Scaley;
        width=gSpriteClips.w *Scalex;
        hight=gSpriteClips.h*Scaley;
        //collides( 1);
}

Ball::~Ball()
{
    //dtor
    AudioManager::Release();
    mAudioMgr = NULL;
    delete ball;
    ball=NULL;
}
//

//
void Ball::Update()
{
dx=BALL_SPEED;
x=x+dx;
y=y+dy;
//allow ball to bounce off walls
if(x<=0)
{
mAudioMgr->PlaySFX("sounds/wall_hit.wav",0,1);
 BALL_SPEED=-BALL_SPEED;
 if(x<0)x=1;
    //dx=-BALL_SPEED;
}
if(x+width>=WINDOW_WIDTH)
{
    mAudioMgr->PlaySFX("sounds/wall_hit.wav",0,1);
    BALL_SPEED=-BALL_SPEED;
    //dx=-BALL_SPEED;
}
if(y<=0)
{
    mAudioMgr->PlaySFX("sounds/wall_hit.wav",0,1);
    dy=-dy;
}
if(y+hight>=WINDOW_HEIGHT)
{

}
}
void Ball::Render()
{
 ball->render( x, y, &gSpriteClips,width,hight );
//padle->render( x, y-100, &gSpriteClips2,Scalex,Scaley );
}
