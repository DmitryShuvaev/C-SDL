#ifndef BALL_H
#define BALL_H
#include "Texture.h"
#include "Paddle.h"
#include "AudioManager.h"
class Ball:public Collision
{
    public:
        Ball();
        virtual ~Ball();
//template <class T1,class T2>
//bool collides( const T1 &ball,const T2 &target )
//{
//   if(ball.x+ball.width>=target.x
//     && ball.x<= target.x + target.width
//     &&ball.y+ball.hight>=target.y
//     &&ball.y<=target.y+target.hight)
//   return true;
//  return false;
//}

        void Update();
        void Render();
        float Scalex=3;
    float Scaley=3;
    int x;
    int y;
    int dx=0;
    int dy=5;
    int width;
    int hight;
    int BALL_SPEED;
    int resSPEED;
Texture*ball;
SDL_Rect gSpriteClips;
AudioManager* mAudioMgr;
};

#endif // BALL_H
