#include "SDL_image.h"
#include "../include/Sprite.h"
#include "../include/Platform.h"

Sprite::Sprite() {
}

//int Sprite::Lua_HostFunction(lua_State* L) {
//    SDL_Surface* loadedSurface = IMG_Load("..assets/VRAM_Mine.png");
//    return 1;
//}

void Sprite::LoadSprite(std::string name) {
    this->name = name;
    SDL_Surface* loadedSurface = IMG_Load(name.c_str());
    width = loadedSurface->w;
    height = loadedSurface->h;
    sprite = SDL_CreateTextureFromSurface(Platform::renderer, loadedSurface);

}

SDL_Texture* Sprite::GetTexture() {
    return sprite;
}

int Sprite::GetWidth() {
    return width;
}

int Sprite::GetHeight() {
    return height;
}

Sprite::~Sprite() {
}