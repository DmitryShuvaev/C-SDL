#include "PlayerWalkingState.h"

PlayerWalkingState::PlayerWalkingState()
{
    //ctor
    mInput=InputManager::Instance();
}

PlayerWalkingState::~PlayerWalkingState()
{
    //dtor
}
void PlayerWalkingState::Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen)
{
    mInput->Update();
    if(mPlayScreen.lmaker->mTileMap->b!=NULL)
    {
     //if(mPlayScreen.lmaker->mTileMap->b->gemx<=20)
        for(int i=0;i<mPlayScreen.lmaker->mTileMap->sizearr;i++)
        {
            //if(mPlayScreen.lmaker->mTileMap->b[i]!=NULL)
         if(mPlayScreen.lmaker->mTileMap->b[i].g->gemColide(mPlayScreen.character->x,mPlayScreen.character->y,mPlayScreen.character->width,mPlayScreen.character->hight))

   {
       if(mPlayScreen.lmaker->mTileMap->b[i].g->gem)
       {
              delete mPlayScreen.lmaker->mTileMap->b[i].g->gem;
        mPlayScreen.lmaker->mTileMap->b[i].g->gem=NULL;
        cout<<"brck deleted"<<endl;
         //set text to score texture
         mPlayScreen.scoreValue=mPlayScreen.scoreValue+100;
         mPlayScreen.scoreText.str( "" );
         mPlayScreen.scoreText << mPlayScreen.scoreValue;
         mPlayScreen.score->SetText(mPlayScreen.scoreText.str().c_str(),{255, 255, 255});
         mPlayScreen.blackscore->SetText(mPlayScreen.scoreText.str().c_str(),{0, 0, 0});
       }

   }
        }

    }
    if(mInput->KeyDown(SDL_SCANCODE_LEFT)||mInput->KeyDown(SDL_SCANCODE_RIGHT))
    {

     int tempX=(mPlayScreen.character->x+3)-mPlayScreen.dx;
     int tempY=mPlayScreen.character->y+(mPlayScreen.character->hight);
     int tempXX=((mPlayScreen.character->x-3)+mPlayScreen.character->width)-mPlayScreen.dx;
     //gem colision

//     if(mPlayScreen.lmaker->mTileMap->pointToTile(tempX,mPlayScreen.character->y)->consumable)
//     {
//         cout<<"gem colide"<<endl;
//     }
//          if(mPlayScreen.lmaker->mTileMap->pointToTile(tempXX,mPlayScreen.character->y)->consumable)
//     {
//         cout<<"gem colide"<<endl;
//     }
    if((mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tempY)!=NULL&&mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tempY)->solid)
       ||(mPlayScreen.lmaker->mTileMap->pointToTile(tempXX,tempY)!=NULL&&mPlayScreen.lmaker->mTileMap->pointToTile(tempXX,tempY)->solid))
    {


      //
      if(mInput->KeyDown(SDL_SCANCODE_LEFT))
      {
          mPlayScreen.animLeft=true;
          mPlayScreen.mAnimation->movinAnimation(*mPlayScreen.character);
          if(!mPlayScreen.character->checkLeftCollisions(mPlayScreen.dx,*mPlayScreen.lmaker->mTileMap))
          mPlayScreen.moveLeft();
//            else
//            {
//                     int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY-1);
//        int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY-1);
//        int llx=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
//        mPlayScreen.character->x=llx;
//            }
               if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
               {
                    mPlayScreen.character->gSpriteClip.x =32;
                    //jump state
                      mPlayScreen.characterDY = mPlayScreen.JUMP_VELOCITY;
                      mCurrentScreen=jump;
               }//end if
      }
      else if(mInput->KeyDown(SDL_SCANCODE_RIGHT))
        {
         mPlayScreen.animLeft=false;
              mPlayScreen.mAnimation->movinAnimation(*mPlayScreen.character);
             if(!mPlayScreen.character->checkRightCollisions(mPlayScreen.dx,*mPlayScreen.lmaker->mTileMap))
             mPlayScreen.moveRight();
//            else
//            {
//                     int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY-1);
//        int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY-1);
//        int llx=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
//        mPlayScreen.character->x=llx;
//            }
                   if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
                   {
                      mPlayScreen.character->gSpriteClip.x =32;
                    //jump state
                      mPlayScreen.characterDY = mPlayScreen.JUMP_VELOCITY;
                      mCurrentScreen=jump;
                   }//end if &&!activeJump
        }
//      else if(mInput->KeyReleased(SDL_SCANCODE_LEFT)||mInput->KeyReleased(SDL_SCANCODE_RIGHT))
//        {
//         mPlayScreen.animLeft=false;
//         mPlayScreen.character->gSpriteClip.x =0;
//         mPlayScreen.mAnimation->mAnimationTimer=0.2f;
//cout<<"walking"<<endl;
//        }


    }
    //if not collision
    else
    {
        mPlayScreen.characterDY = 0.0;
        mPlayScreen.jumped=true;
        mPlayScreen.activeJump=false;
//        int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY);
//        int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY);
//        int lly=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->y- mPlayScreen.character->hight;
//        mPlayScreen.character->y=lly;
        mCurrentScreen=falling;
        mPlayScreen.character->gSpriteClip.x =32;
    }
    }
    else if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
    {
       mPlayScreen.character->gSpriteClip.x =32;
       mCurrentScreen=jump;
    }
    //if we're not pressing anything at all
    else
    {
      mPlayScreen.character->gSpriteClip.x =0;
      mCurrentScreen=idle;
    }
    //check if we've collided with any entities and die if so
//    for (int i = 0; i < mPlayScreen.snailold_size; i++)
//    {
//        if(mPlayScreen.snailColide(mPlayScreen.checksnailcolis[i],*mPlayScreen.character))
//        {
//            //mPlayScreen.snail[i].consumad=true;
//            if(!mPlayScreen.checksnailcolis[i].consumad)
//            mCurrentScreen=start;
//        }
//    }
    for (int i = 0; i < mPlayScreen.old_size; i++)
    {
        if(mPlayScreen.snail[i].x>=0&&mPlayScreen.snail[i].x<=WINDOW_WIDTH)
        if(mPlayScreen.snailColide(mPlayScreen.snail[i],*mPlayScreen.character))
        {
            if(!mPlayScreen.snail[i].consumad)
            mCurrentScreen=start;
        }
    }
}
