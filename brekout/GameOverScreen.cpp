#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
    //ctor
        mInput=InputManager::Instance();
        title=new Texture("fonts/font.ttf","GAME OVER",FONT_SIZE,{255,255,255});
        title->SetXY(WINDOW_WIDTH/2- title->mWidth/2,
                    WINDOW_HEIGHT/3 );
    //
        finalScore=new Texture("fonts/font.ttf","Final Score: ",16*3,{255,255,255});
        finalScore->SetXY(WINDOW_WIDTH/2- finalScore->mWidth/2,
                    WINDOW_HEIGHT/2 );
    //
        presEnter=new Texture("fonts/font.ttf","Press Enter!",16*3,{255,255,255});
        presEnter->SetXY(WINDOW_WIDTH/2- presEnter->mWidth/2,
                    WINDOW_HEIGHT-WINDOW_HEIGHT/4 );
}

GameOverScreen::~GameOverScreen()
{
    //dtor
    delete title;
    title=NULL;
    delete finalScore;
    finalScore=NULL;
    delete presEnter;
    presEnter=NULL;
    mInput=NULL;
}
void GameOverScreen::Update(SCREENS &mCurrentScreen,PlayScreen &mPlayScreen,int &score,Health &health,int&level,HighScores *mHighScores,int&highScoreIndex)
{
     mInput->Update();
         scoreText.str( "" );
         scoreText << "Final Score: " << score;
         finalScore->SetText(scoreText.str().c_str(),{255, 255, 255});
         finalScore->SetXY(WINDOW_WIDTH/2- finalScore->mWidth/2,
                           WINDOW_HEIGHT/2 );
    level=1;
// if(mInput->KeyPressed(SDL_SCANCODE_RETURN))
// {
//   mCurrentScreen=start;
//   mPlayScreen.clearScreen();
//   score=0;
//   health.health=3;
// }
 if(mInput->KeyPressed(SDL_SCANCODE_RETURN))
 {


 bool highScore = false;
     //keep track of what high score ours overwrites, if any
    // int scoreIndex = 11;
    //cout<<mHighScores[1].score<<endl;
    for(int i=9; i>0; i--)
    {
        int intscore=std::stoi( mHighScores[i].score );
        //cout<<a<<endl;
        if(score>intscore)
        {
         highScoreIndex = i;
         highScore = true;
         //cout<<i<<endl;
         //break;
        }
    }
    //
    cout<<mHighScores[highScoreIndex].score<<endl;
    if(highScore)
    {
      mPlayScreen.clearScreen();
      //score=0;
      health.health=3;
      mCurrentScreen=enter_high_score;
    }
    else
    {
      mCurrentScreen=start;
    }
 }
}
void GameOverScreen::Render()
{
 title->Render();
 finalScore->Render();
 presEnter->Render();
}
