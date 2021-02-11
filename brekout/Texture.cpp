#include "Texture.h"

Texture::Texture()
{
    //ctor
    mGraphics = Graphics::Instance();

}

Texture::Texture(std::string filename) {

		mGraphics = Graphics::Instance();

		mTex = Graphics::Instance()->LoadTexture(filename);

		//Gets the Width and Height of the texture
		SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);
		mRenderRect.w = mWidth;
		mRenderRect.h = mHeight;
        mRenderRect.x = 0;
        mRenderRect.y = 0;
}//
//texture for text
Texture::Texture(char* fontname,char* text,int SIZE,SDL_Color color)
{
   mGraphics = Graphics::Instance();
   TTF_Init();
   this->text=text;
   font = TTF_OpenFont(fontname, SIZE);
    mTex=mGraphics->CreateTextTexture(font,text,color);
    SDL_QueryTexture(mTex,NULL,NULL,&mWidth,&mHeight);
    mRenderRect.w=mWidth;
    mRenderRect.h=mHeight;
   //this->color=color;
}
void Texture::SetXY(float x,float y)
{
    mRenderRect.x = x;
    mRenderRect.y = y;
}
//set color
void Texture::SetColor(SDL_Color color)
{
  //this->color=color;
  if(mTex!=NULL){SDL_DestroyTexture(mTex);
  mTex=NULL;
  }
  mTex=mGraphics->CreateTextTexture(font,text,color);
    SDL_QueryTexture(mTex,NULL,NULL,&mWidth,&mHeight);
    mRenderRect.w=mWidth;
    mRenderRect.h=mHeight;
}
//
void Texture::setAlpha( Uint8 alpha )
{
	SDL_SetTextureBlendMode(mTex, SDL_BLENDMODE_BLEND);
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTex, alpha );
}
//
void Texture::SetText(std::string text,SDL_Color color)
{
   if(mTex!=NULL){SDL_DestroyTexture(mTex);
  mTex=NULL;
  }
  //std::stringstream scoreText;

    this->text=strcpy((char*)malloc(text.length()+1), text.c_str());
  //cout<<text;
  mTex=mGraphics->CreateTextTexture(font,this->text,color);
  SDL_QueryTexture(mTex,NULL,NULL,&mWidth,&mHeight);
      mRenderRect.w=mWidth;
    mRenderRect.h=mHeight;
}
void Texture::render( int x, int y,  SDL_Rect* clip ,float Scalex,float Scaley)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, Scalex, Scaley };

	//Set clip rendering dimensions
//	if( clip != NULL )
//	{
//		renderQuad.w = clip->w*Scalex;
//		renderQuad.h = clip->h*Scaley;
//	}
//    mRenderRect.x = x;
//    mRenderRect.y = y;
//    mRenderRect.w=clip->w*Scalex;
//    mRenderRect.h=clip->h*Scaley;
//renderQuad.w =Scalex;
//renderQuad.h = Scaley;
   mGraphics->RenderTex(mTex,clip,renderQuad);
}
void Texture::Render()
{
   mGraphics->DrawTexture(mTex,NULL,&mRenderRect,0,SDL_FLIP_NONE);
}


Texture::~Texture()
{
    //dtor
if(mTex!=NULL){
  SDL_DestroyTexture(mTex);
  mTex=NULL;
  }
    mGraphics=NULL;
}
