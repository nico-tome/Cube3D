# Cube3D
Cube3D project from 42 CC

# Description

This project can be split in 4 parts:

- Parsing + checking
- Rendering (raycasting)
- Game stuffs
- Exiting / free

## Parsing

For the parsing we do 3 steps:

### Reading

First we read ou .cub file and load all the stuffs it contains, like that, we don't leak with our custom gnl.
All the datas are stored in a `s_parsing_infos` structure. We store everything in the `raw_datas` section of that structure.

### Cleaning

After the first reading, we parse the `raw_datas` again and try to assigne every line to a data we need (ex: `no_path`, `map` etc...). We will use that later to check and load our datas in the game.

### Checking

Lastely, we will look if every infos as a data in it, if not we throw an error and exit. If we have a data, we check id this data is valid or not. If not we throw an error and exit. If everything is ok, we load the data into ou game.

### Exiting

If we have an error we will free every datas we have stored.
