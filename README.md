# Sokoban
Simple Sokoban game created in C++

# Overview
This is a C++ implementation of the classic Sokoban puzzle game, developed as a school project. The game features keyboard controls and a graphical interface powered by the SFML library. Players push boxes onto designated goal tiles to complete levels.

# Features
Grid-based puzzle gameplay

Keyboard controls: arrow keys or WASD to move

Multiple levels loaded from external .lvl files

Smooth rendering with SFML graphics and textures

Win condition detection

Ability to reset the current level with the R key

# Requirements
C++17 compatible compiler (e.g., g++)

SFML library (graphics, window, system) installed and linked

Texture image files (PNG) included in project directory:

block_06.png (wall)

ground_01.png (ground)

ground_04.png (goal)

crate_03.png (box)

player_05.png, player_08.png, player_20.png, player_17.png (player facing directions)

Level files in .lvl format specifying the map layout

# How to Build
Ensure SFML is installed on your system.

Compile with the included Makefile or manually with:
g++ Sokoban.o main.o -o Sokoban -lsfml-graphics -lsfml-window -lsfml-system -Wall -Werror -pedantic

Run the executable with a level file as argument:
./Sokoban level1.lvl

Any levels created should follow this symbol table:
| Symbol | Meaning         | Description                       |
| ------ | --------------- | --------------------------------- |
| `#`    | Wall            | Impassable obstacle               |
| `.`    | Floor / Ground  | Empty space where player can move |
| `a`    | Goal            | Target location for boxes         |
| `@`    | Player on Floor | Player's current position         |
| `2`    | Player on Goal  | Player standing on a goal tile    |
| `A`    | Box on Floor    | Box placed on normal floor        |
| `1`    | Box on Goal     | Box correctly placed on a goal    |


Controls
Move player: Arrow keys or W/A/S/D

Reset level: R key

Close game: Window close button

# Code Structure
main.cpp: Entry point, game loop, input handling, window management

Sokoban.cpp / Sokoban.h: Core game logic, state management, rendering

# Known Issues / Limitations
Levels must be properly formatted and match the expected size

No sound effects or music included

Basic UI without menus or advanced options

# License
This project is provided for educational purposes. Code is for non-commercial use.

Assests used in this game are not owned by me.

Sprites:

	Sokoban (pack)

	by  Kenney Vleugels (Kenney.nl)

			------------------------------

	License (Creative Commons Zero, CC0)

	http://creativecommons.org/publicdomain/zero/1.0/

	You may use these assets in personal and commercial projects.

	Credit (Kenney or www.kenney.nl) would be nice but is not mandatory.

			------------------------------
   
	Donate:   http://support.kenney.nl

	Request:  http://request.kenney.nl

	Follow on Twitter for updates:

	@KenneyNL

Text: 
For displaying the "You win!" text, the file for the font to display the
text was downloaded for free from dafont.com. (SuperMario256.ttf)
