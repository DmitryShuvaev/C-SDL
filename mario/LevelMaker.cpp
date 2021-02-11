#include "LevelMaker.h"

LevelMaker::LevelMaker()

{
    //ctor
    mTileMap=new TileMap();
    ground_level=7;
    int blockHeight=4;
    const int randx=rand() % 6;;//this is x position
    const int randy=rand()%  10;
    bool isPil=false;
for(int x=0;x<mTileMap->numCols;x++)
{
    int tileID = mTileMap->SCREENS1::TILE_ID_EMPTY;
    for(int y=0;y<ground_level;y++)
    {
         mTileMap->table[y][x].brick = new Brick(mTileMap->SkySpriteClip.x,
                                                 mTileMap->SkySpriteClip.y
                                       ,mTileMap->SkySpriteClip.w,
                                       mTileMap->SkySpriteClip.h);
         mTileMap->table[y][x].brick->x=x*mTileMap->table[y][x].brick->width;
         mTileMap->table[y][x].brick->y=y*mTileMap->table[y][x].brick->hight;
         mTileMap->table[y][x].brick->solid=false;
    }
        //chance to just be emptiness
        if (rand() % 8 == 1)
        {
           for(int y=ground_level;y<mTileMap->numRows;y++)
           {
                          mTileMap->table[y][x].brick = new Brick(mTileMap->SkySpriteClip.x,
                                                 mTileMap->SkySpriteClip.y
                                       ,mTileMap->SkySpriteClip.w,
                                       mTileMap->SkySpriteClip.h);
             mTileMap->table[y][x].brick->x=x*mTileMap->table[y][x].brick->width;
             mTileMap->table[y][x].brick->y=y*mTileMap->table[y][x].brick->hight;
             mTileMap->table[y][x].brick->solid=false;
           }
        }else
        {
            isPil=false;
            int tempx,tempy;
                  for(int y=ground_level;y<mTileMap->numRows;y++)
                  {


                  mTileMap->table[y][x].brick = new Brick(mTileMap->gSpriteClips[randy][randx].x,
                                                 mTileMap->gSpriteClips[randy][randx].y
                                       ,mTileMap->gSpriteClips[randy][randx].w,
                                       mTileMap->gSpriteClips[randy][randx].h);
                 mTileMap->table[y][x].brick->x=x*mTileMap->table[y][x].brick->width;
                 mTileMap->table[y][x].brick->y=y*mTileMap->table[y][x].brick->hight;
                 mTileMap->table[y][x].brick->solid=true;
                 if(y==ground_level)
                 {
                    mTileMap->table[y][x].brick->topper=true;
                    tempx=mTileMap->table[y][x].brick->x;
                    tempy=mTileMap->table[y-1][x].brick->y;
                 }

                  }
           //chance to generate a pillar
            if (rand() % 8 == 1)
            {
                isPil=true;
             //pillar tiles
                mTileMap->table[ground_level][x].brick->topper=false;
                mTileMap->table[ground_level-1][x].brick->gSpriteClip.x=mTileMap->gSpriteClips[randy][randx].x;
                mTileMap->table[ground_level-1][x].brick->gSpriteClip.y=mTileMap->gSpriteClips[randy][randx].y;
                mTileMap->table[ground_level-1][x].brick->solid=true;
                //
                mTileMap->table[ground_level-2][x].brick->gSpriteClip.x=mTileMap->gSpriteClips[randy][randx].x;
                mTileMap->table[ground_level-2][x].brick->gSpriteClip.y=mTileMap->gSpriteClips[randy][randx].y;
                mTileMap->table[ground_level-2][x].brick->solid=true;
                mTileMap->table[ground_level-2][x].brick->topper=true;;
            //chance to generate bush on pillar
            if (rand() % 8 == 1){
            tempx=mTileMap->table[ground_level-2][x].brick->x;
            tempy=mTileMap->table[ground_level-3][x].brick->y;
            generateBushes(tempx,tempy);
            }
            }
                if (!isPil)
                {
                //chance to generate bushes
                  if (rand() % 8 == 1)
                  {
                   generateBushes(tempx,tempy);
                  }
                }
        }
        //chance to spawn a block
     if (rand() % 8 == 1)
     {
       if(!isPil)
       {
       mTileMap->table[blockHeight][x].brick->randx_jumpBlock=rand() % 6;
       mTileMap->table[blockHeight][x].brick->randy_jumpBlock=rand() % 5;
       //mTileMap->Jump_blockClip.x=mTileMap->randx_jumpBlock*16;
       //mTileMap->Jump_blockClip.y=mTileMap->randy_jumpBlock*16;

       mTileMap->table[blockHeight][x].brick->jump_blocks=true;
       mTileMap->table[blockHeight][x].brick->solid=true;
       //chance to spawn gem, not guaranteed
       //if (rand() % 5 == 1)
       {
        //mTileMap->table[blockHeight][x].brick->gem=new
        mTileMap->table[blockHeight][x].brick->gemx=mTileMap->table[blockHeight][x].brick->x;
        mTileMap->table[blockHeight][x].brick->gemy=mTileMap->table[blockHeight][x].brick->y-mTileMap->table[blockHeight][x].brick->hight/4;
        mTileMap->table[blockHeight][x].brick->isGem=true;
       }
       }
       else
       {
        mTileMap->table[blockHeight-2][x].brick->randx_jumpBlock=rand() % 6;
        mTileMap->table[blockHeight-2][x].brick->randy_jumpBlock=rand() % 5;

        mTileMap->table[blockHeight-2][x].brick->jump_blocks=true;
        mTileMap->table[blockHeight-2][x].brick->solid=true;
       }
     }
}
//mTileMap->table[6][5].brick->gSpriteClip.x=0;
//mTileMap->table[6][5].brick->gSpriteClip.y=0;
//mTileMap->table[6][5].brick->gSpriteClip.w=16;
//mTileMap->table[6][5].brick->gSpriteClip.h=16;
//mTileMap->table[6][5].brick->solid=true;
//cout<<mTileMap->SCREENS1::SKY;
//cout<<"numcols="<<numCols<<endl;
}
//

LevelMaker::~LevelMaker()
{
    //dtor
// for(int x=0;x<mTileMap->numCols;x++)
// {
//  for(int y=0;y<mTileMap->numRows;y++)
//    {
//     if(mTileMap->table[y][x].brick!=NULL)
//     {
//     delete mTileMap->table[y][x].brick;
//     mTileMap->table[y][x].brick=NULL;
//     }
//
//    }
// }

 delete mTileMap;
 mTileMap=NULL;

}
//------------------------------------------------------------------------------
void LevelMaker::generateBushes(int &tempx,int &tempy)
{
    int randx=rand()%3;
    int randy=rand()%4;
 if(mTileMap->bushes==NULL)
 {
    mTileMap->bushes=new TileMap::Bushes[mTileMap->SIZEBush];
    mTileMap->bushes[mTileMap->indxBush].x=tempx;
    mTileMap->bushes[mTileMap->indxBush].y=tempy;
    mTileMap->bushes[mTileMap->indxBush].SpriteClip=mTileMap->bushSpriteClips[randy][randx];
    mTileMap->old_size_bush=mTileMap->SIZEBush;
    mTileMap->indxBush++;
 }
 else
 {
    mTileMap->reSIZE(mTileMap->bushes,mTileMap->SIZEBush,mTileMap->old_size_bush);
    mTileMap->bushes[mTileMap->indxBush].x=tempx;
    mTileMap->bushes[mTileMap->indxBush].y=tempy;
    mTileMap->bushes[mTileMap->indxBush].SpriteClip=mTileMap->bushSpriteClips[randy][randx];
    mTileMap->indxBush++;
    mTileMap->old_size_bush=mTileMap->SIZEBush;
 }
}
