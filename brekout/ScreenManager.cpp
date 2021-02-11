#include "ScreenManager.h"
ScreenManager*ScreenManager::sInstance=NULL;
ScreenManager*ScreenManager::Instance()
{
  if(sInstance==NULL)
  {
      sInstance=new ScreenManager();
  }
  return sInstance;
}
void ScreenManager::Release()
{
    delete sInstance;
    sInstance = NULL;
}//
void ScreenManager::Update()
{

 switch(mCurrentScreen)
 {
 case start:
    mStartScreen->Update(mCurrentScreen);


    break;
 case play:


    if(mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
    {
      mCurrentScreen=start;


    }
    mPlayScreen->Update(mCurrentScreen,scoreValue,*health,level);
    break;
// case score:

   // break;
 case serve:
    mServeScreen->Update(mCurrentScreen,*mPlayScreen);
    break;
 case game_over:
    mGameOverScreen->Update(mCurrentScreen,*mPlayScreen,scoreValue,*health,level,mHighScores,highScoreIndex);

    break;
 case victory:
    mVictoryScreen->Update(mCurrentScreen,scoreValue,*mPlayScreen,*health,level);
    break;
 case high_scores:
    mHighScoreScreen->Update(mCurrentScreen,mHighScores);
    break;
 case enter_high_score:
    mEnterHighScoreScreen->Update(mCurrentScreen,mHighScores,highScoreIndex,scoreValue);
    break;
 case paddle_select:
    mPaddleSelectScreen->Update(mCurrentScreen,*mPlayScreen);
    break;
 }
}//

void ScreenManager::Render()
{
 background->Render();
 //

 switch(mCurrentScreen)
 {
 case start:

    mStartScreen->Render();
    if(prevscore!=scoreValue)
     {
         prevscore=scoreValue;
         scoreText.str( "" );
         scoreText << "Score:   " << scoreValue;
         mscore->SetText(scoreText.str().c_str(),{255, 255, 255});

     }
    break;
 case play:
   health->Render();
   mPlayScreen->Render();
    if(prevscore!=scoreValue)
     {
         prevscore=scoreValue;
         scoreText.str( "" );
         scoreText << "Score:   " << scoreValue;
         mscore->SetText(scoreText.str().c_str(),{255, 255, 255});

     }
   mscore->Render();
    break;
 case serve:
   health->Render();
   mServeScreen->Render(*mPlayScreen);
   mscore->Render();
    break;
 case game_over:
  mGameOverScreen->Render();
    break;
 case victory:
    health->Render();
    mscore->Render();
    mVictoryScreen->Render(*mPlayScreen);
    break;
 case high_scores:
    mHighScoreScreen->Render();
    break;
    case enter_high_score:
    mEnterHighScoreScreen->Render();
    break;
    case paddle_select:
       mPaddleSelectScreen->Render(*mPlayScreen);
        break;

 }
}
ScreenManager::ScreenManager()
{
    //ctor
    mInput=InputManager::Instance();
    mAudioMgr = AudioManager::Instance();
    mStartScreen=new StartScreen();
    mPlayScreen=new PlayScreen();
    mServeScreen=new ServeScreen();
    mGameOverScreen=new GameOverScreen();
    mVictoryScreen=new VictoryScreen();
    mHighScoreScreen=new HighScoreScreen();
    mEnterHighScoreScreen=new EnterHighScoreScreen();
    mPaddleSelectScreen=new PaddleSelectScreen();
    health=new Health();
    mCurrentScreen=start;
    //mCurrentScreen=enter_high_score;
    //mCurrentScreen=game_over;
    //mCurrentScreen=paddle_select;
    background=new Background();
    //padlle=new Paddle();
    mscore=new Texture("fonts/font.ttf","Score",8*3,{255,255,255});
    mscore->SetXY(WINDOW_WIDTH - 60*3,
                    5*3);
    WriteToFile();
    Readfromfile();
}

ScreenManager::~ScreenManager()
{
    //dtor
    mInput=NULL;
    delete mStartScreen;
    mStartScreen=NULL;
    delete mPlayScreen;
    mPlayScreen=NULL;
    delete mServeScreen;
    mServeScreen=NULL;
    delete health;
    health=NULL;
    delete mscore;
    mscore=NULL;
    delete mGameOverScreen;
    mGameOverScreen=NULL;
    delete mVictoryScreen;
    mVictoryScreen=NULL;
    delete mHighScoreScreen;
    mHighScoreScreen=NULL;
    delete mEnterHighScoreScreen;
    mEnterHighScoreScreen=NULL;
    delete mPaddleSelectScreen;
    mPaddleSelectScreen=NULL;
}
void ScreenManager::Readfromfile()
{
//    string line;
//    int i=0;
//  ifstream myfile ("Names.txt");
//  if (myfile.is_open())
//  {
//    while ( getline (myfile,line) )
//    {
//      mHighScores[i].name=line;//strdup(line.c_str());
//      cout << mHighScores[i].name << '\n';
//     i++;
//    }
//    myfile.close();
//  }
//
//  else cout << "Unable to open file";
//
    std::ifstream fin("Names.txt");
    if (!fin) {std::cerr<<"error\n"; return ;}
    int i=0;
    std::string line;
    while (std::getline(fin, line)) {

        std::istringstream iss(line);
        iss >> mHighScores[i].name  >> mHighScores[i].score ;

        if (iss) {
            // use mHighScores[i].name,mHighScores[i].score
            //std::cout<< mHighScores[i].name <<' '<< mHighScores[i].score <<'\n';
        }
        i++;
    }//end while
}
void ScreenManager::WriteToFile()
{
  ofstream myfile1;
  myfile1.open ("Names.txt");
  for(int i=10;i>=1;i--)
  {
    myfile1 << "CTO ";
    myfile1 << i*1000;
    myfile1 << "\n";
  }

  myfile1.close();
}
