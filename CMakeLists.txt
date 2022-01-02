cmake_minimum_required(VERSION "3.21.4")
project("Synth")

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME "Synth")

#find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
#find_library(SDL2_LIBRARY NAME SDL2)

#set(SDL_INCLUDE_DIR /usr/include/SDL2)
#set(SDL2_LIBRARIES /usr/lib/SDL2)

#find_package(SDL2 REQUIRED)

find_package(PkgConfig)
PKG_CHECK_MODULES(SDL2 REQUIRED sdl2)

file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${SDL2_CFLAGS_OTHER})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)
