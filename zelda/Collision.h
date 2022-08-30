#ifndef COLLISION_H
#define COLLISION_H
#include <SDL.h>



class Collision
{
    public:
          enum SCREENS{start,GameOver,play,walking,idle,score,dungeonScreen,SwingSwordState};
          enum ENTITYSTATE{EntityWalk,EntityIdle};
          enum DIRECTIONS{left,right,up,down};
          enum SWITCH_STATE{pressed,unpressed};
        static bool AABB(const SDL_Rect&recA,const SDL_Rect&recB);
        //static bool AABB(const SDL_Rect&colA,
       // const SDL_Rect&colB);
        Collision();
        virtual ~Collision();
float ic=2.5;
int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
    static const int SCREEN_WIDTH=1280;
    static const int SCREEN_HEIGHT=720;
int TILE_SIZE = 16;
    protected:

    private:
};

#endif // COLLISION_H
