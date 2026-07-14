cmake_minimum_required(VERSION 4.3.0)

project(Lust_pl2 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
    pl
    GIT_REPOSITORY "git@github.com:ptcsoderlund/limbo-pl1.git"
    GIT_TAG "main"
  )
FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-3.4.12 # Use a specific release tag for stability
)
set(SDL_SHARED ON CACHE BOOL "Build SDL3 as a shared library" FORCE)
set(SDL_STATIC OFF CACHE BOOL "Do not build SDL3 static library" FORCE)
FetchContent_MakeAvailable(SDL3)
FetchContent_MakeAvailable(pl)

add_subdirectory(code/pl2)
