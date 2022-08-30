#include "ScreenManager.h"
ScreenManager*ScreenManager::sInstance=NULL;
ScreenManager*ScreenManager::Instance()
{
  if(sInstance==NULL)
  {
      sInstance=new ScreenManager();
  }
  return sInstance;
}
void ScreenManager::Release()
{
    delete sInstance;
    sInstance = NULL;
}//
void ScreenManager::Update()
{

 switch(mCurrentScreen)
 {
 case start:
    mStartScreen->Update(mCurrentScreen,mPlayScreen);
    break;
 case GameOver:
    mGameOverState->Update(mCurrentScreen,mPlayScreen);
    break;
 case walking:
     for(int i=0;i<10;i++)
     {


     if(mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState==ENTITYSTATE::EntityWalk)
     {
         mEnemyEntityWalkState->Update(*mPlayScreen->dungeon->currentRoom->entities[i],
                                       mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState,
                                       *mPlayScreen->player,*mPlayScreen->mAnimation,*mPlayScreen);
         //cout<<"entity"<<endl;
     }
     else if(mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState==ENTITYSTATE::EntityIdle)
     {
       mEnemyEntityIdleState->Update(*mPlayScreen->dungeon->currentRoom->entities[i], mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState,
                                     *mPlayScreen);
     }
     }
     mPlayScreen->Update(mCurrentScreen);
     mPlayerWalkingState->Update(mCurrentScreen,*mPlayScreen);
    break;
 case dungeonScreen:
    mPlayScreen->dungeon->Update(mCurrentScreen,*mPlayScreen->player,*mPlayScreen->mAnimation);
    break;
 case idle:
     for(int i=0;i<10;i++)
     {
     if(mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState==ENTITYSTATE::EntityWalk)
     {
         mEnemyEntityWalkState->Update(*mPlayScreen->dungeon->currentRoom->entities[i],mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState,
                                       *mPlayScreen->player,*mPlayScreen->mAnimation,*mPlayScreen);

     }
     else if(mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState==ENTITYSTATE::EntityIdle)
     {
       mEnemyEntityIdleState->Update(*mPlayScreen->dungeon->currentRoom->entities[i],mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState,
                                     *mPlayScreen);
     }
     }

     mPlayerIdleState->Update(mCurrentScreen,*mPlayScreen,*mPlayerSwingSwordState);
     mPlayScreen->Update(mCurrentScreen);
    break;
 case SwingSwordState:
     for(int i=0;i<10;i++)
     {
     if(mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState==ENTITYSTATE::EntityWalk)
     {
         mEnemyEntityWalkState->Update(*mPlayScreen->dungeon->currentRoom->entities[i],mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState,
                                       *mPlayScreen->player,*mPlayScreen->mAnimation,*mPlayScreen);

     }
     else if(mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState==ENTITYSTATE::EntityIdle)
     {
       mEnemyEntityIdleState->Update(*mPlayScreen->dungeon->currentRoom->entities[i],mPlayScreen->dungeon->currentRoom->entities[i]->mEntityState,
                                     *mPlayScreen);
     }
     }

 mPlayerSwingSwordState->Update(mCurrentScreen,*mPlayScreen->player,*mPlayScreen->mAnimation,mPlayScreen);
 mPlayScreen->Update(mCurrentScreen);
    break;

 }
}//

void ScreenManager::Render()
{

 switch(mCurrentScreen)
 {
 case start:

    mStartScreen->Render();
    break;
 case GameOver:
    mGameOverState->Render();
    break;
 case play:
    //mPlayScreen->Render();

    break;
 case walking:
    mPlayScreen->Render();

    break;
 case idle:
    mPlayScreen->Render();
    break;
 case dungeonScreen:
    mPlayScreen->Render();
    break;
 case SwingSwordState:
   mPlayScreen->Render();
   /*
   mPlayScreen->player->player->mGraphics->draw_rect(mPlayScreen->player->lefthitbox);
   mPlayScreen->player->player->mGraphics->draw_rect(mPlayScreen->player->righthitbox);
   mPlayScreen->player->player->mGraphics->draw_rect(mPlayScreen->player->uphitbox);
   mPlayScreen->player->player->mGraphics->draw_rect(mPlayScreen->player->downhitbox);
   */
    break;


 }
}
ScreenManager::ScreenManager()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
    mStartScreen=new StartScreen();
    mPlayScreen=new PlayScreen();
    mPlayerWalkingState=new PlayerWalkingState();
    mPlayerIdleState=new PlayerIdleState();
    mPlayerSwingSwordState=new PlayerSwingSwordState();
    //entity states
    mEnemyEntityWalkState=new EntityWalkState();
    mEnemyEntityIdleState=new EntityIdleState();
    mGameOverState=new GameOverState();
    mCurrentScreen=start;

 //mAudioMgr->PlaySFX("marios_way.mp3",-1);
}

ScreenManager::~ScreenManager()
{
    //dtor
    mInput=NULL;
    delete mStartScreen;
    mStartScreen=NULL;
    delete mPlayScreen;
    mPlayScreen=NULL;
    delete mGameOverState;

}
