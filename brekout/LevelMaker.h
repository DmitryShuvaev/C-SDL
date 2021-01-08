#ifndef LEVELMAKER_H
#define LEVELMAKER_H
#include "Brick.h"
//#include "Collision.h"

class LevelMaker
{
    public:
        LevelMaker();
        virtual ~LevelMaker();
        struct Table
        {
          Brick *brick;
        };
        void initLevel();
 int numRows;
 int numCols;
Table **table;
SDL_Rect gSpriteClips[6];
    private:

};

#endif // LEVELMAKER_H
