#include "EntityWalkState.h"

EntityWalkState::EntityWalkState()
{
    //ctor
}

EntityWalkState::~EntityWalkState()
{
    //dtor
}
//Entity *(&entity)[10]
void EntityWalkState::Update(Entity &entity,ENTITYSTATE &currentState,Player & p,Animation&mAnimation,PlayScreen&mPlayScreen)
{
 entity.durTimer++;



     processAI(entity,mPlayScreen);
     switch(entity.dir)
     {
      case left:

          entity.movinAnimation_Left();
          break;
      case right:
          entity.movinAnimation_Right();

          break;
      case up:
         entity.movinAnimation_Up();
          break;
      case down:
          entity.movinAnimation_Down();
          break;
     }

 if(entity.Duration==0)
 {
  set_duration(entity);
 }
 if(entity.durTimer>=entity.Duration)
 {
     entity.Duration=0;
     entity.durTimer=0;
     currentState=EntityIdle;
     entity.setIdle();
 }

}
void EntityWalkState::processAI(Entity &entity,PlayScreen&mPlayScreen)
{
   //if entity hit player
 mPlayScreen.update_hearts(*mPlayScreen.player,entity);
 if_bumped(entity,mPlayScreen);

}
void EntityWalkState::if_bumped(Entity &entity,PlayScreen&mPlayScreen)
{

 if(entity.dir==left)
 {
     entity.hurtbox.x-=2;
     if(entity_colide(entity,mPlayScreen.dungeon->currentRoom->entities)==false)
     {
      entity.hurtbox.x+=2;

     if(!AABB(mPlayScreen.dungeon->currentRoom->coliderleftWall,entity.hurtbox))
     {

                  entity.x-=1;
                  entity.hurtbox.x=entity.x;
                  entity.hurtbox.y=entity.y;
                  entity.bumped=false;


     }else
     {

          entity.Duration=0;
     }
     }else
     {
       entity.Duration=0;

       //entity.x+=2;
       entity.hurtbox.x=entity.x;
       entity.hurtbox.y=entity.y;

     }
 }
 else  if(entity.dir==right)
 {
     entity.hurtbox.x+=2;
     if(entity_colide(entity,mPlayScreen.dungeon->currentRoom->entities)==false)
     {
     entity.hurtbox.x-=2;
     if(!AABB(mPlayScreen.dungeon->currentRoom->coliderrightWall,entity.hurtbox))
     {
          entity.x+=1;
          entity.hurtbox.x=entity.x;
          entity.hurtbox.y=entity.y;
          entity.bumped=false;
     }else
     {

          entity.Duration=0;
     }
     }else
     {
       entity.Duration=0;

        //entity.x-=2;
        entity.hurtbox.x=entity.x;
        entity.hurtbox.y=entity.y;

     }
 }
  else  if(entity.dir==up)
 {
     entity.hurtbox.y-=2;
     if(entity_colide(entity,mPlayScreen.dungeon->currentRoom->entities)==false)
     {
     entity.hurtbox.y+=2;
     if(!AABB(mPlayScreen.dungeon->currentRoom->colidertopWall,entity.hurtbox))
     {
          entity.y-=1;
          entity.hurtbox.x=entity.x;
          entity.hurtbox.y=entity.y;
          entity.bumped=false;
     }else
     {

         entity.Duration=0;
     }
     }else
     {
       entity.Duration=0;

       //entity.y+=2;
       entity.hurtbox.x=entity.x;
       entity.hurtbox.y=entity.y;



     }
 }
   else  if(entity.dir==down)
 {
     entity.hurtbox.y+=2;
     if(entity_colide(entity,mPlayScreen.dungeon->currentRoom->entities)==false)
     {
     entity.hurtbox.y-=2;
     if(!AABB(mPlayScreen.dungeon->currentRoom->coliderlowWall,entity.hurtbox))
     {
          entity.y+=1;
          entity.hurtbox.x=entity.x;
          entity.hurtbox.y=entity.y;
          entity.bumped=false;
     }else
     {

       entity.Duration=0;
     }
     }
     else
     {
          entity.Duration=0;
          //entity.y-=2;
          entity.hurtbox.x=entity.x;
          entity.hurtbox.y=entity.y;


     }
 }
}
void EntityWalkState::set_duration(Entity &entity)
{
 //set an initial move duration and direction
     entity.Duration = (rand() % 5)*50;
     int i=rand() % 4;
     while(entity.currand_dir==i)i=rand() % 4;
     if(i==0)
     {entity.dir=left;

     }
     else if(i==1)
     {entity.dir=up;

     }
     else if(i==2)
     {entity.dir=down;

     }
     else if(i==3)
     {entity.dir=right;

     }
     entity.currand_dir=i;
     entity.bumped=false;
     entity.durTimer=0;
     //cout<<i<<endl;
}
bool EntityWalkState::entity_colide(Entity &entity,Entity *(&entitys)[10])
{
 for(int i=0;i<10;i++)
 {
     if(AABB(entity.hurtbox,entitys[i]->hurtbox)&&entity.id!=entitys[i]->id)
        {
         //cout<<true<<endl;
            return true;
        }
 }
 //cout<<false<<endl;
 return false;
}
bool EntityWalkState::entity_colide_rect(Entity &entity,Entity *(&entitys)[10])
{
 SDL_Rect temp=entity.hurtbox;
 temp.x-=2;
 temp.y-=2;
 temp.h+=4;
 temp.w+=4;
 for(int i=0;i<10;i++)
 {
     if(AABB(temp,entitys[i]->hurtbox)&&entity.id!=entitys[i]->id)
        {
         //cout<<true<<endl;
            return true;
        }
 }
 //cout<<false<<endl;
 return false;
}
bool EntityWalkState::player_entity_colide(Player * player,Entity *(&entitys)[10])
{
 for(int i=0;i<10;i++)
 {
     if(AABB(player->rect,entitys[i]->hurtbox))
        {
         if(entitys[i]->alive)
            return true;
        }
 }
 return false;
}
