#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <iostream>
#include <memory>
#include "Texture.h"
#include "Collision.h"
#include <cstring>

class Room:public Collision
{
    public:
        Room();
        ~Room();

        void init();

        void Update(SCREENS &mCurrentScreen,int &score,bool &scrolling);
        void Render();
        bool colidecontinue();
        bool colideexit();
        void ClearScreen();
                char*conveText(std::string scoreStr);
        //        Texture*background;
        int tilesize=16*ic;
        Texture*ground;
        Texture*topleft;
        Texture*topright;
        Texture*lowleft;
        Texture*lowright;
        Texture*leftWall[14];
        Texture*rightWall[14];
        Texture*topWall[28];
        Texture*lowWall[28];
        Texture*centerMap[14][28];
};

#endif // ROOM_H
