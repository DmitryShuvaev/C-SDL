#include "Score.h"

Score::Score()
{
    //ctor

   init();
}
Score::Score(int scorev)
{
    //mInput=InputManager::Instance();
  init();
  score->SetText(conveText(std::to_string(scorev)));
}
void Score::init()
{
        mInput=InputManager::Instance();
      title=new Texture("flappy.ttf","Oof! You lost!",28*ic,color[0]);
    score=new Texture("flappy.ttf","Score",14*ic,color[0]);
    presEnt=new Texture("flappy.ttf","Press Enter to Play Again!",14*ic,color[0]);
    title->SetXY(title->mGraphics->SCREEN_WIDTH/2 - title->mWidth/2,64*ic);
    presEnt->SetXY(presEnt->mGraphics->SCREEN_WIDTH/2 - presEnt->mWidth/2,160*ic);
    score->SetXY(score->mGraphics->SCREEN_WIDTH/2 - score->mWidth/2,100*ic);
}
Score::~Score()
{
    //dtor
    delete title;
    title=NULL;
    delete score;
    score=NULL;
    delete presEnt;
    presEnt=NULL;
    mInput=NULL;
}
 char* Score::conveText(std::string scoreStr)
{
 std::string str="Score: "+scoreStr;
//char* char_type = new char[str.length()];
//strcpy(char_type, str.c_str());
////delete char_type;
char*char_type= &str[0];
return char_type;
}//end
void Score::SetTextValue(int &scorev)
{
  score->SetText(conveText(std::to_string(scorev)));
}
void Score::Update(SCREENS &mCurrentScreen,int &scorev)
{
    mInput->Update();
    if(ifUpdate){
    score->SetText(conveText(std::to_string(scorev)));
    ifUpdate=false;
    }
    if(mInput->KeyPressed(SDL_SCANCODE_KP_ENTER))
    {
               //cout<<"enter"<<endl;
     mCurrentScreen=CountdownState;
     scorev=0;
    }
}//end
void Score::Update(SCREENS &mCurrentScreen)
{
    mInput->Update();
    //score->SetText(conveText(std::to_string(scorev)));
    if(mInput->KeyPressed(SDL_SCANCODE_KP_ENTER))
    {
               //cout<<"enter"<<endl;
     mCurrentScreen=play;

    }
}//end
void Score::Render()
{
 title->Render();
 presEnt->Render();
 score->Render();
}
