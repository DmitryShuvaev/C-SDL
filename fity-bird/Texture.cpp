#include "Texture.h"

Texture::Texture()
{
    //ctor
    mGraphics = Graphics::Instance();

}
void Texture::SetPos(int x,int y)
{

}
	Texture::Texture(std::string filename) {

		mGraphics = Graphics::Instance();
		//Get the full path of the file
		//std::string fullPath = SDL_GetBasePath();
		//fullPath.append("Assets/" + filename);

		//If the file has not been already loaded, load it and add it to the mTextures map
		//if(mTextures[fullPath] == nullptr)
			//mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);

		//returning the cached file from the map
		//return mTextures[fullPath];
		//Loads the texture from the AssetManager to avoid loading textures more than once
		mTex = Graphics::Instance()->LoadTexture(filename);

		//Gets the Width and Height of the texture
		SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

		//Clipped is false since the image is not loaded from a spritesheet
		mClipped = false;

		mRenderRect.w = mWidth;
		mRenderRect.h = mHeight;
	}
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
   this->color=color;
}
void Texture::SetXY(float x,float y)
{
    mRenderRect.x = x;
    mRenderRect.y = y;
}
void Texture::SetColor(SDL_Color color)
{
  this->color=color;
  if(mTex!=NULL){SDL_DestroyTexture(mTex);
  mTex=NULL;
  }
  mTex=mGraphics->CreateTextTexture(font,text,color);
}
void Texture::SetText(char* text)
{
   if(mTex!=NULL){SDL_DestroyTexture(mTex);
  mTex=NULL;
  }
  mTex=mGraphics->CreateTextTexture(font,text,color);
}
void Texture::Render()
{
   mGraphics->DrawTexture(mTex,NULL,&mRenderRect,0,SDL_FLIP_NONE);
}
void Texture::RenderFlipped()
{
    mGraphics->DrawTexture(mTex,NULL,&mRenderRect,0,SDL_FLIP_VERTICAL);
}
void Texture::RenderRec(SDL_Color color)
{
mGraphics->RenderRect( mRenderRect,color);
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
