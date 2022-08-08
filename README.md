# Cub3D

![42-Badge](https://img.shields.io/badge/%C3%89cole-42SP-blue)![C-Badge](https://img.shields.io/badge/Language-C-lightgrey)[![42Unlicense](https://img.shields.io/badge/License-42Unlicense-yellowgreen)](https://github.com/gcamerli/42unlicense)

<img src="https://github.com/dpiza/resources/blob/master/gifs/nuk3d_menu.gif?raw=true"/>


## Description

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. In this project, we explore the concepts of ray-casting.

## Goals

This is the second project in which we use the graphical library [`miniLibX`](https://github.com/42Paris/minilibx-linux), and my new favorite.
The goal is to make a dynamic view inside a maze.

<img src="https://github.com/dpiza/resources/blob/master/gifs/nuk3d_.gif?raw=true"/>

## Mandatory

• Smooth window management;

• Display different wall textures thatvary deppending on which side the wall is facing;

• Set the floor and the ceiling to two different colors;

• Set the following keys:
   - W A S D to move the point of view through the maze;
   - ← and → arrow keys to rotate the camera;
   - ESC to close the window and quit the program cleanly, so as the red cross.

• Use of images of the minilibX;

• Validate the map files;

• Print **Error\n** followed by an explicit error message for invalid maps.

## Bonus

• Wall collision;

• Minimap system;

• Doors which can be open and close;

• Animated sprite;

• Rotate the point of view with the mouse.

## Extra Features

Since this project scrached the right itch, I couldn't miss the opportunity to add a few bonuses of my own

• A NPC;

• A quest with a quest log system;

• Enemies that chase the player until they are defeated;

• HUD bar with multiple menu options, such as:
   - Quest log;
   - Inventory;
   - Minimap;
   - Character information (roleplay);
   - Character status (roleplay);
   - Animated interaction button.
   - Shadow applied to walls, sprites, floor and ceiling

• Visual feedback when the player takes damage.


## Requirements

### Minilibx
Install its dependencies:

```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
Clone minilibx repo:
```
$ git clone https://github.com/42Paris/minilibx-linux.git
```
Run the config tool:
```
./configure
```
For more details, check miniLibx repository [`Readme`](https://github.com/42Paris/minilibx-linux).

## Usage

### Mandatory

To compile the program, run:

```
$ make
```

Execute the program, providing the valid map file path
```
$ ./cub3d maps/mandatory/vault_map.cub
```
<img src="https://github.com/dpiza/resources/blob/master/imgs/mandatory.png?raw=true"/>


### Bonus

To compile the program, run:

```
$ make bonus
```

Execute the program, providing the valid map file path
```
$ ./cub3d maps/bonus/vault42.cub
```
<img src="https://github.com/dpiza/resources/blob/master/imgs/bonus.png?raw=true"/>

Controls:
```
[W][A][S][D]: 		move the player
[←][→]:				rotate the camera
[Rclick]+[Mouse]:	rotate the camera
[E]:				interact (use)
[R]:				reload ammo
[ESC]:				close the game
```

## Contribution

This group project was made in partnership with [Henrique Duller](https://github.com/HcDuller)

## License

This work is published under the terms of [42 Unlicense](https://github.com/gcamerli/42unlicense)
