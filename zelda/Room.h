#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <iostream>
#include <memory>
#include "Texture.h"
#include "AudioManager.h"
#include "Collision.h"
#include "Door.h"
#include "Player.h"
#include "Entity.h"
#include <cstring>
struct Walsxy
{
    int x,y;
};
struct Posxy
{
    int x,y;
};

class Room:public Collision
{
    public:
        Room();
        ~Room();

        void init();

        void Update(SCREENS &mCurrentScreen,Player*player);
        void Render();
        bool colidecontinue();
        bool colideexit();
        void ClearScreen();
        void make_coners();
        void render_corners();
        void render_left_wall();
        void render_right_wall();
        void make_left_wall();
        void make_right_wall();
        void make_top_wall();
        void make_low_wall();
        void make_floor();
        void make_door();
        void make_wall_coliders();
        void make_entities();

        void render_top_wall();
        void render_low_wall();
        void render_floor();
        void render_door();
        void render_switch();
        void render_hearts();
        void set_pos(int valuey);
        void set_pos_x(int valuey);
        void make_door_switch();
        void make_open_door_switch();
        void switch_onCollide (Player*player);
        int randomvalue(int max,int min);
        char*conveText(std::string scoreStr);
        int tilesize=50;
        Texture*maintexture;
        Texture*enemy;
        SDL_Rect topleftSpriteClip;
        SDL_Rect toprightSpriteClip;
        SDL_Rect lowleftSpriteClip;
        SDL_Rect lowrightSpriteClip;
        Walsxy leftWall[3];
        Walsxy rightWall[3];
        Walsxy topWall[3];
        Walsxy lowWall[3];
        Walsxy floor[32];
        SDL_Rect leftWallClip[10];
        SDL_Rect rightWallClip[10];
        SDL_Rect topWallClip[22];
        SDL_Rect lowWallClip[22];
        SDL_Rect floorCliprect[220];
        int y_from_top=70;
        Door *door;
        Door*lowDoor;
        Door*leftDoor;
        Door*rightDoor;
        //positions for shiftin
        Posxy floorxypos[220];
        Posxy lowWallxypos[22];
        Posxy topWallxypos[22];
        Posxy leftWallxypos[10];
        Posxy rightWallxypos[10];
        Posxy topleftxypos;
        Posxy toprightxypos;
        Posxy lowleftxypos;
        Posxy lowrightxypos;
        SDL_Rect colider;
        SDL_Rect coliderLowWall;
        SDL_Rect coliderUpWall;
        SDL_Rect coliderUp;
        SDL_Rect coliderLeftWall;
        SDL_Rect coliderLeft;
        SDL_Rect coliderRightWall;
        SDL_Rect coliderRight;
        //entities in the room
        Entity *entities[10];
        //collision  with room wall top
        SDL_Rect colidertopWall;
        //collision  with room wall low
        SDL_Rect coliderlowWall;
        //collision  with room wall left
        SDL_Rect coliderleftWall;
        //collision  with room wall right
        SDL_Rect coliderrightWall;
        //switch to open doors
        SDL_Rect door_switch;
        Texture*switch_texture;
        int switch_x;
        int switch_y;
        //colider for door_switch
        SDL_Rect door_switch_colider;
        SWITCH_STATE sw_state;
        //bool doorway_open = false;
        AudioManager* mAudioMgr;

        //topleftrect
        SDL_Rect topleft;
};

#endif // ROOM_H
