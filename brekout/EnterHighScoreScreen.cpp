#include "EnterHighScoreScreen.h"

EnterHighScoreScreen::EnterHighScoreScreen()
{
    //ctor
        mInput=InputManager::Instance();
    title=new Texture("fonts/font.ttf","Press Enter to confirm!",8*3,{255,255,255});
    title->SetXY(title->mGraphics->WINDOW_WIDTH/2 - title->mWidth/2,WINDOW_HEIGHT-18*3);
    //
    scoreText.str( "" );
    scoreText  << (char)chars[0];
    char1=new Texture("fonts/font.ttf"," ",FONT_SIZE,{255,255,255});
    char1->SetText(scoreText.str().c_str(),{255, 255, 255});
    char1->SetXY(char1->mGraphics->WINDOW_WIDTH/2 - 28*3,WINDOW_HEIGHT/2);
    //
    scoreText.str( "" );
    scoreText  << (char)chars[1];
    char2=new Texture("fonts/font.ttf"," ",FONT_SIZE,{255,255,255});
    char2->SetText(scoreText.str().c_str(),{255, 255, 255});
    char2->SetXY(char2->mGraphics->WINDOW_WIDTH/2 - 6*3,WINDOW_HEIGHT/2);
    //
    scoreText.str( "" );
    scoreText  << (char)chars[2];
    char3=new Texture("fonts/font.ttf"," ",FONT_SIZE,{255,255,255});
    char3->SetText(scoreText.str().c_str(),{255, 255, 255});
    char3->SetXY(char3->mGraphics->WINDOW_WIDTH/2 +20*3,WINDOW_HEIGHT/2);
    //yourscoreText
    yourscoreText=new Texture("fonts/font.ttf","Your score: ",16*3,{255,255,255});
    yourscoreText->SetXY(yourscoreText->mGraphics->WINDOW_WIDTH/2 - yourscoreText->mWidth/2,30*3);
}

EnterHighScoreScreen::~EnterHighScoreScreen()
{
    //dtor
    mInput=NULL;
    delete title;
    title=NULL;
    delete char1;
    char1=NULL;
    delete char2;
    char2=NULL;
    delete char3;
    char3=NULL;
    delete yourscoreText;
    yourscoreText=NULL;
}
void EnterHighScoreScreen::Update(SCREENS &mCurrentScreen, HighScores *mHighScores,int&highScoreIndex,int &score)
{
    mInput->Update();
          std::stringstream scorevalue;
          scorevalue.str( "" );
          scorevalue  <<"Your score: "<< score;
          yourscoreText->SetText(scorevalue.str().c_str(),{255, 255, 255});
          yourscoreText->SetXY(yourscoreText->mGraphics->WINDOW_WIDTH/2 - yourscoreText->mWidth/2,30*3);
    HighScores highScores[10];
if(mInput->KeyPressed(SDL_SCANCODE_RETURN))
{
     for(int i=0; i<10; i++)
    {
       highScores[i].name=mHighScores[i].name;
       highScores[i].score=mHighScores[i].score;
    }
    //highScores[highScoreIndex].name=mHighScores[i].name;
    std::stringstream scoreText;
         scoreText.str( "" );
         scoreText << (char)chars[0]<<(char)chars[1]<<(char)chars[2];
         highScores[highScoreIndex].name=scoreText.str().c_str();
         //score
         scoreText.str( "" );
         scoreText << score;
    highScores[highScoreIndex].score=scoreText.str().c_str();
    //cout<<highScores[highScoreIndex].name<<endl;
    //go backwards through high scores table till this score, shifting scores
    for(int i=highScoreIndex; i<9; i++)
    {
        //int intscore=std::stoi( mHighScores[i].score );
        highScores[i+1].score=mHighScores[i].score;
         //cout<<i<<endl;
    }
    for(int i=0; i<10; i++)
    {
        cout<<highScores[i].score<<endl;
    }
    //write scores to file
  ofstream scorefile;
  scorefile.open ("Names.txt");
  for(int i=0;i<10;i++)
  {
    scorefile << highScores[i].name<<" ";
    scorefile << highScores[i].score;
    scorefile << "\n";
  }
  scorefile.close();
  //
  mCurrentScreen=high_scores;
}


    //scroll through character slots
    if(mInput->KeyPressed(SDL_SCANCODE_LEFT))
    {
        ifHighlited=true;
      if(highlightedChar>0)
       highlightedChar--;
    }
    else if(mInput->KeyPressed(SDL_SCANCODE_RIGHT))
    {
        ifHighlited=true;
      if(highlightedChar<2)
       highlightedChar++;
    }
    if(mInput->KeyPressed(SDL_SCANCODE_UP))
    {
       chars[highlightedChar] = chars[highlightedChar] + 1;

       if(chars[highlightedChar] > 90)
       {
        chars[highlightedChar] = 65;
       }
    }else if(mInput->KeyPressed(SDL_SCANCODE_DOWN))
    {
       chars[highlightedChar] = chars[highlightedChar] - 1;

       if(chars[highlightedChar] <65)
       {
        chars[highlightedChar] = 90;
       }

    }
    //if(ifHighlited)
    {
        if(highlightedChar==0)
        {
          scoreText.str( "" );
          scoreText  << (char)chars[highlightedChar];
          char1->SetText(scoreText.str().c_str(),{103, 255, 255});
          //cout<<char1->text;
          char2->SetColor({255,255,255});
          char3->SetColor({255,255,255});
          ifHighlited=false;
        }
        else if(highlightedChar==1)
        {
          char1->SetColor({255,255,255});
          scoreText.str( "" );
          scoreText  << (char)chars[highlightedChar];
          char2->SetText(scoreText.str().c_str(),{103, 255, 255});
          char3->SetColor({255,255,255});
          ifHighlited=false;
        }
        else if(highlightedChar==2)
        {
          char1->SetColor({255,255,255});
          char2->SetColor({255,255,255});
          scoreText.str( "" );
          scoreText  << (char)chars[highlightedChar];
          char3->SetText(scoreText.str().c_str(),{103, 255, 255});
          ifHighlited=false;
        }
    }
}//

void EnterHighScoreScreen::Render()
{
 title->Render();
 char1->Render();
 char2->Render();
 char3->Render();
 yourscoreText->Render();
}
