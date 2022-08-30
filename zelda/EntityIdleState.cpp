#include "EntityIdleState.h"

EntityIdleState::EntityIdleState()
{
    //ctor
}

EntityIdleState::~EntityIdleState()
{
    //dtor
}
void EntityIdleState::Update(Entity&entity,ENTITYSTATE &currentState,PlayScreen&mPlayScreen)
{
 mPlayScreen.update_hearts(*mPlayScreen.player,entity);
 entity.durTimer++;
 if(entity.Duration==0)
 {
     entity.Duration = (rand() % 5)*50;

 }
 if(entity.durTimer>=entity.Duration)
 {
     entity.Duration=0;
     entity.durTimer=0;
     currentState=EntityWalk;
 }
}
