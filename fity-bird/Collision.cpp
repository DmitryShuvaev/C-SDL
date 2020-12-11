#include "Collision.h"
//#include "ColliderComponent.h"

Collision::Collision()
{
    //ctor
}
bool Collision::AABB(const SDL_Rect&recA,const SDL_Rect&recB)
 {
     if(recA.x+recA.w>=recB.x &&
        recB.x+recB.w>=recA.x &&
        recA.y+recA.h>=recB.y &&
        recB.y+recB.h>=recA.y)
     {
         return true;
     }
     return false;
 }
//bool Collision:: AABB(const SDL_Rect&colA,
//        const SDL_Rect&colB)
//{
//    if(AABB(colA,colB))
//    {
//        std::cout<<colA.tag<<" hit: "<<colB.tag<<std::endl;
//        return true;
//    }else
//    {
//        return false;
//    }
//}
Collision::~Collision()
{
    //dtor
}
