#ifndef CHARACTER_H
#define CHARACTER_H
#include "Texture.h"
#include "AudioManager.h"
#include "TileMap.h"
class Character
{
    public:
        Character();
        Character(const int x,const int y,const int w,const int h);
        virtual ~Character();
        void Update();
        void Render();
        void RenderFlipped();
        bool checkLeftCollisions(float &dx,TileMap & mTileMap);
        bool checkRightCollisions(float &dx,TileMap & mTileMap);
        float Scalex=5;
        float Scaley=5;
        int x;
        int y;
        int width;
        int hight;
        Texture*character;
        SDL_Rect gSpriteClip;
        SDL_Rect gSpriteClips[6];
    private:
};

#endif // CHARACTER_H
