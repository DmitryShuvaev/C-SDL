#ifndef ENTITY_H
#define ENTITY_H
#include "Texture.h"
#include "Player.h"
#include "Timer.h"
#include "Collision.h"
class Entity:public Collision
{
    public:
        Entity();
        Entity(const int x,const int y,const int w,const int h);
        virtual ~Entity();
        void movinAnimation_Left();
        void movinAnimation_Right();
        void movinAnimation_Down();
        void movinAnimation_Up();
        void Reset();
        void Update(SDL_Rect*player_hitbox);
        void Render();
        void Coliders(SDL_Rect*player_hitbox);
        void make_clip_array(int v);
        void setIdle();
        bool colide_with_other_entities(Entity &entity,Entity *(&entitys)[10]);
        SDL_Rect animations_left[3];
        SDL_Rect animations_down[3];
        SDL_Rect animations_right[3];
        SDL_Rect animations_up[3];
        SDL_Rect gSpriteClip;
        int x=0;
        int y=0;
        int width;
        int hight;
        float Scalex=3.5;
        float Scaley=3.5;
        SDL_Rect hurtbox;
        bool alive=true;
        //health
        int health=1;
        DIRECTIONS dir;
        //animation
        float mAnimationTimer=0.2f;
int count=0;
bool startanim=false;

        Timer* mTimer;
Timer* mgemTimeanim;
float mgemAnimationTimer=0.0f;
bool anim_start=false;
bool bumped=false;
float timerdiv=0.18f;
//animation for walkstate and idlestate
int Duration=0;
int durTimer=0;
ENTITYSTATE mEntityState;
int currand_dir=0;
int id=0;
bool hited_player=false;
};

#endif // ENTITY_H
