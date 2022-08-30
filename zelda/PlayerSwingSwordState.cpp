#include "PlayerSwingSwordState.h"

PlayerSwingSwordState::PlayerSwingSwordState()
{
    //ctor
    mTimer = Timer::Instance();
    mAnimationTimer=0.12f;
//    mgemTimeanim=Timer::Instance();
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
}
void PlayerSwingSwordState::init_hitbox(Player & player,Animation&mAnimation)
{
 /*
 switch(mAnimation.curentanim)
 {
 case left:
    player.hitbox.x=player.x-player.hitboxWidth;
    player.hitbox.y=player.y+10;
    break;
 }
 */
}
PlayerSwingSwordState::~PlayerSwingSwordState()
{
    //dtor
}
void PlayerSwingSwordState::Reset()
{
      count=0;
      mAnimationTimer=0.f;
      anim_start=false;
      active=false;
}

void PlayerSwingSwordState::SwordLeftAnim(Player & mcharacter,Animation&mAnimation)
{
 mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/time_dev>=1)
{
    if(count==4)
    {
     mcharacter.gSpriteClip.x =  101;
     mcharacter.gSpriteClip.y =  230;

        Reset();
    }
    else if (count==3)
    {
      mcharacter.gSpriteClip.x =  68;
      mcharacter.gSpriteClip.y =  230;
    }
    else if (count==2)
    {
      mcharacter.gSpriteClip.x =  33;
      mcharacter.gSpriteClip.y =  230;
    }
    else if (count==1)
    {
      mcharacter.gSpriteClip.x =  9;
      mcharacter.gSpriteClip.y =  230;

    }

     count++;
     mAnimationTimer=0.0f;
}
}
void PlayerSwingSwordState::SwordRightAnim(Player & mcharacter)
{
 mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/time_dev>=1)
{
    if(count==4)
    {
     mcharacter.gSpriteClip.x =  105;
     mcharacter.gSpriteClip.y =  198;

        Reset();
    }
    else if (count==3)
    {
      mcharacter.gSpriteClip.x =  73;
      mcharacter.gSpriteClip.y =  198;
    }
    else if (count==2)
    {
      mcharacter.gSpriteClip.x =  41;
      mcharacter.gSpriteClip.y =  198;
    }
    else if (count==1)
    {
      mcharacter.gSpriteClip.x =  9;
      mcharacter.gSpriteClip.y =  198;
    }
     count++;
     mAnimationTimer=0.0f;
}
}
void PlayerSwingSwordState::SwordTopAnim(Player & mcharacter)
{
 mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/time_dev>=1)
{
    if(count==4)
    {
     mcharacter.gSpriteClip.x =  104;
     mcharacter.gSpriteClip.y =  166;

        Reset();
    }
    else if (count==3)
    {
      mcharacter.gSpriteClip.x =  72;
      mcharacter.gSpriteClip.y =  166;
    }
    else if (count==2)
    {
      mcharacter.gSpriteClip.x =  40;
      mcharacter.gSpriteClip.y =  166;
    }
    else if (count==1)
    {
      mcharacter.gSpriteClip.x =  8;
      mcharacter.gSpriteClip.y =  166;
    }
     count++;
     mAnimationTimer=0.0f;
}
}
void PlayerSwingSwordState::SwordDownAnim(Player & mcharacter)
{
 mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/time_dev>=1)
{
    if(count==4)
    {
     mcharacter.gSpriteClip.x =  104;
     mcharacter.gSpriteClip.y =  134;

        Reset();
    }
    else if (count==3)
    {
      mcharacter.gSpriteClip.x =  72;
      mcharacter.gSpriteClip.y =  134;
    }
    else if (count==2)
    {
      mcharacter.gSpriteClip.x =  40;
      mcharacter.gSpriteClip.y =  134;
    }
    else if (count==1)
    {
      mcharacter.gSpriteClip.x =  8;
      mcharacter.gSpriteClip.y =  134;
    }
     count++;
     mAnimationTimer=0.0f;
}
}
void PlayerSwingSwordState::Update(SCREENS &mCurrentScreen,Player & p,Animation&mAnimation,PlayScreen *ps)
{
     mInput->Update();

     switch(mAnimation.curentanim)
     {
     case left:
     if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
     {
      mAudioMgr->PlaySFX("sounds/sword.wav",0,1);
      mAnimationTimer=1;
      anim_start=true;
      count=1;
      //time_dev=0.05f;
      //ps->Render();
      SwordLeftAnim(p,mAnimation);
     }
     if(anim_start)
     {

      SwordLeftAnim(p,mAnimation);
      for(int i=0;i<10;i++)
      ps->dungeon->currentRoom->entities[i]->Update(&p.lefthitbox);
      //ps->dungeon->currentRoom->entities->Coliders(&p);

     }
     else
     {
      Go_toIdle(mCurrentScreen,mAnimation,p);
     }
     break;
     case right:
     if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
     {
      mAudioMgr->PlaySFX("sounds/sword.wav",0,1);
      mAnimationTimer=1;
      anim_start=true;
      count=1;
      SwordRightAnim(p);
     }
     if(anim_start)
     {
      SwordRightAnim(p);
      for(int i=0;i<10;i++)
      ps->dungeon->currentRoom->entities[i]->Update(&p.righthitbox);
     }
     else
     {
      anim_start=true;
      mAnimation.setIdle(p);
      mCurrentScreen=idle;
     }
     break;
     case up:
     if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
     {
      mAudioMgr->PlaySFX("sounds/sword.wav",0,1);
      mAnimationTimer=1;
      anim_start=true;
      count=1;
      SwordTopAnim(p);
     }
     if(anim_start)
     {
      SwordTopAnim(p);
      for(int i=0;i<10;i++)
      ps->dungeon->currentRoom->entities[i]->Update(&p.uphitbox);
     }
     else
     {
      anim_start=true;
      mAnimation.setIdle(p);
      mCurrentScreen=idle;
     }
     break;
     case down:
     if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
     {
      mAudioMgr->PlaySFX("sounds/sword.wav",0,1);
      mAnimationTimer=1;
      anim_start=true;
      count=1;
      SwordDownAnim(p);
     }
     if(anim_start)
     {
      SwordDownAnim(p);
      for(int i=0;i<10;i++)
      ps->dungeon->currentRoom->entities[i]->Update(&p.downhitbox);
     }
     else
     {
      anim_start=true;
      mAnimation.setIdle(p);
      mCurrentScreen=idle;
     }
     break;
     }


 }
 void PlayerSwingSwordState::Render()
 {

 }
void PlayerSwingSwordState::Go_toIdle(SCREENS &mCurrentScreen,Animation&mAnimation,Player & p)
{
       time_dev=0.08f;
      anim_start=true;
      mAnimation.setIdle(p);
      mCurrentScreen=idle;
}
