#include "PlayScreen.h"

#include "StartScreen.h"

PlayScreen::PlayScreen()
{
    //ctor
 if(mInput==NULL)
 mInput=InputManager::Instance();
 mAudioMgr = AudioManager::Instance();
  mAudioMgr->PlaySFX("sounds/music.mp3",-1);
 init();
}//end
void PlayScreen::make_player()
{
    player=new Player(0,6,16,22);
    player->x=WINDOW_WIDTH / 2 - (player->width / 2);
    player->y=WINDOW_HEIGHT/2-(player->hight / 2);
    player->lefthitbox.x=player->x-player->hitboxWidth;
    player->lefthitbox.y=player->y+10;
    player->righthitbox.x=player->x+player->width;
    player->righthitbox.y=player->y+10;

}
void PlayScreen::init()
{

    dungeon=new Dungeon();
    dungeon->init();
    mAnimation=new Animation();
    mAnimation->count=1;

    make_player();
    make_hearts();

}
void PlayScreen::Update(SCREENS &mCurrentScreen)
{
//
//   //mInput->UpdatePrevInput();
   if(mInput!=NULL)
   mInput->Update();
   if(player!=NULL)
   {
   player->Update();
   if(player->health<=0)
   {mCurrentScreen=GameOver;
    ClearScreen();
    init();

   }
   }
}
void PlayScreen::Render()
{
 if(dungeon!=NULL)
 dungeon->Render();
 if(heart!=NULL)
 render_hearts();
 if(player!=NULL)
 player->Render();
}
PlayScreen::~PlayScreen()
{
//    //dtor
    delete mAnimation;
    AudioManager::Release();
    mAudioMgr = NULL;
    mInput=NULL;
    delete player;
    delete heart;
    delete dungeon;
}
void PlayScreen::moveLeft_Right(int positionx)
{
 player->x+=positionx;

}
void PlayScreen::moveUp_Down(int positiony)
{
 player->y+=positiony;

}
void PlayScreen::ClearScreen()
{
    delete mAnimation;
    //AudioManager::Release();
    //mAudioMgr = NULL;
//InputManager::Release();
    //mInput=NULL;

    delete heart;
    delete dungeon;
    delete player;
}

void PlayScreen::make_hearts()
{
    heart=new Texture("graphics/hearts.png");
for(int i=0;i<3;i++)hearts[i]=new Heart_obj();
    for(int i=0, i2=2;i<3;i++,i2+=4)
    {

    hearts[i]->x=i*50+i2;
    hearts[i]->y=8;
    hearts[i]->heart_rect.x=64;
    hearts[i]->heart_rect.y=0;
    hearts[i]->heart_rect.w=16;
    hearts[i]->heart_rect.h=16;
    }
    //
}
void PlayScreen::render_hearts()
{
    //    for i = 1, 3 do
//        if healthLeft > 1 then
//            heartFrame = 5
//        elseif healthLeft == 1 then
//            heartFrame = 3
//        else
//            heartFrame = 1
//        end
    for(int i=0;i<3;i++)
    {
    heart->render( hearts[i]->x, hearts[i]->y, &hearts[i]->heart_rect,50,50 );
    }
}
void PlayScreen::update_hearts(Player&player,Entity&entity)
{
     if(entity.alive)
     {
     if(AABB(player.rect,entity.hurtbox))
     {
       player.is_hit=true;

        if(entity.hited_player==false)
         {
             entity.hited_player=true;
             player.health--;
             set_hearts(player);

             mAudioMgr->PlaySFX("sounds/hit_player.wav",0,3);
         }
     }else
     {
         if(entity.hited_player==true)
         {
           //player.is_hit=true;
           //cout<<"colsi"<<endl;
          entity.hited_player=false;
         }
     }
     }
}
void PlayScreen::set_hearts(Player&player)
{
  if(player.health==5)
  {
    hearts[2]->heart_rect.x=32;
  }
  else if(player.health==4)
  {
   hearts[2]->heart_rect.x=0;
  }
  else if(player.health==3)
  {
   hearts[1]->heart_rect.x=32;
  }
  else if(player.health==2)
  {
   hearts[1]->heart_rect.x=0;
  }
  else if(player.health==1)
  {
   hearts[0]->heart_rect.x=32;
  }
  else if(player.health<=0)
  {
   hearts[0]->heart_rect.x=0;
  }
}
