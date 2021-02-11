#include "PlayScreen.h"

#include "StartScreen.h"

PlayScreen::PlayScreen()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
    pause=new Texture("fonts/font.ttf","PAUSED",32*3,{255,255,255});
    pause->SetXY(pause->mGraphics->WINDOW_WIDTH/2 - pause->mWidth/2,
                 pause->mGraphics->WINDOW_HEIGHT/2 -48);

    //mTimer = Timer::Instance();
    background=new Texture("graphics/backgrounds.png");
        int randy[] = {0,128,256};
        backgroundSpriteClip.x =  0;
		backgroundSpriteClip.y =  randy[rand()%3];
		backgroundSpriteClip.w = background->mRenderRect.w;
		backgroundSpriteClip.h = 128;
        backgroundwidth=backgroundSpriteClip.w *5;
        backgroundhight=backgroundSpriteClip.h *7;
        //
        backgrX2=WINDOW_WIDTH;
        //
        init();

}//end
void PlayScreen::init()
{
    characterDY=0.0;
    JUMP_VELOCITY=-70;
    GRAVITY = 2;
    jumped=false;
    activeJump=false;
    c=0;
    dx=0;
    scoreValue=0;
    lmaker=new LevelMaker();
    character=new Character(0,0,16,20);
    character->x=WINDOW_WIDTH / 2 - (character->width / 2);
    character->y=10;
    int randy[] = {0,128,256};

    backgroundSpriteClip.y =  randy[rand()%3];
    mAnimation=new Animation();
    mAnimation->count=1;
    score=new Texture("fonts/font.ttf","0",16*5,{255,255,255});
    score->SetXY(20,20);
    blackscore=new Texture("fonts/font.ttf","0",16*5,{0,0,0});
    blackscore->SetXY(25,25);
        //
    snailTexture =new Texture("graphics/creatures.png");
    SIZESnail=1;old_size=0;
    indx=0;
    spawnEnemies();
}

void PlayScreen::Update(SCREENS &mCurrentScreen)
{
   mInput->Update();
}//end update
void PlayScreen::Render()
{
//deleteColissnailar();
   if((backgrX)<=-WINDOW_WIDTH)
   {
       //cout<<(backgrX)<<endl;
       backgrX2=WINDOW_WIDTH;
       backgrX=0;

   }else if(backgrX>=0)
   {
       backgrX2=0;
       backgrX=-WINDOW_WIDTH;
   }
    background->render( backgrX, backgrY, &backgroundSpriteClip,backgroundwidth,backgroundhight );
    background->render( backgrX2, backgrY, &backgroundSpriteClip,backgroundwidth,backgroundhight );
    lmaker->mTileMap->Render();

    blackscore->Render();
    score->Render();
    for (int i = 0; i < old_size; i++)
    {
      //
      if(!snail[i].renderflipp&&!snail[i].consumad
         &&snail[i].x>=0&&snail[i].x<=WINDOW_WIDTH)
      snailTexture->render( snail[i].x, snail[i].y, &snail[i].gSpriteClip,snail[i].width,snail[i].hight );
      else if(!snail[i].consumad
              &&snail[i].x>=0&&snail[i].x<=WINDOW_WIDTH)
      snailTexture->RenderFlipped( snail[i].x, snail[i].y, &snail[i].gSpriteClip,snail[i].width,snail[i].hight );
      //
      //SnailArray(snail[i]);
    }
renderSnailarr();
 if(animLeft)
 character->RenderFlipped();
 else
 character->Render();
}
PlayScreen::~PlayScreen()
{
//    //dtor
    mInput=NULL;
    AudioManager::Release();
    mAudioMgr = NULL;
    delete mAnimation;
    mAnimation=NULL;
    delete character;
    character=NULL;
    delete snailTexture;
    snailTexture=NULL;
    delete blackscore;
    blackscore=NULL;
    delete score;
    score=NULL;
    delete lmaker;
    lmaker=NULL;
    delete [] this->snail;
    snail=NULL;
}
void PlayScreen::clearScreen()
{

if(character!=NULL)
{
 delete character;
 character=NULL;
}

 delete snailTexture;
 snailTexture=NULL;
 delete blackscore;
 blackscore=NULL;
 delete score;
 score=NULL;
 delete mAnimation;
 mAnimation=NULL;
if(snail!=NULL)
{
 delete [] snail;
 snail=NULL;
}

delete lmaker;
lmaker=NULL;
}
//
void PlayScreen::moveLeft()
{

    if(character->x<=WINDOW_WIDTH / 2 - (character->width / 2)
       &&(lmaker->mTileMap->table[0][lmaker->mTileMap->numCols-1].brick->x>=WINDOW_WIDTH-5
        //||lmaker->mTileMap->table[0][lmaker->mTileMap->numCols-1].brick->x>=WINDOW_WIDTH+5
        )
       &&lmaker->mTileMap->table[0][0].brick->x<0)
    {


 dx+=3;
 //self.player.x - PLAYER_WALK_SPEED * dt
 //mPlayScreen.character->x+mPlayScreen.PLAYER_WALK_SPEED*0.2;
     for(int y=0;y<lmaker->mTileMap->numRows;y++)
     {
         for(int x=0;x<lmaker->mTileMap->numCols;x++)
         {

             lmaker->mTileMap->table[y][x].brick->x+=3;
             lmaker->mTileMap->table[y][x].brick->gemx+=3;
         }
     }//
     //move snail with bricks together
    for (int i = 0; i < old_size; i++)
    {
      snail[i].x+=3;

    }
    //move bushes
    for (int i = 0; i < lmaker->mTileMap->old_size_bush; i++)
    {
      lmaker->mTileMap->bushes[i].x+=3;
    }
     backgrX+=1;
     backgrX2+=1;

     //cout<<(backgrX)<<endl;
    }
    else if(character->x>0)
    {
     character->x-=3;
    }
}
//------------------------------------------------------------------------------
void PlayScreen::moveRight()
{

 if(character->x>=WINDOW_WIDTH / 2 - (character->width / 2)
    &&lmaker->mTileMap->table[0][lmaker->mTileMap->numCols-1].brick->x>WINDOW_WIDTH)
 {


 dx-=3;
 for(int y=0;y<lmaker->mTileMap->numRows;y++)
 {
     for(int x=0;x<lmaker->mTileMap->numCols;x++)
     {
         lmaker->mTileMap->table[y][x].brick->x-=3;
         lmaker->mTileMap->table[y][x].brick->gemx-=3;
     }
 }
 //move snail with brick right
    for (int i = 0; i < old_size; i++)
    {
      snail[i].x-=3;

    }
    //move bushes
    for (int i = 0; i < lmaker->mTileMap->old_size_bush; i++)
    {
      lmaker->mTileMap->bushes[i].x-=3;
    }
 backgrX-=1;
 backgrX2-=1;

 //cout<<(backgrX)<<endl;
 }
 else if(character->x+character->width<WINDOW_WIDTH)
 {
  character->x+=3;

 }
}
void PlayScreen::moveGem()
{
//  if(mAnimation->startanim)
//  {
//     mAnimation->gemAnimation(lmaker->mTileMap->table[ly][lx].brick->gemy);
//  }
}
//------------------------------------------------------------------------------
void PlayScreen::spawnEnemies()
{
    //spawn snails in the level
for(int x=0;x<lmaker->mTileMap->numCols;x++)
{
    //flag for whether there's ground on this column of the level
        bool groundFound = false;
    //int tileID = mTileMap->SCREENS1::TILE_ID_EMPTY;
    for(int y=0;y<lmaker->mTileMap->numRows;y++)
    {
      if(!groundFound)
      {
        if(lmaker->mTileMap->table[y][x].brick->topper)
        {
            groundFound=true;
            //random chance, 1 in 20
            int randsnail=rand() % 5 + (1);
            if(randsnail==1)
            {


                        if(snail==NULL)
                           {
                            snail=new Snail[SIZESnail];
                            snail[indx].x=lmaker->mTileMap->table[y][x].brick->x;
                            snail[indx].y=lmaker->mTileMap->table[y][x].brick->y-snail[indx].hight;
                            snail[indx].state=snail[indx].SNAILSTATES::idleS;
                            old_size=SIZESnail;

                            indx++;
                           }
                           else
                           {
                             lmaker->mTileMap->reSIZE(snail,SIZESnail,old_size);
                            snail[indx].x=lmaker->mTileMap->table[y][x].brick->x;
                            snail[indx].y=lmaker->mTileMap->table[y][x].brick->y-snail[indx].hight;
                            snail[indx].state=snail[indx].SNAILSTATES::idleS;
                             indx++;
                             old_size=SIZESnail;
                           }
            }

        }
      }
    }
}
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void PlayScreen::deleteColissnailar()
{
    if(checksnailcolis !=NULL)
    {
     delete[] checksnailcolis;
     checksnailcolis=NULL;
     sizeSnailColisarr=1;
     indxsnailcol=0;
    }
}
//------------------------------------------------------------------------------
void PlayScreen::SnailArray(Snail&snail)
{
  if(snail.x>=0&&snail.x<=WINDOW_WIDTH)
  {
    if(checksnailcolis ==NULL)
    {
     checksnailcolis=new Snail[sizeSnailColisarr];
     checksnailcolis[indxsnailcol] =snail;
     snailold_size=sizeSnailColisarr;
     indxsnailcol++;
    }
    else
    {
     lmaker->mTileMap->reSIZE(checksnailcolis,sizeSnailColisarr,snailold_size);
     checksnailcolis[indxsnailcol] =snail;
     indxsnailcol++;
     snailold_size=sizeSnailColisarr;
    }
  }
}
//------------------------------------------------------------------------------
void PlayScreen::SetscoreText()
{
    scoreValue=scoreValue+100;
    scoreText.str( "" );
    scoreText << scoreValue;
    score->SetText(scoreText.str().c_str(),{255, 255, 255});
    blackscore->SetText(scoreText.str().c_str(),{0, 0, 0});
}
//------------------------------------------------------------------------------
void PlayScreen::renderSnailarr()
{
     for (int i = 0; i < snailold_size; i++)
    {
      //
      if(!checksnailcolis[i].renderflipp&&!checksnailcolis[i].consumad)
      snailTexture->render( checksnailcolis[i].x, checksnailcolis[i].y, &checksnailcolis[i].gSpriteClip,checksnailcolis[i].width,checksnailcolis[i].hight );
      else if(!checksnailcolis[i].consumad)
      snailTexture->RenderFlipped( checksnailcolis[i].x, checksnailcolis[i].y, &checksnailcolis[i].gSpriteClip,checksnailcolis[i].width,checksnailcolis[i].hight );
    }
}
void PlayScreen::removeSnail(Snail *&original, int &SIZESnail,int &old_size)
{
    SIZESnail-=1;
    int index=0;
	Snail *temporiginal = new Snail[SIZESnail]; //(final)new array

	for (int i = 0; i < old_size; i++) //copy old array to new array
	{
	    if(!original[i].consumad)
        {
         temporiginal[index++] = original[i];
        }
	}

	delete[] original; //delete old array
	original = temporiginal; //point old array to new array
	old_size=SIZESnail;
	cout<<old_size<<endl;
}
//------------------------------------------------------------------------------
bool PlayScreen::snailColide(Snail&snail,Character&character )
{
     if(snail.x+snail.width>=character.x &&
        character.x+character.width>=snail.x &&
        snail.y+snail.hight>=character.y &&
        character.y+character.hight>=snail.y)
     {
         return true;
     }
     return false;
}
