#include "SnailChasingState.h"

SnailChasingState::SnailChasingState()
{
    //ctor
}

SnailChasingState::~SnailChasingState()
{
    //dtor
}
void SnailChasingState::Update(PlayScreen&mPlayScreen,Snail&snail)
{
      snail.movingTimer+= snail.mTimer->DeltaTime();
      snail.movinAnimation(0.1f);
    int diffX = abs(mPlayScreen.character->x - snail.x);

    if(diffX > 5 * TILE_SIZE)
    {
      snail.state=snail.moving;
      //cout<<"moving"<<endl;
    }
    else if(mPlayScreen.character->x < snail.x)
    {
     snail.renderflipp=false;
     snail.movingDirection=Snail::DIRECTION::left;
      if(!checkLeftCollisions(mPlayScreen,snail,5))
       {
        snail.x-=0.4;
       }

    }
    else
    {
     snail.renderflipp=true;
     snail.movingDirection=Snail::DIRECTION::right;
      if(!checkRightCollisions(mPlayScreen,snail,-5))
       {
        snail.x+=0.4;
       }
    }
}
//------------------------------------------------------------------------------
bool SnailChasingState::checkLeftCollisions(PlayScreen&mPlayScreen,Snail&snail,int ex)
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
bool SnailChasingState::checkRightCollisions(PlayScreen&mPlayScreen,Snail&snail,int ex)
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
