#include "Entity.h"

Entity::Entity()
{
    //ctor
        mTimer = Timer::Instance();
        mAnimationTimer=0.12f;
        mgemTimeanim=Timer::Instance();
        //make_clip_array(1);//int tilemap x=0 y=85 from top
}
Entity::Entity(const int x,const int y,const int w,const int h)
{

        mTimer = Timer::Instance();
        mAnimationTimer=0.12f;
        mgemTimeanim=Timer::Instance();
        gSpriteClip.x = x;
		gSpriteClip.y = y;
		gSpriteClip.w = w;
		gSpriteClip.h = h;

        width=animations_left[0].w*Scalex;
        hight=animations_left[0].h*Scaley;
        this->x=width;
        this->y=hight;
        hurtbox.x=x;
        hurtbox.y=y;
		hurtbox.w = width;
		hurtbox.h = hight;
}
Entity::~Entity()
{
    //dtor

}
void Entity::Update(SDL_Rect*player_hitbox)
{
        hurtbox.x=x;
        hurtbox.y=y;
        Coliders(player_hitbox);
}
void Entity::Render()
{


}
void Entity::Coliders(SDL_Rect*player_hitbox)
{
 if(AABB(hurtbox,*player_hitbox))
 {
  alive=false;
 }
}
void Entity::movinAnimation_Left()
{

mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/timerdiv>=1)
{
    if(count==3)
    {
     gSpriteClip.x =  animations_left[0].x;
     gSpriteClip.y =  animations_left[0].y;
        Reset();
    }
    else if (count==2)
    {
      gSpriteClip.x =  animations_left[1].x;
      gSpriteClip.y =  animations_left[1].y;
    }
    else if (count==1)
    {
      gSpriteClip.x =  animations_left[2].x;
      gSpriteClip.y =  animations_left[2].y;
    }
     count++;
     mAnimationTimer=0.0f;
}

}
void Entity::movinAnimation_Down()
{
 mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/timerdiv>=1)
{
    if(count==3)
    {
     gSpriteClip.x =  animations_down[0].x;
     gSpriteClip.y =  animations_down[0].y;
        Reset();
    }
    else if (count==2)
    {
      gSpriteClip.x =  animations_down[1].x;
      gSpriteClip.y =  animations_down[1].y;
    }
    else if (count==1)
    {
      gSpriteClip.x =  animations_down[2].x;
      gSpriteClip.y =  animations_down[2].y;
    }
     count++;
     mAnimationTimer=0.0f;
}
}
void Entity::movinAnimation_Right()
{
mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/timerdiv>=1)
{
    if(count==3)
    {
     gSpriteClip.x =  animations_right[0].x;
     gSpriteClip.y =  animations_right[0].y;
        Reset();
    }
    else if (count==2)
    {
      gSpriteClip.x =  animations_right[1].x;
      gSpriteClip.y =  animations_right[1].y;
    }
    else if (count==1)
    {
      gSpriteClip.x =  animations_right[2].x;
      gSpriteClip.y =  animations_right[2].y;
    }
     count++;
     mAnimationTimer=0.0f;
}
}//
void Entity::movinAnimation_Up()
{
 mAnimationTimer += mTimer->DeltaTime();

if(mAnimationTimer/timerdiv>=1)
{
    if(count==3)
    {
     gSpriteClip.x =  animations_up[0].x;
     gSpriteClip.y =  animations_up[0].y;
        Reset();
    }
    else if (count==2)
    {
      gSpriteClip.x =  animations_up[1].x;
      gSpriteClip.y =  animations_up[1].y;
    }
    else if (count==1)
    {
      gSpriteClip.x =  animations_up[2].x;
      gSpriteClip.y =  animations_up[2].y;
    }
     count++;
     mAnimationTimer=0.0f;
}
}
void Entity::Reset()
{
      count=0;
      mAnimationTimer=0.f;
     anim_start=false;
}
void Entity::make_clip_array(int v)
{
 //cout<<v<<endl;
      if(v==0)
      {


      //elow ghost
        for(int i=0;i<3;i++)
        {
        animations_down[i].x = (i*16);
		animations_down[i].y = 68;
		animations_down[i].w = 16;
		animations_down[i].h = 12;
        }

        for(int i=0;i<3;i++)
        {
        animations_left[i].x = (i*16);
		animations_left[i].y = 85;
		animations_left[i].w = 16;
		animations_left[i].h = 11;
        }
        for(int i=0;i<3;i++)
        {
        animations_right[i].x = (i*16);
		animations_right[i].y = 101;
		animations_right[i].w = 16;
		animations_right[i].h = 11;
        }
        for(int i=0;i<3;i++)
        {
        animations_up[i].x = (i*16);
		animations_up[i].y = 115;
		animations_up[i].w = 16;
		animations_up[i].h = 13;
        }//end elow ghost
        gSpriteClip.w = 16;
		gSpriteClip.h = 13;
        width=animations_left[0].w*Scalex;
        hight=animations_left[0].h*Scaley;

        this->x=width;
        this->y=hight;
        hurtbox.x=x;
        hurtbox.y=y;
		hurtbox.w = width;
		hurtbox.h = hight;
      }
      else if(v==1)
      {
    //white skeleton
        for(int i=0;i<3;i++)
        {
        animations_down[i].x = (i*16)+147;
		animations_down[i].y = 0;
		animations_down[i].w = 10;
		animations_down[i].h = 16;
        }
        for(int i=0;i<3;i++)
        {
        animations_left[i].x = (i*16)+147;
		animations_left[i].y = 17;
		animations_left[i].w = 10;
		animations_left[i].h = 16;
        }
        for(int i=0;i<3;i++)
        {
        animations_right[i].x = (i*16)+147;
		animations_right[i].y = 33;
		animations_right[i].w = 10;
		animations_right[i].h = 16;
        }
        for(int i=0;i<3;i++)
        {
        animations_up[i].x = (i*16)+147;
		animations_up[i].y = 49;
		animations_up[i].w = 10;
		animations_up[i].h = 16;
        }//end white skeleton
        gSpriteClip.w = 10;
		gSpriteClip.h = 16;
        width=animations_left[0].w*Scalex;
        hight=animations_left[0].h*Scaley;

        this->x=width;
        this->y=hight;
        hurtbox.x=x;
        hurtbox.y=y;
		hurtbox.w = width;
		hurtbox.h = hight;
      }
      else if(v==2)
      {
      //bat
         for(int i=0;i<3;i++)
        {
        animations_down[i].x = (i*16)+48;
		animations_down[i].y = 66;
		animations_down[i].w = 16;
		animations_down[i].h = 13;
        }
        for(int i=0;i<3;i++)
        {
        animations_left[i].x = (i*16)+48;
		animations_left[i].y = 82;
		animations_left[i].w = 16;
		animations_left[i].h = 13;
        }
        for(int i=0;i<3;i++)
        {
        animations_right[i].x = (i*16)+48;
		animations_right[i].y = 98;
		animations_right[i].w = 16;
		animations_right[i].h = 13;
        }
        for(int i=0;i<3;i++)
        {
        animations_up[i].x = (i*16)+48;
		animations_up[i].y = 114;
		animations_up[i].w = 16;
		animations_up[i].h = 13;
        }//end bat
        gSpriteClip.w = 16;
		gSpriteClip.h = 13;
        width=animations_left[0].w*Scalex;
        hight=animations_left[0].h*Scaley;

        this->x=width;
        this->y=hight;
        hurtbox.x=x;
        hurtbox.y=y;
		hurtbox.w = width;
		hurtbox.h = hight;
      }
      else if(v==3)
      {
      //spider
        for(int i=0;i<3;i++)
        {
        animations_down[i].x = (i*16)+144;
		animations_down[i].y = 70;
		animations_down[i].w = 16;
		animations_down[i].h = 10;
        }
        for(int i=0;i<3;i++)
        {
        animations_left[i].x = (i*16)+144;
		animations_left[i].y = 87;
		animations_left[i].w = 16;
		animations_left[i].h = 10;
        }
        for(int i=0;i<3;i++)
        {
        animations_right[i].x = (i*16)+144;
		animations_right[i].y = 103;
		animations_right[i].w = 16;
		animations_right[i].h = 10;
        }
        for(int i=0;i<3;i++)
        {
        animations_up[i].x = (i*16)+144;
		animations_up[i].y = 118;
		animations_up[i].w = 16;
		animations_up[i].h = 10;
        }//end spider
        gSpriteClip.w = 16;
		gSpriteClip.h = 10;
        width=animations_left[0].w*Scalex;
        hight=animations_left[0].h*Scaley;

        this->x=width;
        this->y=hight;
        hurtbox.x=x;
        hurtbox.y=y;
		hurtbox.w = width;
		hurtbox.h = hight;
     }
     else if(v==4)
      {
      //white ghost
        for(int i=0;i<3;i++)
        {
        animations_down[i].x = (i*16)+96;
		animations_down[i].y = 64;
		animations_down[i].w = 16;
		animations_down[i].h = 16;
        }
        for(int i=0;i<3;i++)
        {
        animations_left[i].x = (i*16)+96;
		animations_left[i].y = 80;
		animations_left[i].w = 16;
		animations_left[i].h = 16;
        }
        for(int i=0;i<3;i++)
        {
        animations_right[i].x = (i*16)+96;
		animations_right[i].y = 96;
		animations_right[i].w = 16;
		animations_right[i].h = 16;
        }
        for(int i=0;i<3;i++)
        {
        animations_up[i].x = (i*16)+96;
		animations_up[i].y = 112;
		animations_up[i].w = 16;
		animations_up[i].h = 16;
        }//end white ghost
        gSpriteClip.w = 16;
		gSpriteClip.h = 16;
        width=animations_left[0].w*Scalex;
        hight=animations_left[0].h*Scaley;

        this->x=width;
        this->y=hight;
        hurtbox.x=x;
        hurtbox.y=y;
		hurtbox.w = width;
		hurtbox.h = hight;
      }
}
void Entity::setIdle()
{
     switch(dir)
 {
 case left:
     gSpriteClip.x =  animations_left[1].x;
     gSpriteClip.y =  animations_left[1].y;
    break;
 case up:
    gSpriteClip.x =  animations_up[1].x;
    gSpriteClip.y =  animations_up[1].y;
    break;
 case right:
    gSpriteClip.x =  animations_right[1].x;
    gSpriteClip.y =  animations_right[1].y;
     break;
 case down:
    gSpriteClip.x =  animations_down[1].x;
    gSpriteClip.y =  animations_down[1].y;
     break;
 }
}
bool Entity::colide_with_other_entities(Entity &entity,Entity *(&entitys)[10])
{
 for(int i=0;i<10;i++)
 {
     if(AABB(entity.hurtbox,entitys[i]->hurtbox)&&entity.id!=entitys[i]->id)
        {
         //cout<<true<<endl;
            return true;
        }
 }
 //cout<<false<<endl;
 return false;
}
