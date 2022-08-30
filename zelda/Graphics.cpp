#include "Graphics.h"
Graphics*Graphics::sInstance=NULL;
	//Initializing to false
bool Graphics::sInitialized = false;
Graphics*Graphics::Instance()
{
    if(sInstance==NULL)
    {
        sInstance=new Graphics();
    }
    return sInstance;
}
void Graphics::Release()
{
    delete sInstance;
    sInstance=NULL;
    sInitialized = false;
}
void Graphics::Render()
{
 SDL_RenderPresent(mRenderer);
}
Graphics::Graphics()
{
    //ctor
   sInitialized = Init();
}
bool Graphics::Init()
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)<0){
        return false;
    }
		//Creating the window
		mWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

		//Handling with window creation errors
		if(mWindow == NULL) {

//			printf("Window Creation Error: %s\n", SDL_GetError());
			return false;
		}
				//Creating the renderer
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
				//Handling with the renderer creation errors
		if(mRenderer == NULL) {

//			printf("Renderer Creation Error: %s\n", SDL_GetError());
			return false;
		}

		//Setting the renderer's clear color to white
		SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
				int flags = IMG_INIT_PNG;

		if(!(IMG_Init(flags) & flags)) {

			printf("IMG Initialization Error: %s\n", IMG_GetError());
			return false;
		}
}//
void Graphics::ClearBackBuffer() {

		SDL_RenderClear(mRenderer);
}
	SDL_Texture* Graphics::LoadTexture(std::string path) {

		SDL_Texture* tex = NULL;

		//load the image onto a surface
		SDL_Surface* surface = IMG_Load(path.c_str());
		//Handling image loading errors
		if(surface == NULL) {

			printf("Image Load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
			return tex;
		}

		//Converting the surface into a texture to be able to render it using the renderer
		tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		//Handling texture creation errors
		if(tex == NULL) {

			printf("Create Texture Error: %s\n", SDL_GetError());
			return tex;
		}

		//free the surface since only the texture is needed
		SDL_FreeSurface(surface);

		return tex;
	}
SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color) {
        	//Get rid of preexisting texture

		//Render the text onto a surface using the provided font and color
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
		//Handling font rendering errors
		if(surface == NULL) {

			//printf("Text Render Error: %s\n", TTF_GetError());
			return NULL;
		}

		//Converting the surface into a texture to be able to render it using the renderer
		SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		//Handle texture creation errors
		if(tex == NULL) {

			//printf("Text Texture Creation Error: %s\n", SDL_GetError());
			return NULL;
		}

		//free the surface since only the texture is needed
		SDL_FreeSurface(surface);

		return tex;
}
	void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip) {

		SDL_RenderCopyEx(mRenderer, tex, clip, rend, angle, NULL, flip);
	}
	void Graphics::DrawTexture(SDL_Texture* tex,SDL_Rect &p) {

      SDL_RenderCopy(mRenderer, tex, NULL, &p);
	}
void Graphics::RenderTex(SDL_Texture*mTexture, SDL_Rect* clip, SDL_Rect&renderQuad)
{
SDL_RenderCopy( mRenderer, mTexture, clip, &renderQuad );
}
void Graphics::draw_rect(SDL_Rect &r)
{
  SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
  SDL_RenderDrawRect(mRenderer, &r);
  SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
}
Graphics::~Graphics()
{
    //dtor
        SDL_DestroyWindow(mWindow);
		mWindow = NULL;
}
