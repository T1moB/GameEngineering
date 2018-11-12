#pragma once
#include "Component.h"
#include "SDL.h"
#include "SDL_image.h"

class RenderComponent : public Component
{
public:
	RenderComponent(const char* path, SDL_Renderer* r) {
		SDL_Surface* surface;
		surface = IMG_Load(path);
		texture = SDL_CreateTextureFromSurface(r, surface);
	}
	SDL_Texture* GetTexture() {return texture; }
	int GetIndex() { return 3; }
	Type GetType() { return Type::Render; }
	~RenderComponent();
private:
	SDL_Texture* texture;
};