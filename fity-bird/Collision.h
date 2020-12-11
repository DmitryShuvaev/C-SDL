#ifndef COLLISION_H
#define COLLISION_H
#include <SDL.h>



class Collision
{
    public:
          enum SCREENS{start,play,score,CountdownState};
        static bool AABB(const SDL_Rect&recA,const SDL_Rect&recB);
        //static bool AABB(const SDL_Rect&colA,
       // const SDL_Rect&colB);
        Collision();
        virtual ~Collision();

    protected:

    private:
};

#endif // COLLISION_H
