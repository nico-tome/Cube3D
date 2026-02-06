/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:50:41 by ntome             #+#    #+#             */
/*   Updated: 2026/02/06 19:48:24 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "raycasting_bonus.h"
#include "texture_bonus.h"
#include "vector2_bonus.h"
#include <math.h>
#include <stdlib.h>

void	init_ray(t_mlx *mlx, t_ray *ray, int x)
{
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
	if (ray->rayDir.x < 0)
	{
		ray->step.x = -1;
		ray->sideDist.x = (mlx->player.pos.x - ray->mapPos.x) * ray->deltaDist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sideDist.x = (ray->mapPos.x + 1.0 - mlx->player.pos.x) * ray->deltaDist.x;
	}
	if (ray->rayDir.y < 0)
	{
		ray->step.y = -1;
		ray->sideDist.y = (mlx->player.pos.y - ray->mapPos.y) * ray->deltaDist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sideDist.y = (ray->mapPos.y + 1.0 - mlx->player.pos.y) * ray->deltaDist.y;
	}
}

void	dda(t_mlx *mlx, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->sideDist.x < ray->sideDist.y)
		{
			ray->sideDist.x += ray->deltaDist.x;
			ray->mapPos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sideDist.y += ray->deltaDist.y;
			ray->mapPos.y += ray->step.y;
			ray->side = 1;
		}
		if (mlx->map.map[ray->mapPos.y][ray->mapPos.x] == '1')
			ray->hit = 1;
	}
}

void	init_draw(t_mlx *mlx, t_drawing *draw, t_ray *ray)
{
	draw->lineHeight = (int)(mlx->window_size.y / ray->perpWallDist);
	draw->drawStart = -draw->lineHeight / 2 + mlx->window_size.y / 2;
	if (draw->drawStart < 0)
		draw->drawStart = 0;
	draw->drawEnd = draw->lineHeight / 2 + mlx->window_size.y / 2;
	if (draw->drawEnd >= mlx->window_size.y)
		draw->drawEnd = mlx->window_size.y - 1;
	if (ray->side == 1)
	{
		draw->wallX = mlx->player.pos.x + ray->perpWallDist * ray->rayDir.x;
		if (ray->rayDir.y > 0)
			draw->texture = mlx->we_wall;
		else
			draw->texture = mlx->ea_wall;
	}
	else
	{
		draw->wallX = mlx->player.pos.y + ray->perpWallDist * ray->rayDir.y;
		if (ray->rayDir.x > 0)
			draw->texture = mlx->so_wall;
		else
			draw->texture = mlx->no_wall;
	}
	draw->wallX -= floor(draw->wallX);
	draw->step = 1.0 * draw->texture.texture_height / draw->lineHeight;
} 

void	setup_line(t_mlx *mlx, t_drawing *draw, t_ray *ray, int x)
{
	int		i;

	i = 0;
	while (i < draw->drawStart)
	{
		mlx->drawing_line[x + mlx->window_size.x * i] = mlx->ceiling;
		i++;
	}
	draw->tex.x = (int)(draw->wallX * (double)draw->texture.texture_width);
	if ((ray->side == 0 && ray->rayDir.x > 0) || (ray->side == 1 && ray->rayDir.y < 0))
		draw->tex.x = draw->texture.texture_width - draw->tex.x - 1;
	draw->texPos = (draw->drawStart - mlx->window_size.y / 2 + draw->lineHeight / 2) * draw->step;
	while (i <= draw->drawEnd)
	{
		draw->tex.y = (int)draw->texPos & (draw->texture.texture_height - 1);
		draw->texPos += draw->step;
		mlx->drawing_line[x + mlx->window_size.x * i] = mlx_get_image_pixel(mlx->mlx, draw->texture.texture, draw->tex.x, draw->tex.y);
		i++;
	}
	while (i < mlx->window_size.y)
	{
		mlx->drawing_line[x + mlx->window_size.x * i] = mlx->floor;
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
			ray.perpWallDist = (ray.sideDist.x - ray.deltaDist.x);
		else
			ray.perpWallDist = (ray.sideDist.y - ray.deltaDist.y);
		init_draw(mlx, &draw, &ray);
		setup_line(mlx, &draw, &ray, i);
		i++;
	}
	mlx_pixel_put_region(mlx->mlx, mlx->win, 0, 0, mlx->window_size.x,
		mlx->window_size.y, mlx->drawing_line);
}
