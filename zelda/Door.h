#ifndef DOOR_H
#define DOOR_H
#include "Texture.h"
#include "Collision.h"
class Door:Collision
{
    public:
      Door();
      virtual ~Door();
      void make_door();
      void make_low_door();
      void make_left_door();
      void make_right_door();
      void open_right_door();
      void open_left_door();
      void open_up_door();
      void open_low_door();
      void render_door(Texture*maintexture);
      void render_low_door(Texture*maintexture);
      void render_left_door(Texture*maintexture);
        SDL_Rect door;
        int tilesizex=100;
        int tilesizey=75;
        int x,y;
        SDL_Rect colider;
     bool open = false;
};

#endif // DOOR_H
