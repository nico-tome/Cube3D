/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:50:41 by ntome             #+#    #+#             */
/*   Updated: 2026/02/07 13:18:47 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "raycasting.h"
#include "texture.h"
#include "vector2.h"
#include <math.h>
#include <stdlib.h>

void	init_ray(t_mlx *mlx, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)(mlx->window_size.x) - 1;
	ray->ray_dir.x = mlx->player.rot.x + mlx->player.plane.x * ray->camera_x;
	ray->ray_dir.y = mlx->player.rot.y + mlx->player.plane.y * ray->camera_x;
	ray->map_pos = dvec2_to_vec2(mlx->player.pos);
	if (ray->ray_dir.x == 0.0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0.0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
	init_side_dist(mlx, ray);
}

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
