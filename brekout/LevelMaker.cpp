#include "LevelMaker.h"

LevelMaker::LevelMaker():
    numRows(1),numCols(1)
{
    //ctor
    initLevel();
    numRows=rand() % 5 + (1);
    //generates rand numbers from 7 to 13
    numCols=rand() % 7 + (7);
    table=new Table*[numRows];
    for(int y=0;y<numRows;y++)
    {
        //whether we want to enable skipping for this row
        int skipPattern=rand() % 2;
        int alternateColor1=rand() % 6;
        bool skipFlag=rand() % 2;
        table[y]=new Table[numCols];
        for(int x=0;x<numCols;x++)
        {

         table[y][x].brick = new Brick(gSpriteClips[alternateColor1].x,gSpriteClips[alternateColor1].y
                                       ,gSpriteClips[alternateColor1].w,gSpriteClips[alternateColor1].h);
         table[y][x].brick->x=(x)*table[y][x].brick->width+(8*2)+ (13 - numCols) * table[y][x].brick->hight;
         table[y][x].brick->y=y*table[y][x].brick->hight+table[y][x].brick->hight;
         table[y][x].brick->color=alternateColor1;
            if(skipFlag&&skipPattern)
            {
               table[y][x].brick->inPlay=false;
               skipFlag=false;
            }
            else
            {
             skipFlag=true;
            }
        }
    }
//cout<<"numcols="<<numCols<<endl;
}
//
void LevelMaker::initLevel()
{
    for(int i=0;i<6;i++)
    {
        if(i==0)
        {
        gSpriteClips[i].x =  0;
		gSpriteClips[i].y =  0;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==1)
        {
        gSpriteClips[i].x =  128;
		gSpriteClips[i].y =  0;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==2)
        {
        gSpriteClips[i].x =  64;
		gSpriteClips[i].y =  16;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==3)
        {
        gSpriteClips[i].x =  0;
		gSpriteClips[i].y =  32;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==4)
        {
        gSpriteClips[i].x =  128;
		gSpriteClips[i].y =  32;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }
        else if(i==5)
        {
        gSpriteClips[i].x =  64;
		gSpriteClips[i].y =  48;
		gSpriteClips[i].w = 32;
		gSpriteClips[i].h = 16;
        }

    }

}
LevelMaker::~LevelMaker()
{
    //dtor
    for(int y=0;y<numRows;y++)
    {
        for(int x=0;x<numCols;x++)
        {
            delete table[y][x].brick;
        }
    }
    	for( size_t i=0; i<this->numRows; i++ )
        {
           delete [] this->table[i];
        }


	delete [] this->table;
}
