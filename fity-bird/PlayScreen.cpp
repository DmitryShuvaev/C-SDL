#include "PlayScreen.h"

#include "StartScreen.h"

PlayScreen::PlayScreen()
{
    //ctor

init();
//pipes.emplace_back(std::make_unique<Tube>());
}//end
void PlayScreen::init()
{
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
//score text

//std::string scoreStr=std::to_string(scoreValue);
//char* char_type = new char[scoreStr.length()];
//strcpy(char_type, scoreStr.c_str());
scoreTex=new Texture("flappy.ttf",conveText(std::to_string(scoreValue)),28*ic,color[0]);
scoreTex->SetXY(8*ic,
                8*ic);
//
bird=new Bird();


pipes.emplace_back(std::make_unique<Tube>());
}//end init

char* PlayScreen::conveText(std::string scoreStr)
{
std::string str="Score: "+scoreStr;
//char char_type[str.length()+1];
//strcpy(char_type, str.c_str());
char*char_str= strdup(str.c_str());

//delete [] char_type;
return char_str;
}//end

void PlayScreen:: drawMenuTex(SDL_Surface* menu,SDL_Rect &p)
{

}//

void PlayScreen::Update(SCREENS &mCurrentScreen,int &scorevalue,bool &scrolling)
{

   //mInput->UpdatePrevInput();
   mInput->Update();
   spawnTimer=spawnTimer+0.01;
if(spawnTimer>2)
{
    //add new pipe
   // cout<<spawnTimer<<endl;
   pipes.emplace_back(std::make_unique<Tube>());
   spawnTimer=0;
}
for (auto &pipe: pipes)
{
  pipe->Update();
}
for (auto &pipe: pipes)
{
  if(bird->collides(*pipe))
  {
     // return ;

     scrolling=false;
     mCurrentScreen=score;
     mAudioMgr->PlaySFX("explosion.wav",0,1);
     mAudioMgr->PlaySFX("hurt.wav",0,2);
     ClearScreen();

     cout<<""<<mCurrentScreen<<endl;
     return;
  }
        // score a point if the pipe has gone past the bird to the left all the way
        // be sure to ignore it if it's already been scored
            if(!pipe->scored){
              if (pipe->x + pipe->PIPE_WIDTH < bird->bird->mRenderRect.x){
                scoreValue= scoreValue+ 1;
                scorevalue=scoreValue;
                pipe->scored = true;
                scoreTex->SetText(conveText(std::to_string(scoreValue)));
                mAudioMgr->PlaySFX("score.wav",0,3);
                }
            }
}
  for (auto iter = std::begin(pipes); iter != std::end(pipes); )
  {
    if ((*iter)->lower->mRenderRect.x < -128)
    {
     iter = pipes.erase(iter);
     //cout<<"erased "<<pipes.size()<<endl;
    }

    else
      ++iter;
  }


bird->Update();
if(bird->bird->mRenderRect.y>bird->bird->mGraphics->SCREEN_HEIGHT)
{

     scrolling=false;
     mCurrentScreen=score;
      mAudioMgr->PlaySFX("explosion.wav",0,1);
      mAudioMgr->PlaySFX("hurt.wav",0,2);
     ClearScreen();

     //cout<<""<<mCurrentScreen<<endl;
     return;
}

}
void PlayScreen::Render()
{


    for (auto &pipe: pipes)
    {
     pipe->Render();
    }
    bird->Render();
    scoreTex->Render();
}
PlayScreen::~PlayScreen()
{
    //dtor
    delete bird;
    bird=NULL;
    AudioManager::Release();
    mAudioMgr = NULL;
}
void PlayScreen::ClearScreen()
{
   spawnTimer=0;
//   backgroundScroll=0;
//   groundScroll=0;
   scoreValue=0;
   pipes.clear();
    delete bird;
    bird=NULL;
    AudioManager::Release();
    mAudioMgr = NULL;
    mInput=NULL;
    init();
}
