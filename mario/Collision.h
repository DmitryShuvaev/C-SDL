#ifndef COLLISION_H
#define COLLISION_H
#include <SDL.h>
#include <string>


class Collision
{
    public:
          enum SCREENS{start,play,score,serve,game_over,victory,high_scores,enter_high_score,falling,walking,idle,jump};
        static bool AABB(const SDL_Rect&recA,const SDL_Rect&recB);
struct HighScores
{
    std::string name;
    std::string score;
};
        Collision();
        virtual ~Collision();
float ic=4.3;
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int TILE_SIZE = 16*5;
template <class T1,class T2>
bool collides( const T1 &ball,const T2 &target )
{
   if(ball.x+ball.width>=target.x
     && ball.x<= target.x + target.width
     &&ball.y+ball.hight>=target.y
     &&ball.y<=target.y+target.hight)
   return true;
  return false;
}
template <class T1,class T2>
bool collidesLeftLow( const T1 &ball,const T2 &target )
{
    int w=target.width/4;
    int h=target.hight/4;
    int x=target.x;
    int y=target.y+(target.hight-h);
   if(ball.x+ball.width>=x
     && ball.x<= x + w
     &&ball.y+ball.hight>=y
     &&ball.y<=y+h)
   return true;
  return false;
}
//
template <class T1,class T2>
bool collidesRightLow( const T1 &ball,const T2 &target )
{
    int w=target.width/4;
    int h=target.hight/4;
    int x=target.x+(target.width-w);
    int y=target.y+(target.hight-h);
   if(ball.x+ball.width>=x
     && ball.x<= x + w
     &&ball.y+ball.hight>=y
     &&ball.y<=y+h)
   return true;
  return false;
}
    private:
};

#endif // COLLISION_H
