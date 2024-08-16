# Dungeon Game in C++
This is a small project where SDL is used to create a simple mini game of a character wondering in a dungeon filled with crests and enemies.

## Installation
After you clone the project locally you should go to the project's properties and add the following
- In the "VC++ Directories / Include Directories"
  Add the path to the "SDL2/include" folder
- In the "VC++ Directories / Library Directories"
  Add the path to the "SDL2/lib/x64" folder
- In the "C/C++ Directories / Additional Include Directories"
  Add the path to the "SDL2/lib/x64" folder
- In the "Linker / Input"
  Add the following
  SDL2.lib
  SDL2main.lib
  SDL2_image.lib
  SDL2_mixer.lib
  SDL2_ttf.lib
