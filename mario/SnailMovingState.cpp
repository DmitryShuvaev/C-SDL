#include "SnailMovingState.h"

SnailMovingState::SnailMovingState()
{
    //ctor
    mTimer = Timer::Instance();
//mAnimationTimer=0.2f;
    movingTimer=0;
    movingDuration=rand() % 5;

}

SnailMovingState::~SnailMovingState()
{
    //dtor
}
void SnailMovingState::movinAnimation(Snail&snail)
{

//mAnimationTimer += mTimer->DeltaTime();
//
//if(mAnimationTimer/0.2f>=1)
//{
//    if(count==2)
//    {
//     snail.gSpriteClip.x =  0;
//      count=0;
//      mAnimationTimer=0.f;
//    }
//    else if (count==1)
//    {
//      snail.gSpriteClip.x =  16;
//    }
//     count++;
//     mAnimationTimer=0.0f;
//}

}
//------------------------------------------------------------------------------
void SnailMovingState::Update(PlayScreen&mPlayScreen,Snail&snail)
{
      snail.movingTimer+= snail.mTimer->DeltaTime();
      snail.movinAnimation(0.2f);
      //reset movement direction and timer if timer is above duration
      if(snail.movingTimer > snail.movingDuration)
      {
          //chance to go into idle state randomly
            int randsnail=rand() % 4 + (1);
            if(randsnail==1)
            {
                snail.state=snail.idleS;
                Reset(snail);
            }
            else
            {
              //cout<<Snail::DIRECTION(rand() % 2);

             snail.movingDirection=Snail::DIRECTION(rand() % 2);
             if(snail.movingDirection==Snail::DIRECTION::left)
              snail.renderflipp=false;
             else snail.renderflipp=true;
               Reset(snail);
            }

      }
      else if(snail.movingDirection==Snail::DIRECTION::left)
      {
       if(!checkLeftCollisions(mPlayScreen,snail,5))
       {
        snail.x-=0.2;
       }
       else
       {
        //reset direction if we hit a wall
        snail.renderflipp=true;
        Reset(snail);
        snail.movingDirection=Snail::DIRECTION::right;
       }

      }
      else
      {
       if(!checkRightCollisions(mPlayScreen,snail,-5))
       {
        snail.x+=0.2;
       }
       else
       {
        snail.renderflipp=false;
        Reset(snail);

        snail.movingDirection=Snail::DIRECTION::left;
       }
      }

    // calculate difference between snail and player on X axis
    // and only chase if <= 5 tiles
    int diffX = abs(mPlayScreen.character->x - snail.x);

    if(diffX < 5 * TILE_SIZE)
    {
      snail.state=snail.chasing;
      //cout<<diffX<<endl;
    }




}
//------------------------------------------------------------------------------
void SnailMovingState::Reset(Snail&snail)
{
 snail.movingTimer=0;
 snail.movingDuration=rand() % 6+1;

}
//------------------------------------------------------------------------------
bool SnailMovingState::checkLeftCollisions(PlayScreen&mPlayScreen,Snail&snail,int ex)
{
    int tempX=(snail.x+ex)-mPlayScreen.dx;
    int tileBottomLeft=snail.y+(snail.hight-1);
    int tileTopLeft=snail.y+1;
    //place player outside the X bounds on one of the tiles to reset any overlap
    if((mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tileBottomLeft)!=NULL
            &&mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tileBottomLeft)->solid)
           )
    {
//        int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tileBottomLeft-1);
//        int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tileBottomLeft-1);
//        int llx=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
//        snail.x=llx+mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->width;
      return true;
    }
    else if(mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tileTopLeft)!=NULL
            &&mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tileTopLeft)->solid)
    {

        return true;
    }
    else if(mPlayScreen.lmaker->mTileMap->pointToTile(tempX,snail.y+(snail.hight))!=NULL
            &&!mPlayScreen.lmaker->mTileMap->pointToTile(tempX,snail.y+(snail.hight))->solid)
    {
        return true;
    }

    return false;
}
//------------------------------------------------------------------------------
bool SnailMovingState::checkRightCollisions(PlayScreen&mPlayScreen,Snail&snail,int ex)
{
    int tempX=(snail.x+snail.width+ex)-mPlayScreen.dx;
    int tempY=snail.y+(snail.hight-1);
    int tileTopLeft=snail.y+1;
   // int tempXX=((x-3)+width)-dx;
    //place player outside the X bounds on one of the tiles to reset any overlap
    if((mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tempY)!=NULL
        &&mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tempY)->solid)
           )
    {
//        int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY-1);
//        int ly=mPlayScreen.lmaker->mTileMap->indexY(snail.x,tempY-1);
//        int llx=mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->x;
//        snail.x=llx;
      return true;
    }
    else if(mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tileTopLeft)!=NULL
            &&mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tileTopLeft)->solid)
    {
        return true;
    }
    else if(mPlayScreen.lmaker->mTileMap->pointToTile(tempX,snail.y+(snail.hight))!=NULL
            &&!mPlayScreen.lmaker->mTileMap->pointToTile(tempX,snail.y+(snail.hight))->solid)
    {
        return true;
    }
    return false;
}
