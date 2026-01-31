*This project has been created as part of the 42 curriculum by ntome and ccouton*

# Cube3D
Cube3D project from 42 CC

# Description

This project can be split in 4 parts:

- 📖 Parsing + checking
- 🧊 Rendering (raycasting)
- 🕹️ Game stuffs
- 🚪 Exiting / free

---

## 📖 Parsing
<details open>
<summary><i>See</i></summary>

For the parsing we do 3 steps:

### 👓 Reading

First we read ou **.cub** file and load all the datas it contains, like that, we don't leak with our custom gnl.
All the datas are stored in a `s_parsing_infos` structure. We store everything in the `raw_datas` section of that structure.

```h
//parsing.h
typedef struct	s_parsing_infos
{
	t_map	map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_color;
	char	*ceiling_color;
	char	**raw_datas;
	char	*file_extension;
	int		file_size;
	int		fd;
	int		result;
}				t_parsing_infos;
```

### 🚮 Cleaning

After the first reading, we parse the `raw_datas` again and try to assigne every line to a data we need (ex: `no_path`, `map` etc...). We will use that later to check and load our datas in the game.

### ✔️ Checking

Lastely, we will look if every infos as a data in it, if not we throw an error and exit. If we have a data, we check id this data is valid or not. If not we throw an error and exit. If everything is ok, we load the data into ou game.

### 🚪 Exiting

If we have an error we will free every datas we have stored.

<img width="562" height="317" alt="image" src="https://github.com/user-attachments/assets/b37f83d6-15d9-4ce8-9017-0aa6c15f3dcd" />

*A example of valid map*
</details>

## 🧊 Rendering (raycasting)

<details open>
  <summary><i>See</i></summary>
  For rendering we used the [lodev article](https://lodev.org/cgtutor/raycasting.html) about raycasting.
  
  Firs we have a struct that will contain every variables needed to perform our raycast:

  ```h
typedef struct	s_ray
{
	double	cameraX;
	double	perpWallDist;
	t_dvec2	rayDir;
	t_vec2	mapPos;
	t_dvec2	sideDist;
	t_dvec2	deltaDist;
	t_vec2	step;
	int		hit;
	int		side;
	int		draw;
}				t_ray;
  ```
</details>
