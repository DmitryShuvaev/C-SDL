#include "Character.h"

Character::Character()
{
    //ctor
            //mAudioMgr = AudioManager::Instance();
        character=new Texture("graphics/character.png");

        gSpriteClip.x =  0;
		gSpriteClip.y =  0;
		gSpriteClip.w = 16;
		gSpriteClip.h = 20;
        width=gSpriteClip.w *Scalex;
        hight=gSpriteClip.h*Scaley;
        x=width;
        y=hight;
}
Character::Character(const int x,const int y,const int w,const int h)
{
         //mAudioMgr = AudioManager::Instance();
        character=new Texture("graphics/character.png");

        gSpriteClip.x = x;
		gSpriteClip.y = y;
		gSpriteClip.w = w;
		gSpriteClip.h = h;
        width=gSpriteClip.w*Scalex;
        hight=gSpriteClip.h*Scaley;
        this->x=width;
        this->y=hight;

}
void Character::Render()
{
character->render( x, y, &gSpriteClip,width,hight );

}
void Character::RenderFlipped()
{

    character->RenderFlipped( x, y, &gSpriteClip,width,hight );
}
Character::~Character()
{
    //dtor
 delete character;
 character=NULL;
}
bool Character::checkLeftCollisions(float &dx,TileMap&mTileMap)
{
    int tempX=(x+0)-dx;
    int tileBottomLeft=y+(hight-1);
    //int tempXX=((x-3)+width)-dx;
    int tileTopLeft=y+1;
    //place player outside the X bounds on one of the tiles to reset any overlap
        if((mTileMap.pointToTile(tempX,tileBottomLeft)!=NULL&&mTileMap.pointToTile(tempX,tileBottomLeft)->solid)
       //||(mTileMap.pointToTile(tempX,tileTopLeft)!=NULL&&mTileMap.pointToTile(tempX,tileTopLeft)->solid)
           )
    {
       //cout<<"colision"<<endl;
//        int lx=mTileMap.indexX(tempX,tileBottomLeft);
//        int ly=mTileMap.indexY(x,tileBottomLeft);
//        int lly=mTileMap.table[ly][lx].brick->y- hight;
//        int llx=mTileMap.table[ly][lx].brick->x+mTileMap.table[ly][lx].brick->width;
//        x=llx;
      return true;
    }
    else if(mTileMap.pointToTile(tempX,tileTopLeft)!=NULL&&mTileMap.pointToTile(tempX,tileTopLeft)->solid)
    {
        return true;
    }

    return false;
}

bool Character::checkRightCollisions(float &dx,TileMap&mTileMap)
{
    int tempX=(x+width)-dx;
    int tempY=y+(hight-1);
    int tileTopLeft=y+1;
   // int tempXX=((x-3)+width)-dx;
    //place player outside the X bounds on one of the tiles to reset any overlap
    if((mTileMap.pointToTile(tempX,tempY)!=NULL&&mTileMap.pointToTile(tempX,tempY)->solid)
       //||(mTileMap.pointToTile(tempXX,tempY)!=NULL&&mTileMap.pointToTile(tempXX,tempY)->solid)
           )
    {
//       cout<<"colision"<<endl;
//        int lx=mTileMap.indexX(tempX,tempY);
//        int ly=mTileMap.indexY(x,tempY);
//        int lly=mTileMap.table[ly][lx].brick->y- hight;
//        int llx=mTileMap.table[ly][lx].brick->x+mTileMap.table[ly][lx].brick->width;
        //x=llx-1;
      return true;
    }
    else if(mTileMap.pointToTile(tempX,tileTopLeft)!=NULL&&mTileMap.pointToTile(tempX,tileTopLeft)->solid)
    {
        return true;
    }

    return false;
}
