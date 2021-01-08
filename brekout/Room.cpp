#include "Room.h"

Room::Room()
{
    //ctor
    init();
}


void Room::init()
{
//    mInput=InputManager::Instance();
   // mAudioMgr = AudioManager::Instance();

 ground=new Texture("tilesheet.png",48,0,16,16);
 ground->SetXY(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
 ground->mWidth=ground->mWidth*ic;
 ground->mHeight=ground->mHeight*ic;
//
topleft=new Texture("tilesheet.png",48,0,16,16);
 topleft->SetXY(tilesize,tilesize);
 topleft->mWidth=topleft->mWidth*ic;
 topleft->mHeight=topleft->mHeight*ic;
//
topright=new Texture("tilesheet.png",64,0,16,16);
 topright->SetXY(SCREEN_WIDTH-tilesize*2,tilesize);
 topright->mWidth=topright->mWidth*ic;
 topright->mHeight=topright->mHeight*ic;
//
lowleft=new Texture("tilesheet.png",48,16,16,16);
 lowleft->SetXY(tilesize,SCREEN_HEIGHT-tilesize*2);
 lowleft->mWidth=lowleft->mWidth*ic;
 lowleft->mHeight=lowleft->mHeight*ic;
//
lowright=new Texture("tilesheet.png",64,16,16,16);
 lowright->SetXY(SCREEN_WIDTH-tilesize*2,SCREEN_HEIGHT-tilesize*2);
 lowright->mWidth=lowright->mWidth*ic;
 lowright->mHeight=lowright->mHeight*ic;
 //
 for(int y=0;y<14;y++)
 {
  leftWall[y]=new Texture("tilesheet.png",0,16*5,16,16);
 leftWall[y]->SetXY(tilesize,(tilesize)*(y+2));
 leftWall[y]->mWidth=leftWall[y]->mWidth*ic;
 leftWall[y]->mHeight=leftWall[y]->mHeight*ic;
 //
  rightWall[y]=new Texture("tilesheet.png",16,16*5,16,16);
 rightWall[y]->SetXY(SCREEN_WIDTH-tilesize*2,(tilesize)*(y+2));
 rightWall[y]->mWidth=rightWall[y]->mWidth*ic;
 rightWall[y]->mHeight=rightWall[y]->mHeight*ic;
 }
  for(int x=0;x<28;x++)
 {
 topWall[x]=new Texture("tilesheet.png",0,16*3,16,16);
 topWall[x]->SetXY((tilesize)*(x+2),tilesize);
 topWall[x]->mWidth=topWall[x]->mWidth*ic;
 topWall[x]->mHeight=topWall[x]->mHeight*ic;
 //
 lowWall[x]=new Texture("tilesheet.png",16*2,16*4,16,16);
 lowWall[x]->SetXY(tilesize*(x+2),SCREEN_HEIGHT-tilesize*2);
 lowWall[x]->mWidth=lowWall[x]->mWidth*ic;
 lowWall[x]->mHeight=lowWall[x]->mHeight*ic;

 }
 //center map
  for(int y=0;y<14;y++)
 {
     for(int x =0;x<28;x++)
     {
      centerMap[y][x]=new Texture("tilesheet.png",16*6,0,16,16);
      centerMap[y][x]->SetXY(tilesize*(x+2),(tilesize)*(y+2));
      centerMap[y][x]->mWidth=centerMap[y][x]->mWidth*ic;
      centerMap[y][x]->mHeight=centerMap[y][x]->mHeight*ic;
     }
 //
 }

}//end init

char* Room::conveText(std::string scoreStr)
{
std::string str="Score: "+scoreStr;
char*char_str= strdup(str.c_str());

return char_str;
}//end



void Room::Update(SCREENS &mCurrentScreen,int &scorevalue,bool &scrolling)
{

   //mInput->UpdatePrevInput();
//   mInput->Update();

}
void Room::Render()
{
 ground->RenderClipped();
 topleft->RenderClipped();
 topright->RenderClipped();
 lowleft->RenderClipped();
 lowright->RenderClipped();
 for(int y=0;y<14;y++)
 {
  leftWall[y]->RenderClipped();
  rightWall[y]->RenderClipped();
 }
 for(int x=0;x<28;x++)
 {
     topWall[x]->RenderClipped();
     lowWall[x]->RenderClipped();
 }
 for(int y=0;y<14;y++)
 {
     for(int x =0;x<28;x++)
     {
       centerMap[y][x]->RenderClipped();
     }

 }
}
Room::~Room()
{
    //dtor

//    AudioManager::Release();
//    mAudioMgr = NULL;
 delete ground;
ground= NULL;
delete topleft;
topleft= NULL;
delete topright;
topright= NULL;
delete lowleft;
lowleft= NULL;
delete lowright;
lowright= NULL;
 for(int y=0;y<14;y++)
 {
  delete leftWall[y];
  leftWall[y]= NULL;
  delete rightWall[y];
  rightWall[y]= NULL;
 }
  for(int x=0;x<28;x++)
 {
 delete topWall[x];
 topWall[x]= NULL;
  delete lowWall[x];
 lowWall[x]= NULL;

 }
 //center map
  for(int y=0;y<14;y++)
 {
     for(int x =0;x<28;x++)
     {
    delete  centerMap[y][x];
    centerMap[y][x]= NULL;
     }
 //
 }
}
