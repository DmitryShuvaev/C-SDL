#ifndef LEVELMAKER_H
#define LEVELMAKER_H
#include "Texture.h"
#include "Collision.h"
#include "Brick.h"
#include "TileMap.h"
class LevelMaker:public Collision
{
    public:

        LevelMaker();
        virtual ~LevelMaker();
        void generateBushes(int &tempx,int &tempy);

TileMap*mTileMap;
    private:
int ground_level;
};

#endif // LEVELMAKER_H
