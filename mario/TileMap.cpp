#include "TileMap.h"

TileMap::TileMap():
    numRows(10),numCols(100)
{
    //ctor
    initLevel();
    bricks=new Texture("graphics/tiles.png");
    topTiles=new Texture("graphics/tile_tops.png");
    jump_block=new Texture("graphics/jump_blocks.png");
    gems=new Texture("graphics/gems.png");
    bushesTexture=new Texture("graphics/bushes_and_cacti.png");
    table=new Table*[numRows];
    for(int y=0;y<numRows;y++)
    {

        table[y]=new Table[numCols];
    }
    //rand indexes top tiles
    randx_top=rand() % 6;
    randy_top=rand() % 18;

}
int TileMap::indexY(int x, int y)
{
   int localy=floor(y/TILE_SIZE);
   if(localy>=0)
   return localy;
   else return 0;
}
int TileMap::indexX(int x, int y)
{
   int localx=floor(x/TILE_SIZE);
   if(localx>=0&&localx<numCols)
   return localx;
   else return 0;
}
Brick* TileMap::pointToTile(int x, int y)
{
    int localx=floor(x/TILE_SIZE);
    int localy=floor(y/TILE_SIZE);
    if(localy>=0&&localx>=0
       &&localy<numRows&&localx<numCols)
    return table[localy][localx].brick;
    else return NULL;
}
void TileMap::initLevel()
{
    SkySpriteClip.x=0;
    SkySpriteClip.y=16;
    SkySpriteClip.w=16;
    SkySpriteClip.h=16;
    //jump block
        //rand jump blocks
    //randx_jumpBlock=rand() % 6;
    //randy_jumpBlock=rand() % 5;
    //Jump_blockClip.x=randx_jumpBlock*16;
    //Jump_blockClip.y=randy_jumpBlock*16;
    Jump_blockClip.w=16;
    Jump_blockClip.h=16;
    int dx=16;
    int dy=48;
    for(int y=0;y<10;y++)
    {

         for(int x=0;x<6;x++)
         {
            gSpriteClips[y][x].x = dx;
            gSpriteClips[y][x].y = dy;
            gSpriteClips[y][x].w = 16;
            gSpriteClips[y][x].h = 16;
            dx+=80;
         }
         dx=16;
         dy+=64;
    }
    //generate top tiles points
    dy=0;
    dx=0;
        for(int y=0;y<18;y++)
    {

         for(int x=0;x<6;x++)
         {
            TopsSpriteClips[y][x].x = dx;
            TopsSpriteClips[y][x].y = dy;
            TopsSpriteClips[y][x].w = 16;
            TopsSpriteClips[y][x].h = 16;
            dx+=80;
         }
         dx=16;
         dy+=64;
    }
    //block tiles
    dy=0;
    dx=0;
        for(int y=0;y<5;y++)
    {

         for(int x=0;x<6;x++)
         {
            JumpSpriteClips[y][x].x = dx;
            JumpSpriteClips[y][x].y = dy;
            JumpSpriteClips[y][x].w = 16;
            JumpSpriteClips[y][x].h = 16;
            dx+=16;
         }
         dx=0;
         dy+=16;
    }

//bushes sprite clips bushSpriteClips
    dy=0;
    dx=96;
    for(int y=0;y<4;y++)
    {

         for(int x=0;x<3;x++)
         {
            bushSpriteClips[y][x].x=dx;
            bushSpriteClips[y][x].y=dy;
            bushSpriteClips[y][x].w=16;
            bushSpriteClips[y][x].h=16;
            dx-=16;
         }
         dx=96;
         dy+=16;
    }
}
TileMap::~TileMap()
{
    //dtor
//    for(int x=0;x<numCols;x++)
//    for(int y=0;y<numRows;y++)
//    {
//        if(table[y][x].brick!=NULL)
//        {
//         delete table[y][x].brick;
//         table[y][x].brick=NULL;
//        }
//
//    }
    //delete table[0][0].brick;
    //table[0][0].brick=NULL;

    delete [] this->bushes;
    this->bushes=NULL;
    for( size_t i=0; i<this->numRows; i++ )
    {
        delete [] this->table[i];
    }
	delete [] this->table;
	//if(table[0][0].brick!=NULL)cout<<"not equalt to nul"<<endl;
	delete bricks;
	bricks=NULL;
	delete topTiles;
	topTiles=NULL;
	delete jump_block;
	jump_block=NULL;
	delete gems;
	gems=NULL;
	delete bushesTexture;
	bushesTexture=NULL;
}
void TileMap::Render()
{
    if(b!=NULL)
    {
     delete[] b;
     b=NULL;
     sizearr=1;
     indx=0;
    }

 for(int y=0;y<numRows;y++)
 {
     for(int x=0;x<numCols;x++)
     {
         //
      bricks->render( table[y][x].brick->x, table[y][x].brick->y, &table[y][x].brick->gSpriteClip
                                ,table[y][x].brick->width,table[y][x].brick->hight );
     if(table[y][x].brick->topper==true)
     {
      topTiles->render(table[y][x].brick->x, table[y][x].brick->y,&TopsSpriteClips[randy_top][randx_top]
                       ,table[y][x].brick->width,table[y][x].brick->hight);
     }
     else if(table[y][x].brick->jump_blocks==true)
     {
         //cout<<"numcols="<<randx_jumpBlock<<endl;

        if(table[y][x].brick->isGem==true)
        {
            if(table[y][x].brick->gem!=NULL)//&&table[y][x].brick->gem->startanim==true)
            {
                //table[y][x].brick->gemy-=3;
                if(table[y][x].brick->gem->startanim==true)
                table[y][x].brick->gem->gemAnimation(table[y][x].brick->gemy);
                         gems->render(table[y][x].brick->gemx, table[y][x].brick->gemy
                               ,&table[y][x].brick->gem->gemSpriteClip
                       ,table[y][x].brick->width,table[y][x].brick->hight);
                       //here add this brick to object to check collision
                       if(table[y][x].brick->gemx>=0&&table[y][x].brick->gemx<=WINDOW_WIDTH)
                       {
                           if(b==NULL)
                           {
                            b=new GemsCol[sizearr];
                            b[indx].g=table[y][x].brick;
                            old_size=sizearr;

                            indx++;
                           }
                           else
                           {
                             reSIZE(b,sizearr,old_size);
                             b[indx].g=table[y][x].brick;
                             indx++;
                             old_size=sizearr;
                           }

                           //cout<<"size="<<sizearr<<endl;
                       }
                       //cout<<"gem pos="<<table[y][x].brick->gemx<<endl;
            }


        }
                    jump_block->render(table[y][x].brick->x, table[y][x].brick->y
                               ,&JumpSpriteClips[table[y][x].brick->randy_jumpBlock][table[y][x].brick->randx_jumpBlock]
                       ,table[y][x].brick->width,table[y][x].brick->hight);
     }
     }
 }
 //
 //bushes render
 for (int i = 0; i < old_size_bush; i++)
 bushesTexture->render(bushes[i].x,bushes[i].y,&bushes[i].SpriteClip,bushes[i].width,bushes[i].hight);
}//

