/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:20:55 by ntome             #+#    #+#             */
/*   Updated: 2026/02/07 13:18:18 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "raycasting.h"
#include "vector2.h"

void	init_side_dist(t_mlx *mlx, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (mlx->player.pos.x - ray->map_pos.x);
		ray->side_dist.x *= ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0 - mlx->player.pos.x);
		ray->side_dist.x *= ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (mlx->player.pos.y - ray->map_pos.y);
		ray->side_dist.y *= ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0 - mlx->player.pos.y);
		ray->side_dist.y *= ray->delta_dist.y;
	}
}

int	check_ray_side(t_ray *ray)
{
	if ((ray->side == 0 && ray->ray_dir.x > 0)
		|| (ray->side == 1 && ray->ray_dir.y < 0))
		return (1);
	return (0);
}

double	get_tex_pos(t_mlx *mlx, t_drawing *draw)
{
	double	result;

	result = draw->draw_start - mlx->window_size.y / 2 + draw->line_height / 2;
	result *= draw->step;
	return (result);
}

mlx_color	get_tex_color(t_mlx *mlx, t_drawing *draw)
{
	mlx_color	color;

	color = mlx_get_image_pixel(mlx->mlx,
			draw->texture.texture,
			draw->tex.x, draw->tex.y);
	return (color);
}
