#include "PlayerFallingState.h"

PlayerFallingState::PlayerFallingState()
{
    //ctor
    mInput=InputManager::Instance();
}

PlayerFallingState::~PlayerFallingState()
{
    //dtor
}
void PlayerFallingState::Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen)
{
    mInput->Update();

     mPlayScreen.characterDY = mPlayScreen.characterDY + mPlayScreen.GRAVITY;
     mPlayScreen.character->y=mPlayScreen.character->y+mPlayScreen.characterDY*0.2;
     int tempX=(mPlayScreen.character->x+3)-mPlayScreen.dx;
     int tempY=mPlayScreen.character->y+(mPlayScreen.character->hight);
     int tempXX=((mPlayScreen.character->x-3)+mPlayScreen.character->width)-mPlayScreen.dx;
    if(mPlayScreen.lmaker->mTileMap->b!=NULL)
    {

        for(int i=0;i<mPlayScreen.lmaker->mTileMap->sizearr;i++)
        {

         if(mPlayScreen.lmaker->mTileMap->b[i].g->gemColide(mPlayScreen.character->x,mPlayScreen.character->y
                                                            ,mPlayScreen.character->width,mPlayScreen.character->hight))

           {
               if(mPlayScreen.lmaker->mTileMap->b[i].g->gem)
               {
                 delete mPlayScreen.lmaker->mTileMap->b[i].g->gem;
                 mPlayScreen.lmaker->mTileMap->b[i].g->gem=NULL;

                 mPlayScreen.SetscoreText();
               }

           }
        }

    }

    if((mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tempY)!=NULL&&mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tempY)->solid)
       ||(mPlayScreen.lmaker->mTileMap->pointToTile(tempXX,tempY)!=NULL&&mPlayScreen.lmaker->mTileMap->pointToTile(tempXX,tempY)->solid))
    {

        mPlayScreen.characterDY = 0.0;
        mPlayScreen.jumped=true;
        mPlayScreen.activeJump=false;
        //mPlayScreen.character->gSpriteClip.x =0;
        int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY);
        int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY);
        int lly=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->y- mPlayScreen.character->hight;
        mPlayScreen.character->y=lly;
        //mPlayScreen.character->x=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
      //
      if(mInput->KeyDown(SDL_SCANCODE_LEFT)||mInput->KeyDown(SDL_SCANCODE_RIGHT))
      {

       mCurrentScreen=walking;
      }
      else
      {
          //cout<<"faling"<<endl;
          mPlayScreen.character->gSpriteClip.x =0;
        mCurrentScreen=idle;
      }


    }
    else
    {
        if(mInput->KeyDown(SDL_SCANCODE_LEFT))
        {
         if(!mPlayScreen.character->checkLeftCollisions(mPlayScreen.dx,*mPlayScreen.lmaker->mTileMap))
         {
//                  int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY);
//        int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY);
//            int llx=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
//        mPlayScreen.character->x=llx;
//          if(mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->jump_blocks)
//          {
//                                        int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY);
//        int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY);
//            int llx=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
//        mPlayScreen.character->x=llx;
//        cout<<"true"<<endl;
 //         }
          //if(!mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->fallColide(mPlayScreen.character->x,mPlayScreen.character->y
           //                                                                 ,mPlayScreen.character->width,mPlayScreen.character->hight))
           mPlayScreen.character->gSpriteClip.x =32;
           mPlayScreen.animLeft=true;
           mPlayScreen.moveLeft();
         }
//         else
//         {
//                            int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY);
//        int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY);
//            int llx=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
//        mPlayScreen.character->x=llx;
//         }

        }
        else if(mInput->KeyDown(SDL_SCANCODE_RIGHT))
        {
         if(!mPlayScreen.character->checkRightCollisions(mPlayScreen.dx,*mPlayScreen.lmaker->mTileMap))
         {
          mPlayScreen.character->gSpriteClip.x =32;
          mPlayScreen.animLeft=false;
          mPlayScreen.moveRight();
         }
//         else
//         {
//             int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY);
//                    int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY);
//            int llx=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
//        mPlayScreen.character->x=llx;
//         }
        }
    }
    //go back to start if we fall below the map boundary
    if(mPlayScreen.character->y>WINDOW_HEIGHT)
    {
        mCurrentScreen=start;
    }
    //check if we've collided with any entities and kill them if so
    for (int i = 0; i < mPlayScreen.old_size; i++)
    {
        if(mPlayScreen.snail[i].x>=0&&mPlayScreen.snail[i].x<=WINDOW_WIDTH&&!mPlayScreen.snail[i].consumad)
        if(mPlayScreen.snailColide(mPlayScreen.snail[i],*mPlayScreen.character))
        {
             mPlayScreen.SetscoreText();
             mPlayScreen.snail[i].consumad=true;
        }
    }
    //mPlayScreen.removeSnail(mPlayScreen.snail,mPlayScreen.SIZESnail,mPlayScreen.old_size);
//    for (int i = 0; i < mPlayScreen.snailold_size; i++)
//    {
//        if(mPlayScreen.snailColide(mPlayScreen.checksnailcolis[i],*mPlayScreen.character))
//        {
//            mPlayScreen.checksnailcolis[i].consumad=true;
//
//        }
//    }

}
