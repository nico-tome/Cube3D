/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:50:41 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 14:22:58 by ntome            ###   ########.fr       */
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
} 

void	setup_line(t_mlx *mlx, t_drawing *draw, t_ray *ray)
{
	int			i;

	i = 0;
	while (i < draw->drawStart)
	{
		mlx->drawing_line[i] = mlx->ceiling;
		i++;
	}
	while (i < draw->drawEnd)
	{
		if (ray->side == 1)
			mlx->drawing_line[i] = get_color("0,0,255,255");
		else
			mlx->drawing_line[i] = get_color("0,255,0,255");
		i++;
	}
	while (i < mlx->window_size.y)
	{
		mlx->drawing_line[i] = mlx->floor;
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
		setup_line(mlx, &draw, &ray);
		mlx_pixel_put_region(mlx->mlx, mlx->win, i, 0, 1,
			mlx->window_size.y, mlx->drawing_line);
		i++;
	}
}
