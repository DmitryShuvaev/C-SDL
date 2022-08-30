#include "Room.h"

Room::Room()
{
    //ctor
    init();
}


void Room::init()
{
//    mInput=InputManager::Instance();
 mAudioMgr = AudioManager::Instance();

 maintexture=new Texture("tilesheet.png");
 make_coners();
 make_left_wall();
 make_right_wall();
 make_top_wall();
 make_low_wall();
 make_floor();
 make_wall_coliders();
 door=new Door();
 door->make_door();
 lowDoor=new Door();
 lowDoor->make_low_door();
 leftDoor=new Door();
 leftDoor->make_left_door();
 rightDoor=new Door();
 rightDoor->make_right_door();
    colider.x=WINDOW_WIDTH/2;
    colider.y=WINDOW_HEIGHT-220;
    colider.w=100;
    colider.h=50;
    //
    coliderLowWall.x=WINDOW_WIDTH/2;
    coliderLowWall.y=WINDOW_HEIGHT-60;
    coliderLowWall.w=100;
    coliderLowWall.h=70;
    //
    coliderUp.x=WINDOW_WIDTH/2;
    coliderUp.y=210-20;
    coliderUp.w=100;
    coliderUp.h=50;
    //
    coliderUpWall.x=WINDOW_WIDTH/2;
    coliderUpWall.y=-100;
    coliderUpWall.w=100;
    coliderUpWall.h=170;
    //left colider
    coliderLeft.x=(WINDOW_WIDTH-4*tilesize)-18;
    coliderLeft.y=WINDOW_HEIGHT/2-(45);;
    coliderLeft.w=50;
    coliderLeft.h=100;
    //left wall trans colider
    coliderLeftWall.x=-(75);
    coliderLeftWall.y=WINDOW_HEIGHT/2-(45);;
    coliderLeftWall.w=130;
    coliderLeftWall.h=100;
    //right colider
    coliderRight.x=(4*tilesize)-18;
    coliderRight.y=WINDOW_HEIGHT/2-(45);;
    coliderRight.w=50;
    coliderRight.h=100;
    //right wall trans colider
    coliderRightWall.x=WINDOW_WIDTH-(75);
    coliderRightWall.y=WINDOW_HEIGHT/2-(45);;
    coliderRightWall.w=130;
    coliderRightWall.h=100;
    //entity
    make_entities();
    make_door_switch();

}//end init

char* Room::conveText(std::string scoreStr)
{
std::string str="Score: "+scoreStr;
char*char_str= strdup(str.c_str());

return char_str;
}//end
void Room::make_coners()
{
    topleftSpriteClip.x=48;
    topleftSpriteClip.y=0;
    topleftSpriteClip.w=16;
    topleftSpriteClip.h=16;
    //
    toprightSpriteClip.x=64;
    toprightSpriteClip.y=0;
    toprightSpriteClip.w=16;
    toprightSpriteClip.h=16;
    //
    lowleftSpriteClip.x=48;
    lowleftSpriteClip.y=16;
    lowleftSpriteClip.w=16;
    lowleftSpriteClip.h=16;
    //
    lowrightSpriteClip.x=64;
    lowrightSpriteClip.y=16;
    lowrightSpriteClip.w=16;
    lowrightSpriteClip.h=16;

    topleftxypos.x=tilesize;
    topleftxypos.y=y_from_top;

    toprightxypos.x=SCREEN_WIDTH-tilesize*2;
    toprightxypos.y=y_from_top;

    lowleftxypos.x=tilesize;
    lowleftxypos.y=SCREEN_HEIGHT-tilesize*2;

    lowrightxypos.x=SCREEN_WIDTH-tilesize*2;
    lowrightxypos.y=SCREEN_HEIGHT-tilesize*2;
}
void Room::make_left_wall()
{
 leftWall[0].x=0,leftWall[0].y=64;
 leftWall[1].x=0,leftWall[1].y=80;
 leftWall[2].x=0,leftWall[2].y=96;
 for(int i =0;i<10;i++)
 {
  leftWallClip[i].w=16,leftWallClip[i].h=16;
  //rand range 0 to 2
  leftWallClip[i].x=leftWall[rand() % 3].x,leftWallClip[i].y=leftWall[rand() % 3].y;
 }
 //xy pos for shifting
 for(int i=0;i<10;i++)
 {
  leftWallxypos[i].x=tilesize, leftWallxypos[i].y=y_from_top+tilesize*(i+1);
 }

}
void Room::make_right_wall()
{
 rightWall[0].x=16,rightWall[0].y=64;
 rightWall[1].x=16,rightWall[1].y=80;
 rightWall[2].x=16,rightWall[2].y=96;
  for(int i =0;i<10;i++)
 {
  rightWallClip[i].w=16,rightWallClip[i].h=16;
  //rand range 0 to 2
  rightWallClip[i].x=rightWall[rand() % 3].x,rightWallClip[i].y=rightWall[rand() % 3].y;
 }
   for(int y=0;y<10;y++)
 {
  rightWallxypos[y].x=SCREEN_WIDTH-tilesize*2, rightWallxypos[y].y=y_from_top+tilesize*(y+1);
 }
}
void Room::make_top_wall()
{
 topWall[0].x=0,topWall[0].y=48;
 topWall[1].x=16,topWall[1].y=48;
 topWall[2].x=32,topWall[2].y=48;
   for(int i =0;i<22;i++)
 {
  topWallClip[i].w=16,topWallClip[i].h=16;
  //rand range 0 to 2
  topWallClip[i].x=topWall[rand() % 3].x,topWallClip[i].y=topWall[rand() % 3].y;
 }
 //pos for shifting
 int startposx=tilesize*2;
   for(int x=0;x<22;x++)
 {
  topWallxypos[x].x=startposx+(tilesize*(x));
  topWallxypos[x].y=y_from_top;
 }
}
void Room::make_low_wall()
{
 lowWall[0].x=32,lowWall[0].y=64;
 lowWall[1].x=48,lowWall[1].y=64;
 lowWall[2].x=64,lowWall[2].y=64;
 for(int i =0;i<22;i++)
 {
  lowWallClip[i].w=16,lowWallClip[i].h=16;
  //rand range 0 to 2
  lowWallClip[i].x=lowWall[rand() % 3].x,lowWallClip[i].y=lowWall[rand() % 3].y;
 }
  //posxy for shifting
   int startposx=tilesize*2;
  int y_top=SCREEN_HEIGHT-tilesize*2;
   for(int x=0;x<22;x++)
 {
  lowWallxypos[x].x=startposx+(tilesize*(x));
  lowWallxypos[x].y=y_top;
 }
}
void Room::make_floor()
{
 int i=0;
 for(int x=96;x<208;x=x+16)
 {

  for(int y=0;y<=48;y+=16)
  {
   floor[i].x=x,floor[i].y=y;
   i++;
  }

 }
  for(int x=176;x<208;x+=16)
 {

  for(int y=64;y<=80;y+=16)
  {
   floor[i].x=x,floor[i].y=y;
   i++;
  }
 }
      for(int v=0;v<220;v++)
      {
       //
       floorCliprect[v].w=16,floorCliprect[v].h=16;
       i=rand() % 32;
       floorCliprect[v].x=floor[i].x,floorCliprect[v].y=floor[i].y;
      }
//posxy for render
 int startposx=tilesize*2;
 int y_top=y_from_top+tilesize;
  i=0;

 for(int x=0;x<22;x++)
 {
  for(int y=0;y<10;y++)
  {
   //maintexture->render(startposx,y_top ,&floorCliprect[i++],tilesize,tilesize);
   floorxypos[i].x=startposx;
   floorxypos[i].y=y_top;
   i++;
   y_top+=tilesize;
  }
  startposx+=tilesize;
  y_top=y_from_top+tilesize;
 }
}
void Room::render_corners()
{
 maintexture->render(topleftxypos.x, topleftxypos.y,&topleftSpriteClip,tilesize,tilesize);
 maintexture->render(toprightxypos.x, toprightxypos.y,&toprightSpriteClip,tilesize,tilesize);
 maintexture->render(lowleftxypos.x,lowleftxypos.y,&lowleftSpriteClip,tilesize,tilesize);
 maintexture->render(lowrightxypos.x,lowrightxypos.y,&lowrightSpriteClip,tilesize,tilesize);
}
void Room::render_left_wall()
{
  for(int y=0;y<10;y++)
 {
  maintexture->render(leftWallxypos[y].x, leftWallxypos[y].y,&leftWallClip[y],tilesize,tilesize);
 }
}
void Room::render_right_wall()
{
  for(int y=0;y<10;y++)
 {
  maintexture->render(rightWallxypos[y].x, rightWallxypos[y].y,&rightWallClip[y],tilesize,tilesize);
 }
}
void Room::render_top_wall()
{
   for(int i=0;i<22;i++)
 {
  maintexture->render(topWallxypos[i].x, topWallxypos[i].y,&topWallClip[i],tilesize,tilesize);
 }
}
void Room::render_low_wall()
{

 for(int x=0;x<22;x++)
 {
  maintexture->render(lowWallxypos[x].x,lowWallxypos[x].y ,&lowWallClip[x],tilesize,tilesize);
 }
}
void Room::render_floor()
{

for(int i=0;i<220;i++)
{
 maintexture->render(floorxypos[i].x,floorxypos[i].y ,&floorCliprect[i],tilesize,tilesize);
}
}
void Room::render_switch()
{
switch_texture->render(switch_x,switch_y,&door_switch,tilesize,tilesize);
 //switch_texture->mGraphics->draw_rect(door_switch_colider);
}
void Room::Update(SCREENS &mCurrentScreen,Player*player)
{

   //mInput->UpdatePrevInput();
//   mInput->Update();

}
void Room::Render()
{
 //
 render_floor();
 render_left_wall();
 render_right_wall();
 render_top_wall();
 render_low_wall();
 door-> render_door(maintexture);
 lowDoor-> render_door(maintexture);
 leftDoor->render_left_door(maintexture);
 rightDoor->render_left_door(maintexture);
 render_corners();
 //maintexture->mGraphics->draw_rect(colider);
 render_switch();
 for(int i=0;i<10;i++)
 {

   if(entities[i]->alive)
  {
   enemy->render( entities[i]->x, entities[i]->y, &entities[i]->gSpriteClip,entities[i]->width,entities[i]->hight );
   //enemy->mGraphics->draw_rect(entities[i]->hurtbox);
  }
 }

 //entities->Render();
 //maintexture->mGraphics->draw_rect(coliderLowWall);
 //maintexture->mGraphics->draw_rect(coliderUp);
 //maintexture->mGraphics->draw_rect(coliderUpWall);
 //maintexture->mGraphics->draw_rect(coliderLeft);
 //maintexture->mGraphics->draw_rect(coliderLeftWall);
 /*
 maintexture->mGraphics->draw_rect(coliderRight);
 maintexture->mGraphics->draw_rect(coliderRightWall);
 maintexture->mGraphics->draw_rect(colidertopWall);
 maintexture->mGraphics->draw_rect(coliderlowWall);
 maintexture->mGraphics->draw_rect(coliderleftWall);
 maintexture->mGraphics->draw_rect(coliderrightWall);
 */
 //topleft
 //maintexture->mGraphics->draw_rect(topleft);
}
void Room::set_pos(int valuey)
{
     for(int i=0;i<22;i++)
     {
      lowWallxypos[i].y+=valuey;
      topWallxypos[i].y+=valuey;
     }
     //shifting floors
     for(int i=0;i<220;i++)
     {
      floorxypos[i].y+=valuey;

     }
     for(int i=0;i<10;i++)
     {
      leftWallxypos[i].y+=valuey;
      rightWallxypos[i].y+=valuey;
     }
     topleftxypos.y+=valuey;
     toprightxypos.y+=valuey;
     lowleftxypos.y+=valuey;
     lowrightxypos.y+=valuey;
     door->y+=valuey;
     lowDoor->y+=valuey;
     colider.y+=valuey;
     coliderLowWall.y+=valuey;
     coliderUp.y+=valuey;
     coliderUpWall.y+=valuey;
     leftDoor->y+=valuey;
     leftDoor->colider.y+=valuey;
     rightDoor->y+=valuey;
     coliderRight.y+=valuey;
     coliderRightWall.y+=valuey;
     for(int i=0;i<10;i++)
     {
      entities[i]->y+=valuey;
     }
     switch_y+=valuey;
     door_switch_colider.y+=valuey;
}
void Room::set_pos_x(int valuex)
{
     for(int i=0;i<22;i++)
     {
      lowWallxypos[i].x+=valuex;
      topWallxypos[i].x+=valuex;
     }
     //shifting floors
     for(int i=0;i<220;i++)
     {
      floorxypos[i].x+=valuex;

     }
     for(int i=0;i<10;i++)
     {
      leftWallxypos[i].x+=valuex;
      rightWallxypos[i].x+=valuex;
     }
     topleftxypos.x+=valuex;
     toprightxypos.x+=valuex;
     lowleftxypos.x+=valuex;
     lowrightxypos.x+=valuex;
     door->x+=valuex;
     lowDoor->x+=valuex;
     colider.x+=valuex;
     coliderLowWall.x+=valuex;
     coliderUp.x+=valuex;
     coliderUpWall.x+=valuex;
     leftDoor->x+=valuex;
     leftDoor->colider.x+=valuex;
     coliderLeft.x+=valuex;
     coliderLeftWall.x+=valuex;
     rightDoor->x+=valuex;
     coliderRight.x+=valuex;
     coliderRightWall.x+=valuex;
     for(int i=0;i<10;i++)
     {
      entities[i]->x+=valuex;
     }
     switch_x+=valuex;
     door_switch_colider.x+=valuex;
}
Room::~Room()
{
    //dtor

//    AudioManager::Release();
//    mAudioMgr = NULL;
delete maintexture;
maintexture=NULL;
if(enemy!=NULL)delete enemy;
delete switch_texture;
switch_texture=NULL;
}
void Room::make_wall_coliders()
{
     //colider top wall
    colidertopWall.x=tilesize;
    colidertopWall.y=y_from_top;
    colidertopWall.w=SCREEN_WIDTH-tilesize*2;
    colidertopWall.h=tilesize;
    //colider low wall
    coliderlowWall.x=tilesize;
    coliderlowWall.y=(SCREEN_HEIGHT-tilesize*2)+5;
    coliderlowWall.w=SCREEN_WIDTH-tilesize*2;
    coliderlowWall.h=tilesize;
    //colider left wall
    coliderleftWall.x=tilesize;
    coliderleftWall.y=y_from_top;
    coliderleftWall.w=tilesize-5;
    coliderleftWall.h=(SCREEN_HEIGHT-tilesize*2)-15;
    //colider right wall
    coliderrightWall.x=(SCREEN_WIDTH-tilesize*2)+5;
    coliderrightWall.y=y_from_top;
    coliderrightWall.w=tilesize-5;
    coliderrightWall.h=(SCREEN_HEIGHT-tilesize*2)-15;
}
void Room::make_entities()
{
    enemy=new Texture("graphics/entities.png");
    int minx=2*tilesize;
    int miny=y_from_top+tilesize;
    int maxx=WINDOW_WIDTH-(3*50);
    int maxy=WINDOW_HEIGHT-(3*50);
    int xv,yv;
    for(int i=0;i<10;i++)
    {
    entities[i]=new Entity();//width 15,height 11
    entities[i]->id=i;
    entities[i]->make_clip_array(randomvalue(4,0));
    int rand_dir=randomvalue(4,1);

    if(rand_dir==1)entities[i]->dir=DIRECTIONS::left;
    else if(rand_dir==2)entities[i]->dir=DIRECTIONS::up;
    else if(rand_dir==3)entities[i]->dir=DIRECTIONS::right;
    else if(rand_dir==4)entities[i]->dir=DIRECTIONS::down;
     xv=randomvalue(maxx,minx);
     yv=randomvalue(maxy,miny);

    entities[i]->x=xv;
    entities[i]->y=yv;
    entities[i]->hurtbox.x=entities[i]->x;
    entities[i]->hurtbox.y=entities[i]->y;


    entities[i]->setIdle();
    entities[i]->mEntityState=EntityWalk;
    }
        for(int i=0;i<10;i++)
        while(entities[i]->colide_with_other_entities(*entities[i],entities))
    {
    xv=randomvalue(maxx,minx);
    yv=randomvalue(maxy,miny);
    entities[i]->x=xv;
    entities[i]->y=yv;
    entities[i]->hurtbox.x=entities[i]->x;
    entities[i]->hurtbox.y=entities[i]->y;
    }


}
int Room::randomvalue(int max,int min)
{
	int range = max-min + 1;
	int random= rand()%range + min;
	return random;
}
void Room::make_door_switch()
{
    switch_texture=new Texture("graphics/switches.png");
    int minx=2*tilesize;
    int miny=y_from_top+tilesize;
    int maxx=WINDOW_WIDTH-(3*50);
    int maxy=WINDOW_HEIGHT-(3*50);
    int rand_pos_x=randomvalue(maxx,minx);
    int rand_pos_y=randomvalue(maxy,miny);
    switch_x=rand_pos_x;
    switch_y=rand_pos_y;
    door_switch.x=16;
    door_switch.y=0;
    door_switch.w=16;
    door_switch.h=16;
    //colider with switch
    door_switch_colider.x=switch_x;
    door_switch_colider.y=switch_y;
    door_switch_colider.w=tilesize;
    door_switch_colider.h=tilesize;
    sw_state=unpressed;
}
void Room::switch_onCollide (Player*player)
{
 if(sw_state==unpressed)
 {

 if(AABB(player->rect,door_switch_colider))
    {
    sw_state=pressed;
    door->open=true;
    lowDoor->open=true;
    leftDoor->open=true;
    rightDoor->open=true;
    make_open_door_switch();
    rightDoor->open_right_door();
    leftDoor->open_left_door();
    door->open_up_door();
    lowDoor->open_low_door();
    mAudioMgr->PlaySFX("sounds/door.wav",0,2);
    }
 }else
 {
   if(!AABB(player->rect,door_switch_colider))
    {
     //sw_state=unpressed;
     //if(sw_state==unpressed)sw_state=pressed;
     //cout<<"opened"<<endl;
    }
 }
 //open all doors
}
void Room::make_open_door_switch()
{
    door_switch.x=0;
    door_switch.y=0;
}

