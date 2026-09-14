_This project has been created as part of the 42 curriculum by vsoares-, biphuyal._

# cub3D

## Description

cub3D is a small first-person 3D engine written in C with the
[MiniLibX](https://github.com/42paris/minilibx-linux) graphics library, in the
spirit of Wolfenstein 3D. It reads a `.cub` scene file describing wall
textures, floor and ceiling colours and a grid map, then lets you walk through
that maze in real time.

The 3D view is built with **raycasting**: for every column of the window a ray
is cast from the player across the 2D grid using the DDA algorithm until it
hits a wall. The distance to that wall, measured perpendicular to the camera
plane to avoid the fish-eye effect, gives the height of the wall slice, and
the exact hit point selects which column of the texture to draw.

### Features

- Raycasting renderer with a textured wall per direction (north, south, east, west)
- Solid floor and ceiling colours
- Frame-rate independent movement and rotation (delta time)
- Wall collisions
- Toggleable minimap showing the player and the field-of-view cone
- Strict `.cub` parser that exits with `Error` and an explicit message on any invalid input

## Instructions

### Requirements

- Linux with X11 (`libx11-dev`, `libxext-dev`, `zlib1g-dev`) or macOS
- `cc`, `make` and `git`

### Compilation

```bash
git clone --recurse-submodules <repository-url> cub3D
cd cub3D
make
```

The libraries (`libs/libft` and MiniLibX) are git submodules; if they were not
cloned, `make` fetches them automatically.

| Rule          | Effect                                         |
| ------------- | ---------------------------------------------- |
| `make`        | Builds the libraries and the `cub3D` binary    |
| `make clean`  | Removes object files                           |
| `make fclean` | Removes object files, the binary and libraries |
| `make re`     | `fclean` then `make`                           |

### Usage

```bash
./cub3D maps/valid/subject.cub
./cub3D --debug maps/valid/subject.cub   # debug output, flat-shaded walls
```

### Controls

| Key           | Action                          |
| ------------- | ------------------------------- |
| `W` `S`       | Move forward / backward         |
| `A` `D`       | Strafe left / right             |
| `←` `→`       | Rotate the camera               |
| `Left Shift`  | Run                             |
| `M`           | Toggle the minimap              |
| `\`           | Enable debug mode               |
| `Esc` / close | Quit                            |

### Scene file (`.cub`)

```
NO ./textures/brick.xpm
SO ./textures/stone.xpm
WE ./textures/wood.xpm
EA ./textures/metal.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

- `NO`, `SO`, `WE`, `EA`: path to an `.xpm` texture for each wall direction.
- `F`, `C`: floor and ceiling colours as `R,G,B`, each value between 0 and 255.
- The six elements can appear in any order and be separated by empty lines,
  but each must appear exactly once and all must come before the map.
- The map is the last element and uses `1` for walls, `0` for floor, spaces
  for empty space, and one of `N`, `S`, `E`, `W` for the player's start
  position and facing direction.
- The map must be closed by walls and cannot contain empty lines.

Example scenes are in `maps/valid`, and scenes that must be rejected are in
`maps/invalid`.

## Resources

- [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html):
  the DDA raycasting and texture mapping approach the renderer is based on.
- [cub3D guide by ibon-ira](https://ibon-ira-cub3d.mintlify.app/): a walkthrough
  of the project, from parsing the scene file to rendering.
- [MiniLibX for Linux](https://github.com/42paris/minilibx-linux): the graphics
  library used for the window, images and events.
- [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm):
  used to draw the minimap's lines.

### Use of AI

AI (Claude) was used as an assistant, not to write the project. It helped
investigate memory reported by Valgrind, which turned out to be internal Xlib
caches allocated by `mlx_mouse_hide` (mouse support was then dropped). It also
reviewed the project against the subject before delivery — norm, allowed
functions, invalid maps and leaks — and helped rewrite this README.
