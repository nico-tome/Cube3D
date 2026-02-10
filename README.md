*This project has been created as part of the 42 curriculum by ntome and ccouton*

# Cube3D
Cube3D project from 42 CC

# Description

The project is to re-create the render from the famous game from 1992 [Wolfenstein3D](https://fr.wikipedia.org/wiki/Wolfenstein_3D), using the [raycasting](https://fr.wikipedia.org/wiki/Raycasting) methode.

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
  For rendering we used the lodev article about raycasting.
  
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

We start by initialyze all variables we need:

```c
ray->cameraX = 2 * x / (double)(mlx->window_size.x) - 1;
ray->rayDir.x = mlx->player.rot.x + mlx->player.plane.x * ray->cameraX;
ray->rayDir.y = mlx->player.rot.y + mlx->player.plane.y * ray->cameraX;
ray->mapPos = dvec2_to_vec2(mlx->player.pos);
if (ray->rayDir.x == 0.0)
	ray->deltaDist.x = 1e30;
else
	ray->deltaDist.x = fabs(1 / ray->rayDir.x);
if (ray->rayDir.y == 0.0)
	ray->deltaDist.y = 1e30;
else
	ray->deltaDist.y = fabs(1 / ray->rayDir.y);
ray->hit = 0;
```

After that we perform the dda:

```c
void	dda(t_mlx *mlx, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step.y;
			ray->side = 1;
		}
		if (mlx->map.map[ray->map_pos.y][ray->map_pos.x] == '1')
			ray->hit = 1;
	}
}
```

Like that we have the distance between the wall and the player. After that we can draw the line:

```c
//calculate the height of the wall

void	init_draw(t_mlx *mlx, t_drawing *draw, t_ray *ray)
{
	draw->line_height = (int)(mlx->window_size.y / ray->perp_wall_dist);
	draw->draw_start = -draw->line_height / 2 + mlx->window_size.y / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + mlx->window_size.y / 2;
	if (draw->draw_end >= mlx->window_size.y)
		draw->draw_end = mlx->window_size.y - 1;
	if (ray->side == 1)
	{
		draw->wall_x = mlx->player.pos.x + ray->perp_wall_dist * ray->ray_dir.x;
		if (ray->ray_dir.y > 0)
			draw->texture = mlx->we_wall;
		else
			draw->texture = mlx->ea_wall;
	}
	else
	{
		draw->wall_x = mlx->player.pos.y + ray->perp_wall_dist * ray->ray_dir.y;
		if (ray->ray_dir.x > 0)
			draw->texture = mlx->so_wall;
		else
			draw->texture = mlx->no_wall;
	}
	draw->wall_x -= floor(draw->wall_x);
	draw->step = 1.0 * draw->texture.texture_height / draw->line_height;
}

// draw the line on the screen, first ceiling, then wall, then floor.

void	setup_line(t_mlx *mlx, t_drawing *draw, t_ray *ray, int x)
{
	int		i;

	i = 0;
	while (i < draw->draw_start)
	{
		mlx->draw_line[x + mlx->window_size.x * i] = mlx->ceiling;
		i++;
	}
	draw->tex.x = (int)(draw->wall_x * (double)draw->texture.texture_width);
	if (check_ray_side(ray))
		draw->tex.x = draw->texture.texture_width - draw->tex.x - 1;
	draw->tex_pos = get_tex_pos(mlx, draw);
	while (i <= draw->draw_end)
	{
		draw->tex.y = (int)draw->tex_pos & (draw->texture.texture_height - 1);
		draw->tex_pos += draw->step;
		mlx->draw_line[x + mlx->window_size.x * i] = get_tex_color(mlx, draw);
		i++;
	}
	while (i < mlx->window_size.y)
	{
		mlx->draw_line[x + mlx->window_size.x * i] = mlx->floor;
		i++;
	}
}
```

We loop throght every pixel of the window and this steps again, at the end, we have filled our pixels buffer, so we need to do only one draw call:

```c
void	raycasting(t_mlx *mlx)
{
	int			i;
	t_ray		ray;
	t_drawing	draw;

	i = 0;
	while (i < mlx->window_size.x)
	{
		init_ray(mlx, &ray, i);
		dda(mlx, &ray);
		if (ray.side == 0)
			ray.perp_wall_dist = (ray.side_dist.x - ray.delta_dist.x);
		else
			ray.perp_wall_dist = (ray.side_dist.y - ray.delta_dist.y);
		init_draw(mlx, &draw, &ray);
		setup_line(mlx, &draw, &ray, i);
		i++;
	}
	mlx_pixel_put_region(mlx->mlx, mlx->win, 0, 0, mlx->window_size.x,
		mlx->window_size.y, mlx->draw_line);
}
```
</details>

## 🕹️ Game Stuffs

<details open>
<summary><i>See</i></summary>

For the game stuffs, we have the player movement where we do a little trick to calculate the rotation direction:

```c
rot_s = ROT_SPEED * (mlx->keys[KEY_RIGHT] - mlx->keys[KEY_LEFT]);
```

And here what look like our main loop:

```c
void	loop(void *params)
{
	t_mlx	*mlx;

	mlx = params;
	move_player(mlx);
	mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){.rgba = 0x00FF00FF});
	raycasting(mlx);
}
```
</details>

## 🚪 Exiting / free

<details open>
<summary><i>See</i></summary>

When we exit the game we don't forget to free ou memory and destroy mlx images:

```c
void	free_game(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map.map[i])
	{
		free(mlx->map.map[i]);
		i++;
	}
	if (mlx->we_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->we_wall.texture);
	if (mlx->so_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->so_wall.texture);
	if (mlx->no_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->no_wall.texture);
	if (mlx->ea_wall.texture)
		mlx_destroy_image(mlx->mlx, mlx->ea_wall.texture);
	free(mlx->map.map);
	free(mlx->draw_line);
}

void	free_mlx(t_mlx *mlx)
{
	free_game(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_context(mlx->mlx);
}
```
</details>

---

# Instruction

To run the project, you need to clone this repo:

```bash
git clone git@github.com:nico-tome/Cube3D.git
```

and then compile it with make or make bonus for the bonus project:

```bash
make
make bonus
```

To destroy with objects and executable run:

```bash
make clean
make fclean
```

that will destroy the mandatory and bonus objects and executable.

---

# Resources

For this project we didn't use AI, we use the [lodev tutorial](https://lodev.org/cgtutor/raycasting.html) for the raycasting part. For the textures we found them on [itch](https://itch.io/game-assets/free/tag-textures) and use this [one](https://piiixl.itch.io/textures). Also thanks for [Sacha](https://github.com/TFHD), [cmorel](https://github.com/xrayxv9) and other for theire freedbacks and tips.
