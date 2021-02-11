#include "PlayerJumpState.h"

PlayerJumpState::PlayerJumpState()
{
    //ctor
        mInput=InputManager::Instance();
}

PlayerJumpState::~PlayerJumpState()
{
    //dtor
}
void PlayerJumpState::Update(SCREENS &mCurrentScreen,PlayScreen&mPlayScreen)
{
    mInput->Update();
        // apply velocity to character Y
    mPlayScreen.characterDY = mPlayScreen.characterDY + mPlayScreen.GRAVITY;
    mPlayScreen.character->y=mPlayScreen.character->y+mPlayScreen.characterDY*0.2;
//    if(mPlayScreen.lmaker->mTileMap->b)
//    cout<<"brick "<<mPlayScreen.lmaker->mTileMap->b->x<<endl;

    if(mPlayScreen.characterDY>=0)
    {
        mCurrentScreen=falling;
    }
    //look at two tiles above our head and check for collisions; 3 pixels of leeway for getting through gaps
     int tempX=(mPlayScreen.character->x+3)-mPlayScreen.dx;
     int tempY=mPlayScreen.character->y;
     int tempXX=((mPlayScreen.character->x-3)+mPlayScreen.character->width)-mPlayScreen.dx;

    if(mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tempY)!=NULL&&mPlayScreen.lmaker->mTileMap->pointToTile(tempX,tempY)->solid)

       {
           mPlayScreen.characterDY = 0.0;
           mCurrentScreen=falling;
           int lx=mPlayScreen.lmaker->mTileMap->indexX(tempX,tempY);
           int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY);
           //mPlayScreen.mAnimation->gemAnimation(mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->gemy);
           //mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->gemy=150;
           if(mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->gem==NULL
              &&!mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->consumad)
           {
            //cout<<"gem created"<<endl;
            mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->gem=new Gem();

            mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->consumad=true;
           }

       }
     if(mPlayScreen.lmaker->mTileMap->pointToTile(tempXX,tempY)!=NULL&&mPlayScreen.lmaker->mTileMap->pointToTile(tempXX,tempY)->solid)
    {
           mPlayScreen.characterDY = 0.0;
           mCurrentScreen=falling;
           //mPlayScreen.character->gSpriteClip.x =0;
           int lx=mPlayScreen.lmaker->mTileMap->indexX(tempXX,tempY);
           int ly=mPlayScreen.lmaker->mTileMap->indexY(mPlayScreen.character->x,tempY);
           //mPlayScreen.mAnimation->gemAnimation(mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->gemy);
           //mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->gemy=150;
           //mPlayScreen.mAnimation->startanim=true;
           //mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->startAnimation=true;
           if(mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->gem==NULL
              &&!mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->consumad)
           {
            //cout<<"gem created"<<endl;
            mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->gem=new Gem();
            //mPlayScreen.lmaker->mTileMap->table[ly-1][lx].brick->solid=true;
            mPlayScreen.lmaker->mTileMap->table[ly][lx].brick->consumad=true;
           }


    }
    if(mInput->KeyDown(SDL_SCANCODE_LEFT))
    {
        if(!mPlayScreen.character->checkLeftCollisions(mPlayScreen.dx,*mPlayScreen.lmaker->mTileMap))
        {
         mPlayScreen.character->gSpriteClip.x =32;
         mPlayScreen.animLeft=true;
         mPlayScreen.moveLeft();
        }

    }
    else if(mInput->KeyDown(SDL_SCANCODE_RIGHT))
    {
        if(!mPlayScreen.character->checkRightCollisions(mPlayScreen.dx,*mPlayScreen.lmaker->mTileMap))
        {
         mPlayScreen.character->gSpriteClip.x =32;
         mPlayScreen.animLeft=false;
         mPlayScreen.moveRight();
        }

    }
//check if we've collided with any entities and die if so
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
