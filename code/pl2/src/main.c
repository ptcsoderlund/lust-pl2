#include "SDL3/SDL_events.h"
#include "SDL3/SDL_keycode.h"
#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>
#include <memory/pl_arena_allocator.h>
#include <pl_types.h>
#include <stdio.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

VkInstance vk_instance = {0};

void init(){
}

int main(void) {
  i32 my_num = 300;
  printf("Hello, lust: %i\n", my_num);
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0) {
    printf("SDL_Init failed: %s\n", SDL_GetError());
    return 1;
  }
  SDL_Window *window =
      SDL_CreateWindow("Hello, lust!", 1280, 720, 0);
  if (!window) {
    printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  SDL_Event e;
  SDL_Renderer* renderer = SDL_CreateRenderer(window,nullptr);
  bool app_run = true;
  while (app_run) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT) {
        app_run = false;
        break;
      }
      //quit on escape or q
      if(e.type == SDL_EVENT_KEY_DOWN){
        if(e.key.key == SDLK_ESCAPE || e.key.key == SDLK_Q){
          app_run = false;
          break;
        }
      }
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
