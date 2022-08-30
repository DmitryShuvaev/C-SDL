#include "Player.h"

Player::Player()
{
    //ctor
}
Player::Player(const int x,const int y,const int w,const int h)
{
    //ctor
        player=new Texture("graphics/character.png");
        gSpriteClip.x = x;
		gSpriteClip.y = y;
		gSpriteClip.w = w;
		gSpriteClip.h = h;
        width=gSpriteClip.w*Scalex;
        hight=gSpriteClip.h*Scaley;
        this->x=width;
        this->y=hight;
        //colis rect
        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = hight/2+15;
        lefthitbox.w=hitboxWidth;
        lefthitbox.h=hitboxHeight;
        righthitbox.w=hitboxWidth;
        righthitbox.h=hitboxHeight;
        uphitbox.w=80;
        uphitbox.h=30;
        downhitbox.w=80;
        downhitbox.h=30;
        //

}
void Player::Update()
{
 lefthitbox.x=x-hitboxWidth;
 lefthitbox.y=y+10;
 righthitbox.x=x+width;
 righthitbox.y=y+10;
 uphitbox.x=x-10;
 uphitbox.y=y-10;
 downhitbox.x=x-10;
 downhitbox.y=y+hight-20;
}
void Player::Render()
{

 if(canRender)
 {
  player->render( x, y, &gSpriteClip,width,hight );
 }

        rect.x = x-5;
        rect.y = y+hight/2-10;


         //player->mGraphics->draw_rect(rect);
         //player->mGraphics->draw_rect(lefthitbox);
         if(is_hit)
         Render_hit();

}
void Player::RenderFlipped()
{
 if(canRender)
 {
  player->RenderFlipped( x, y, &gSpriteClip,width,hight );
 }
        rect.x = x-5;
        rect.y = y+hight/2-10;
        player->mGraphics->draw_rect(rect);
}
void Player::Render_hit()
{
   wait_time++;
   if(wait_time<60)
   {

   if(c==4)
   {
    player->setAlpha(100);
    c=0;
   }
   else
   {
   player->setAlpha(255);
   }
   c++;
   }else
   {
       player->setAlpha(255);
       is_hit=false;
       c=0;wait_time=0;
   }

}
Player::~Player()
{
    //dtor
    delete player;
    player=NULL;
}
