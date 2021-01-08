#ifndef BRICK_H
#define BRICK_H
#include "Texture.h"
#include "Particle.h"
#include "AudioManager.h"

class Brick
{
    public:
        Brick();
        Brick(const int x,const int y,const int w,const int h);
        virtual ~Brick();
        void Update();
        void Render();
        void hit();
        void initLevel();
        void renderParticles();
        float Scalex=3;
    float Scaley=3;
    int x;
    int y;
    int width;
    int hight;
    Texture*brick;
SDL_Rect gSpriteClip;
AudioManager* mAudioMgr;
bool inPlay;
int color;
SDL_Rect gSpriteClips[6];
//Particle count
 int TOTAL_PARTICLES = 20;
		//The particles
		Particle* particles[ 20 ];
		int renderParticleTime=100;
		bool renderParticle=false;
		bool np=false;
    private:
};

#endif // BRICK_H
