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
		//Set top left sprite
//		gSpriteClips.x =   0;
//		gSpriteClips.y =   0;
//		gSpriteClips.w = 100;
//		gSpriteClips.h = 100;
    //
    padlle=new Paddle();
    ball=new Ball();
     /* generate number between 1 and 2 (including 1 and 2)*/
     int plusv=rand() % 3 + (2);
     int minusv=-(rand() % 3 + (2));
     //generate either 0 or 1
     int v=rand() % 2;
    ball->BALL_SPEED = v==0?plusv:minusv;
    ball->dy=-(rand() % 5 + (2));
    ball->resSPEED=ball->BALL_SPEED;
    //cout<<ball->dx<<endl;
    lmaker=new LevelMaker();
}//end


void PlayScreen::Update(SCREENS &mCurrentScreen,int &scorevalue,Health &health,int &level)
{

  mInput->Update();

  if(paused==true)
  {
      if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
      {
        mAudioMgr->PlaySFX("sounds/pause.wav",0,1);
        paused = false;

      }
  }else if(paused==false)
  {
      if(mInput->KeyPressed(SDL_SCANCODE_SPACE))
      {
        mAudioMgr->PlaySFX("sounds/pause.wav",0,1);
        paused = true;

      }
    padlle->Update();
    ball->Update();
  }
  //
  if(ball->collides(*ball,*padlle))
  {
   mAudioMgr->PlaySFX("sounds/paddle_hit.wav",0,1);
   //raise ball above paddle in case it goes below it, then reverse dy
    ball->y = padlle->y - ball->width;
   ball->dy = -ball->dy;
   if(ball->x<padlle->x+padlle->width/2
      &&padlle->dx<0&&padlle->ifmove)
      {
          //ball->dx=(padlle->x+padlle->width/2-ball->x)/18;
          ball->BALL_SPEED=-(ball->resSPEED+(abs(padlle->dx/2)));
          cout  <<"true"<<endl;
      }
   else if(ball->x>padlle->x+padlle->width/2
           &&padlle->dx>0&&padlle->ifmove)
   {
     ball->BALL_SPEED=(ball->resSPEED+(abs(padlle->dx/2)));
   }
   else if(!padlle->ifmove)
   {
       ball->BALL_SPEED=ball->resSPEED;
   }
  }
  //detect collision across all bricks with the ball
      for(int y=0;y<lmaker->numRows;y++)
    {
        for(int x=0;x<lmaker->numCols;x++)
        {
            if(lmaker->table[y][x].brick->inPlay&&ball->collides(*ball,*lmaker->table[y][x].brick))
            {

             //trigger the brick's hit function, which removes it from play
             lmaker->table[y][x].brick->hit();

             scorevalue+=10;
             //go to our victory screen if there are no more bricks left
             if(checkVictory())
             {
               mAudioMgr->PlaySFX("sounds/victory.wav",0,1);
               mCurrentScreen=victory;
               return;
             }
             if(ball->x+2<lmaker->table[y][x].brick->x
                   &&ball->dx>0)
                {
                 ball->BALL_SPEED=-ball->BALL_SPEED;
                 ball->x=lmaker->table[y][x].brick->x-ball->width;
                }
             else if(ball->x+6>lmaker->table[y][x].brick->x+lmaker->table[y][x].brick->width
                     &&ball->dx<0)
             {
                 ball->BALL_SPEED=-ball->BALL_SPEED;
                 ball->x=lmaker->table[y][x].brick->x+lmaker->table[y][x].brick->width;
             }
             else if(ball->y<lmaker->table[y][x].brick->y)
             {
                 ball->dy=-ball->dy;
                 ball->y=lmaker->table[y][x].brick->y-ball->width;;
             }
             else if(collidesLeftLow(*ball,*lmaker->table[y][x].brick))
                {
                   ball->y=lmaker->table[y][x].brick->y+lmaker->table[y][x].brick->hight+1;
                   ball->dy=-ball->dy;
                }
                else if(collidesRightLow(*ball,*lmaker->table[y][x].brick))
                {
                   ball->y=lmaker->table[y][x].brick->y+lmaker->table[y][x].brick->hight+1;
                   ball->dy=-ball->dy;
                }
             else
             {
              ball->dy=-ball->dy;
              ball->y=lmaker->table[y][x].brick->y+lmaker->table[y][x].brick->hight;
             }
             //
            }

        }
    }
    //if ball goes below bounds, revert to serve state and decrease health
    if(ball->y>=WINDOW_HEIGHT)
    {
     health.health--;
     mAudioMgr->PlaySFX("sounds/hurt.wav",0,1);
     if(health.health==0)
     {
         mCurrentScreen=game_over;
     }
     else
     {

         mCurrentScreen=serve;
     }

     return;
    }

}
void PlayScreen::Render()
{
 if(paused==true)
 pause->Render();
 padlle->Render();
 ball->Render();
 for(int y=0;y<lmaker->numRows;y++)
 {
     for(int x=0;x<lmaker->numCols;x++)
     {
         lmaker->table[y][x].brick->Render();
//         if(lmaker->table[y][x].brick->renderParticle)
//         {
//          lmaker->table[y][x].brick->renderParticles()   ;
//         }
     }
 }
//
 for(int y=0;y<lmaker->numRows;y++)
 {
     for(int x=0;x<lmaker->numCols;x++)
     {

         if(lmaker->table[y][x].brick->renderParticle)
         {
          lmaker->table[y][x].brick->renderParticles()   ;
         }
     }
 }
}
PlayScreen::~PlayScreen()
{
//    //dtor
    mInput=NULL;
    AudioManager::Release();
    mAudioMgr = NULL;
    delete padlle;
    padlle=NULL;
    delete ball;
    ball=NULL;
}
void PlayScreen::clearScreen()
{

//    AudioManager::Release();
//    mAudioMgr = NULL;
//    mInput=NULL;
delete lmaker;
lmaker=NULL;
lmaker=new LevelMaker();
}
//
bool PlayScreen::checkVictory()
{
  for(int y=0;y<lmaker->numRows;y++)
 {
     for(int x=0;x<lmaker->numCols;x++)
     {

         if(lmaker->table[y][x].brick->inPlay)
         {
          return false  ;
         }
     }
 } //end for
 return true;
}
