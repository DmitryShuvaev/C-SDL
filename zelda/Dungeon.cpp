#include "Dungeon.h"

Dungeon::Dungeon()
{
    //ctor
    currentRoom=new Room();

}
void Dungeon::init()
{


}
void Dungeon::beginShifting(SCREENS &mCurrentScreen,Player & p,Animation*mAnimation)
{

 switch(dir)
 {
 case up:
      if(start_shifting)
     {
      nextRoom=new Room();
      nextRoom->set_pos(-WINDOW_HEIGHT+currentRoom->y_from_top);
      start_shifting=false;

     }
     nextRoom->set_pos(8);
     currentRoom->set_pos(8);
     if(nextRoom->topleftxypos.y>=nextRoom->y_from_top)
     {
         active_shifting=false;
         delete currentRoom;
         currentRoom=NULL;
         currentRoom=nextRoom;
         mCurrentScreen=idle;

     }
     shift_player(&p,8);
     move_player_up(mCurrentScreen,&p,mAnimation);
    break;
 case down:
     if(start_shifting)
     {
      nextRoom=new Room();
      nextRoom->set_pos(WINDOW_HEIGHT+currentRoom->y_from_top);
      start_shifting=false;
     }
     nextRoom->set_pos(-8);
     currentRoom->set_pos(-8);
     if(nextRoom->topleftxypos.y<=nextRoom->y_from_top)
     {
         active_shifting=false;
         delete currentRoom;
         currentRoom=NULL;
         currentRoom=nextRoom;
         mCurrentScreen=idle;
     }
    shift_player(&p,-8);
    move_player_down(mCurrentScreen,&p,mAnimation);
    break;
 case left:
     if(start_shifting)
     {
      nextRoom=new Room();
      nextRoom->set_pos_x(-WINDOW_WIDTH);
      start_shifting=false;
     }
     nextRoom->set_pos_x(8);
     currentRoom->set_pos_x(8);
     if(nextRoom->topleftxypos.x>=nextRoom->tilesize)
     {
         active_shifting=false;
         delete currentRoom;
         currentRoom=NULL;
         currentRoom=nextRoom;
         mCurrentScreen=idle;
     }
    shift_player_x(&p,8);
    move_player_left(mCurrentScreen,&p,mAnimation);
    break;
 case right:
      if(start_shifting)
     {
      nextRoom=new Room();
      nextRoom->set_pos_x(WINDOW_WIDTH);
      start_shifting=false;
     }
     nextRoom->set_pos_x(-8);
     currentRoom->set_pos_x(-8);
     if(nextRoom->topleftxypos.x<=nextRoom->tilesize)
     {
         active_shifting=false;
         delete currentRoom;
         currentRoom=NULL;
         currentRoom=nextRoom;
         mCurrentScreen=idle;
     }
    shift_player_x(&p,-8);
    move_player_right(mCurrentScreen,&p,mAnimation);
    break;
 }
}
void Dungeon::shift_player(Player * player,int dy)
{
 player->y+=dy;

}
void Dungeon::shift_player_x(Player * player,int dx)
{
 player->x+=dx;
}
void Dungeon::move_player_up(SCREENS &mCurrentScreen,Player * player,Animation*mAnimation)
{


          if(!AABB(nextRoom->colider,player->rect))
          {
            mAnimation->movinAnimation_Up(*player);
            player->y-=4;
            if(AABB(nextRoom->coliderLowWall,player->rect))
            {
                player->canRender=false;
                player->x=currentRoom->door->colider.x+
                (currentRoom->door->colider.w/2-player->width/2);
            }else player->canRender=true;
          }else
          {
              mAnimation->setIdle(*player);
              mAnimation->mAnimationTimer=0.12f;
              mAnimation->count=1;
          }

}
void Dungeon::move_player_down(SCREENS &mCurrentScreen,Player * player,Animation*mAnimation)
{


          if(!AABB(nextRoom->coliderUp,player->rect))
          {
            mAnimation->movinAnimation_Down(*player);
            player->y+=4;
            if(AABB(nextRoom->coliderUpWall,player->rect))
            {
                player->canRender=false;
                player->x=currentRoom->lowDoor->colider.x+
                (currentRoom->lowDoor->colider.w/2-player->width/2);
            }else player->canRender=true;
          }else
          {
              mAnimation->setIdle(*player);
              mAnimation->mAnimationTimer=0.12f;
              mAnimation->count=1;
          }

}
void Dungeon::move_player_left(SCREENS &mCurrentScreen,Player * player,Animation*mAnimation)
{


          if(!AABB(nextRoom->coliderLeft,player->rect))
          {
            mAnimation->movinAnimation_Left(*player);
            player->x-=4;
            if(AABB(currentRoom->coliderLeftWall,player->rect))
            {
                player->canRender=false;
                player->y=currentRoom->leftDoor->colider.y+
                (currentRoom->leftDoor->colider.h/2-player->hight/2);
            }else player->canRender=true;
          }else
          {
              mAnimation->setIdle(*player);
              mAnimation->mAnimationTimer=0.12f;
              mAnimation->count=1;
          }

}
void Dungeon::move_player_right(SCREENS &mCurrentScreen,Player * player,Animation*mAnimation)
{


          if(!AABB(nextRoom->coliderRight,player->rect))
          {

            mAnimation->movinAnimation_Right(*player);
            player->x+=4;
            if(AABB(currentRoom->coliderRightWall,player->rect))
            {
                player->canRender=false;
                player->y=currentRoom->rightDoor->colider.y+
                (currentRoom->rightDoor->colider.h/2-player->hight/2);
            }else player->canRender=true;
          }else
          {

              mAnimation->setIdle(*player);
              mAnimation->mAnimationTimer=0.12f;
              mAnimation->count=1;
          }

}
void Dungeon::shift_pos(SCREENS &mCurrentScreen,Player & p,Animation*mAnimation)
{
    if(active_shifting)
    {
       beginShifting(mCurrentScreen,p,mAnimation);
    }
}
void Dungeon::Update(SCREENS &mCurrentScreen,Player & p,Animation&mAnimation)
{
 shift_pos(mCurrentScreen,p,&mAnimation);
}
void Dungeon::Render()
{
  if(nextRoom!=NULL)
  {

      nextRoom->Render();

  }

 currentRoom->Render();

}
Dungeon::~Dungeon()
{
    //dtor
}
