# cub3d Project

Welcome to cub3d, a project from the curriculum of 42 Wolfsburg.

![cub3d](./.media/cub3d.gif)


## Description

cub3d is a 42 Project that aims to create a basic 3D game engine using the raycasting technique. It's inspired by the classic game Wolfenstein 3D and provides a simple environment where you can move around a maze-like map.

## Features

- Raycasting rendering technique
- Textured walls
- Support for different wall textures
- Player movement and rotation
- Collision detection with walls

## Installation

1. Clone this repository: `git clone https://github.com/thule-re/cub3d.git`
2. Navigate to the project directory: `cd cub3d`
3. Run `make` to compile the project
4. Execute the program with `./cub3D path/to/map.cub`

## How to Play

- Move forward: W
- Move backward: S
- Strafe left: A
- Strafe right: D
- Rotate left: Left Arrow
- Rotate right: Right Arrow
- Toggle mouse look: LMB
- Exit the game: Esc

## Map Configuration

The game map is configured using a `.cub` file. The file contains various settings for the game, such as map layout, textures, colors, and more. Here's a sample configuration:

    NO textures/north_texture.png
    SO textures/south_texture.png
    WE textures/west_texture.png
    EA textures/east_texture.png
    F 220,100,50
    C 15,15,15

    1111111
    100W001
    1011101
    1000001
    1111111

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
