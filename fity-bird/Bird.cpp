#include "Bird.h"

Bird::Bird()
{
    //ctor
    mInput=InputManager::Instance();
    		//Initialize AudioManager
		mAudioMgr = AudioManager::Instance();
    bird=new Texture("bird.png");
bird->mRenderRect.w=bird->mRenderRect.w*ic;
bird->mRenderRect.h=bird->mRenderRect.h*ic;
bird->SetXY(bird->mGraphics->SCREEN_WIDTH/2-(bird->mHeight/2),bird->mGraphics->SCREEN_HEIGHT/2-(bird->mWidth/2));
//    sound=new SDL2SoundEffets();
//    sound->addSoundEffect("jump.wav");

}

Bird::~Bird()
{
    //dtor
    delete bird;
    bird=NULL;
//    delete sound;
//    sound=NULL;
		AudioManager::Release();
		mAudioMgr = NULL;
}
bool Bird::collides(const Tube &pipe)
{
  if(bird->mRenderRect.x+bird->mRenderRect.w>=pipe.upper->mRenderRect.x
     && bird->mRenderRect.x<= pipe.upper->mRenderRect.x + pipe.upper->mRenderRect.w
     &&bird->mRenderRect.y+bird->mRenderRect.h>=pipe.upper->mRenderRect.y
     &&bird->mRenderRect.y<=pipe.upper->mRenderRect.y+pipe.upper->mRenderRect.h)
  return true;
  if(bird->mRenderRect.x+bird->mRenderRect.w>=pipe.lower->mRenderRect.x
     && bird->mRenderRect.x<= pipe.lower->mRenderRect.x + pipe.lower->mRenderRect.w
     &&bird->mRenderRect.y+bird->mRenderRect.h>=pipe.lower->mRenderRect.y
     &&bird->mRenderRect.y<=pipe.lower->mRenderRect.y+pipe.lower->mRenderRect.h)
  return true;
  return false;
}
void Bird::Update()
{
    mInput->Update();
 if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
 {
 mAudioMgr->PlaySFX("jump.wav",0,1);
  dy=-4;
  //sound->playSoundEffect(0);
 }
dy=dy+GRAVITY;
bird->mRenderRect.y=bird->mRenderRect.y+dy;
}
void Bird::Render()
{
 bird->Render();
}
