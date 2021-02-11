#ifndef TILEMAP_H
#define TILEMAP_H
#include "Texture.h"
#include "Collision.h"
#include "Brick.h"
#include <math.h>
class TileMap:public Collision
{
    public:
        enum SCREENS1{TILE_ID_EMPTY,TILE_ID_GROUND};
        struct GemsCol
        {
            Brick *g=NULL;
        };
        TileMap();
        virtual ~TileMap();

        struct Table
        {
         Brick *brick;
        };
        struct Bushes
        {
            int x,y;//position of x and y sprite clip
            int width=16*5,hight=16*5;
            //frame
           SDL_Rect SpriteClip;
        };
        void initLevel();
        void Render();
        Brick* pointToTile(int x, int y);
        int indexY(int x, int y);
        int indexX(int x, int y);
        //
        template<typename T>
        void reSIZE(T *&original, int &SIZE,int &old_size)//function definition
        {
            SIZE+=1;
            T *temporiginal = new T[SIZE ]; //(final)new array

            for (int i = 0; i < old_size; i++) //copy old array to new array
            {
                temporiginal[i] = original[i];

                //cout << temporiginal[i].g->gemx << endl;
            }

            delete[] original; //delete old array
            original = temporiginal; //point old array to new array
        }
 int numRows;
 int numCols;
  Texture*bricks;
  Texture*topTiles;
  Texture*jump_block;
  Texture*gems;
  Texture*bushesTexture;
Table **table;
SDL_Rect gSpriteClips[10][6];
SDL_Rect TopsSpriteClips[18][6];
SDL_Rect JumpSpriteClips[5][6];
SDL_Rect SkySpriteClip;
SDL_Rect Jump_blockClip;
//bushes sprites
SDL_Rect bushSpriteClips[4][3];
int randx_top;
int randy_top;
int randx_jumpBlock;
int randy_jumpBlock;
//
GemsCol *b;
int old_size;
int sizearr=1;
int indx=0;
//
Bushes* bushes=NULL;
int SIZEBush=1;
int old_size_bush;
int indxBush=0;
};

#endif // TILEMAP_H
