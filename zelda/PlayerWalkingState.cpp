#include "PlayerWalkingState.h"

PlayerWalkingState::PlayerWalkingState()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
}

PlayerWalkingState::~PlayerWalkingState()
{
    //dtor
}
void PlayerWalkingState::Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen)
{
    mInput->Update();
//    if(mCurrentScreen==SCREENS::GameOver)
//    {mCurrentScreen=walking;
//    cout<<"gameover"<<endl;
//
//    }
   //collision with switch
   mPlayScreen.dungeon->currentRoom->switch_onCollide(mPlayScreen.player);
      //
      if(mInput->KeyDown(SDL_SCANCODE_LEFT))
      {

          mPlayScreen.mAnimation->curentanim=mPlayScreen.mAnimation->STATES::left;
          collision_detection_left(mCurrentScreen,*mPlayScreen.dungeon->currentRoom,mPlayScreen);
       if(mInput->KeyDown(SDL_SCANCODE_SPACE))
      {

       mCurrentScreen=SwingSwordState;
       mAudioMgr->PlaySFX("sounds/sword.wav",0,1);
      }
      }
      else if(mInput->KeyDown(SDL_SCANCODE_RIGHT))
      {

          mPlayScreen.mAnimation->curentanim=mPlayScreen.mAnimation->STATES::right;
          collision_detection_right(mCurrentScreen,*mPlayScreen.dungeon->currentRoom,mPlayScreen);

      if(mInput->KeyDown(SDL_SCANCODE_SPACE))
      {
       mCurrentScreen=SwingSwordState;
      }
      }
        else if(mInput->KeyDown(SDL_SCANCODE_UP))
      {
          mPlayScreen.mAnimation->curentanim=mPlayScreen.mAnimation->STATES::up;
          collision_detection_up(mCurrentScreen,*mPlayScreen.dungeon->currentRoom,mPlayScreen);
      if(mInput->KeyDown(SDL_SCANCODE_SPACE))
      {
       mCurrentScreen=SwingSwordState;
      }

      }
        else if(mInput->KeyDown(SDL_SCANCODE_DOWN))
      {

          mPlayScreen.mAnimation->curentanim=mPlayScreen.mAnimation->STATES::down;
         collision_detection_low(mCurrentScreen,*mPlayScreen.dungeon->currentRoom,mPlayScreen);
      if(mInput->KeyDown(SDL_SCANCODE_SPACE))
      {
       mCurrentScreen=SwingSwordState;
      }
      }//

       else
      {
        mPlayScreen.mAnimation->setIdle(*mPlayScreen.player);
        mPlayScreen.mAnimation->count=1;

        mPlayScreen.mAnimation->mAnimationTimer=0.12f;
        mCurrentScreen=idle;
      }






//
}
//check collision when move up
void PlayerWalkingState::collision_detection_up(SCREENS &mCurrentScreen,Room&room,PlayScreen&mPlayScreen)
{
 //if player moves up check colision with top wall and top door
 //if(mPlayScreen.mAnimation->curentanim==mPlayScreen.mAnimation->STATES::up)
 //{
       //collision player door
    if(AABB(mPlayScreen.dungeon->currentRoom->door->colider,mPlayScreen.player->rect))
     {
         if(mPlayScreen.dungeon->currentRoom->door->open)
         {
         if(mPlayScreen.dungeon->currentRoom->door->colider.x+
            mPlayScreen.dungeon->currentRoom->door->colider.w>=mPlayScreen.player->rect.x+
            mPlayScreen.player->rect.w&&
            mPlayScreen.dungeon->currentRoom->door->colider.x<=mPlayScreen.player->rect.x
            )
         {
          mPlayScreen.mAnimation->curentanim=mPlayScreen.mAnimation->STATES::up;
         if(!mPlayScreen.dungeon->active_shifting)
         {
         mPlayScreen.dungeon->active_shifting=true;
         mPlayScreen.dungeon->start_shifting=true;
         mCurrentScreen=dungeonScreen;
         mPlayScreen.dungeon->dir=DIRECTIONS::up;

         }
         }
         }
     }
     //collision  with top wall and player
     else if(!AABB(mPlayScreen.dungeon->currentRoom->colidertopWall,mPlayScreen.player->rect))
     {
        mPlayScreen.moveUp_Down(-3);

     }
     mPlayScreen.mAnimation->movinAnimation_Up(*mPlayScreen.player);
 //}
}
//check collision when move low
void PlayerWalkingState::collision_detection_low(SCREENS &mCurrentScreen,Room&room,PlayScreen&mPlayScreen)
{
     //collision low door
      if(AABB(mPlayScreen.dungeon->currentRoom->lowDoor->colider,mPlayScreen.player->rect))
     {
         if(mPlayScreen.dungeon->currentRoom->lowDoor->open)
         {
         if(mPlayScreen.dungeon->currentRoom->lowDoor->colider.x+
            mPlayScreen.dungeon->currentRoom->lowDoor->colider.w>=mPlayScreen.player->rect.x+
            mPlayScreen.player->rect.w&&
            mPlayScreen.dungeon->currentRoom->lowDoor->colider.x<=mPlayScreen.player->rect.x
            )
         {

          mPlayScreen.mAnimation->curentanim=mPlayScreen.mAnimation->STATES::down;
         if(!mPlayScreen.dungeon->active_shifting)
         {

         mPlayScreen.dungeon->active_shifting=true;
         mPlayScreen.dungeon->start_shifting=true;
         mCurrentScreen=dungeonScreen;
         mPlayScreen.dungeon->dir=DIRECTIONS::down;

         }
         }
        }
     }
    //collision  with top wall and player
     else if(!AABB(mPlayScreen.dungeon->currentRoom->coliderlowWall,mPlayScreen.player->rect))
     {
       mPlayScreen.moveUp_Down(3);
     }
     mPlayScreen.mAnimation->movinAnimation_Down(*mPlayScreen.player);
}
//check collision when move left
void PlayerWalkingState::collision_detection_left(SCREENS &mCurrentScreen,Room&room,PlayScreen&mPlayScreen)
{
      //collision left door
      if(AABB(mPlayScreen.dungeon->currentRoom->leftDoor->colider,mPlayScreen.player->rect))
     {
         if(mPlayScreen.dungeon->currentRoom->leftDoor->open)
         {

         if(mPlayScreen.dungeon->currentRoom->leftDoor->colider.y+
            mPlayScreen.dungeon->currentRoom->leftDoor->colider.h>=mPlayScreen.player->rect.y+
            mPlayScreen.player->rect.h&&
            mPlayScreen.dungeon->currentRoom->leftDoor->colider.y<=mPlayScreen.player->rect.y
            )
         {

          mPlayScreen.mAnimation->curentanim=mPlayScreen.mAnimation->STATES::left;
         if(!mPlayScreen.dungeon->active_shifting)
         {

         mPlayScreen.dungeon->active_shifting=true;
         mPlayScreen.dungeon->start_shifting=true;
         mCurrentScreen=dungeonScreen;
         mPlayScreen.dungeon->dir=DIRECTIONS::left;

         }
         }
         }
     }
     //collision  with left wall and player
     else if(!AABB(mPlayScreen.dungeon->currentRoom->coliderleftWall,mPlayScreen.player->rect))
     {
       mPlayScreen.moveLeft_Right(-3);
     }
     mPlayScreen.mAnimation->movinAnimation_Left(*mPlayScreen.player);
}
//check collision when move right
void PlayerWalkingState::collision_detection_right(SCREENS &mCurrentScreen,Room&room,PlayScreen&mPlayScreen)
{

        //collision right door
 if(AABB(mPlayScreen.dungeon->currentRoom->rightDoor->colider,mPlayScreen.player->rect))
 {
 if(mPlayScreen.dungeon->currentRoom->rightDoor->open)
 {
     if(mPlayScreen.dungeon->currentRoom->rightDoor->colider.y+
        mPlayScreen.dungeon->currentRoom->rightDoor->colider.h>=mPlayScreen.player->rect.y+
        mPlayScreen.player->rect.h&&
        mPlayScreen.dungeon->currentRoom->rightDoor->colider.y<=mPlayScreen.player->rect.y
        )
     {

      mPlayScreen.mAnimation->curentanim=mPlayScreen.mAnimation->STATES::right;
     if(!mPlayScreen.dungeon->active_shifting)
     {

     mPlayScreen.dungeon->active_shifting=true;
     mPlayScreen.dungeon->start_shifting=true;

     mCurrentScreen=dungeonScreen;
     mPlayScreen.dungeon->dir=DIRECTIONS::right;

     }
     }
 }
 }

//collision  with left wall and player
 else if(!AABB(mPlayScreen.dungeon->currentRoom->coliderrightWall,mPlayScreen.player->rect))
 {
  mPlayScreen.moveLeft_Right(3);
 }
 mPlayScreen.mAnimation->movinAnimation_Right(*mPlayScreen.player);
}
