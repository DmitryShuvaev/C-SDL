#include "HighScoreScreen.h"

HighScoreScreen::HighScoreScreen()
{
    //ctor
    mInput=InputManager::Instance();
    title=new Texture("fonts/font.ttf","High Scores",FONT_SIZE,{255,255,255});
    title->SetXY(title->mGraphics->WINDOW_WIDTH/2 - title->mWidth/2,
                    20*3);
    //
    lowtitle=new Texture("fonts/font.ttf","Press Escape to return to the main menu!",8*3,{255,255,255});
    lowtitle->SetXY(lowtitle->mGraphics->WINDOW_WIDTH/2 - lowtitle->mWidth/2,WINDOW_HEIGHT-18*3);
    for (int i=0; i<10; i++)
    {
     stringstream ss;
     ss << i+1<<".";
     this->mindex[i]=new Texture("fonts/font.ttf","0",16*3,{255,255,255});
     this->mindex[i]->SetXY(WINDOW_WIDTH/4,180 + (i+1) * 39);
     this->mindex[i]->SetText(ss.str(),{255,255,255});
     //
     this->mNames[i]=new Texture("fonts/font.ttf","0",16*3,{255,255,255});
     this->mNames[i]->SetXY(WINDOW_WIDTH/4+190,180 + (i+1) * 39);
     //
     this->mScores[i]=new Texture("fonts/font.ttf","0",16*3,{255,255,255});
     this->mScores[i]->SetXY(WINDOW_WIDTH/2+190,180 + (i+1) * 39);
    }
}

HighScoreScreen::~HighScoreScreen()
{
    //dtor
    mInput=NULL;
    delete title;
    title=NULL;
    delete lowtitle;
    lowtitle=NULL;
    for (int i=0; i<10; i++)
    {
      delete this->mindex[i];
      this->mindex[i]=NULL;
      delete this->mNames[i];
      this->mNames[i]=NULL;
      delete this->mScores[i];
      this->mScores[i]=NULL;
    }
}
void HighScoreScreen::Update(SCREENS &mCurrentScreen, HighScores *mHighScores)
{
    mInput->Update();
    if(notReaded)
    {
      notReaded=false;
        //read from file
        std::ifstream fin("Names.txt");
        if (!fin) {std::cerr<<"error\n"; return ;}
        int i=0;
        std::string line;
        while (std::getline(fin, line)) {

            std::istringstream iss(line);
            iss >> mHighScores[i].name  >> mHighScores[i].score ;
            if (!iss) {
             std::cerr<<"error\n";
            }
            i++;
        }//end while
    }//

    if(mInput->KeyPressed(SDL_SCANCODE_ESCAPE))
    {
        notReaded=true;
     mCurrentScreen=start;
    }
    for (int i=0; i<10; i++)
    {
     this->mNames[i]->SetText(mHighScores[i].name,{255,255,255});
     this->mScores[i]->SetText(mHighScores[i].score,{255,255,255});
    }
}
void HighScoreScreen::Render()
{
 title->Render();
 lowtitle->Render();
    for (int i=0; i<10; i++)
    {
     this->mindex[i]->Render();
     this->mNames[i]->Render();
     this->mScores[i]->Render();
    }
}
