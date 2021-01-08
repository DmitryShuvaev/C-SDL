#ifndef PARTICLE_H
#define PARTICLE_H
#include "Texture.h"

class Particle
{
    public:
        Particle();
        Particle(int x,int y);
        virtual ~Particle();

		//Shows the particle
		void render();
        void update();
		//Checks if particle is dead
		bool isDead();
        int mPosX, mPosY;

		//Current frame of animation
		int mFrame;
				//Type of particle
		Texture *mTexture;
		Texture*gShimmerTexture;
		int renderParticleTime=255;
    private:




};

#endif // PARTICLE_H
