#include "Door.h"

Door::Door()
{
    //ctor
}

Door::~Door()
{
    //dtor
}
void Door::make_door()
{
    door.x=0;
    door.y=122;
    door.w=32;
    door.h=22;
    x=WINDOW_WIDTH/2;
    y=70-23;
    colider.x=x;
    colider.y=y;
    colider.w=tilesizex;
    colider.h=tilesizey;

}
void Door::make_low_door()
{

    door.x=96;
    door.y=176;
    door.w=32;
    door.h=22;
    x=WINDOW_WIDTH/2;
    y=WINDOW_HEIGHT-100;
    colider.x=x;
    colider.y=y;
    colider.w=tilesizex;
    colider.h=tilesizey;

}
void Door::make_left_door()
{
    door.x=154;
    door.y=176;
    door.w=22;
    door.h=32;
    x=26;
    y=WINDOW_HEIGHT/2-(45);
    colider.x=x;
    colider.y=y;
    colider.w=tilesizey;
    colider.h=tilesizex;
}
void Door::make_right_door()
{
    door.x=32;
    door.y=144;
    door.w=22;
    door.h=32;
    x=WINDOW_WIDTH-tilesizex;
    y=WINDOW_HEIGHT/2-(45);
    colider.x=x;
    colider.y=y;
    colider.w=tilesizey;
    colider.h=tilesizex;
}
void Door::render_door(Texture*maintexture)
{
 maintexture->render(x, y,&door,tilesizex,tilesizey);
 //maintexture->mGraphics->draw_rect(colider);
}
void Door::render_low_door(Texture*maintexture)
{
    maintexture->RenderFlipped_Vertical( x, y, &door,tilesizex,tilesizey );
}
void Door::render_left_door(Texture*maintexture)
{
 maintexture->render(x, y,&door,tilesizey,tilesizex);
 //maintexture->mGraphics->draw_rect(colider);
}
void Door::open_right_door()
{
    door.x=0;
    door.y=144;
    door.w=22;
    door.h=32;
}
void Door::open_left_door()
{
    door.x=154;
    door.y=144;
    door.w=22;
    door.h=32;
}
void Door::open_up_door()
{
    door.x=32;
    door.y=90;
    door.w=32;
    door.h=22;
}
void Door::open_low_door()
{
    door.x=112;
    door.y=112;
    door.w=32;
    door.h=22;
}
