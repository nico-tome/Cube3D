/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:06:59 by ntome             #+#    #+#             */
/*   Updated: 2026/02/10 00:11:39 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "raycasting_bonus.h"

mlx_color	get_ceiling_cell(t_mlx *mlx, t_dvec2 floor)
{
	t_vec2	cell;
	t_vec2	t;

	cell = dvec2_to_vec2(floor);
	t.x = (int)(mlx->textures.ceiling.texture_width * (floor.x - cell.x));
	t.y = (int)(mlx->textures.ceiling.texture_height * (floor.y - cell.y));
	t.x &= (mlx->textures.ceiling.texture_width - 1);
	t.y &= (mlx->textures.ceiling.texture_height - 1);
	return (mlx_get_image_pixel(
			mlx->mlx,
			mlx->textures.ceiling.texture,
			t.x,
			t.y));
}

mlx_color	get_ceiling(t_mlx *mlx, int x, int y)
{
	t_dvec2	ray_dir1;
	t_dvec2	ray_dir2;
	t_dvec2	floor_s;
	t_dvec2	floor;
	t_dvec2	data;

	ray_dir1.x = mlx->player.rot.x - mlx->player.plane.x;
	ray_dir1.y = mlx->player.rot.y - mlx->player.plane.y;
	ray_dir2.x = mlx->player.rot.x + mlx->player.plane.x;
	ray_dir2.y = mlx->player.rot.y + mlx->player.plane.y;
	data.y = mlx->window_size.y - y - 1;
	data.x = (0.5 * mlx->window_size.y)
		/ (data.y - mlx->window_size.y / 2);
	floor_s.x = data.x * (ray_dir2.x - ray_dir1.x)
		/ mlx->window_size.x;
	floor_s.y = data.x * (ray_dir2.y - ray_dir1.y)
		/ mlx->window_size.x;
	floor.x = mlx->player.pos.x + data.x * ray_dir1.x;
	floor.y = mlx->player.pos.y + data.x * ray_dir1.y;
	floor.x += floor_s.x * x;
	floor.y += floor_s.y * x;
	return (get_ceiling_cell(mlx, floor));
}

mlx_color	get_floor_cell(t_mlx *mlx, t_dvec2 floor)
{
	t_vec2	cell;
	t_vec2	t;

	cell = dvec2_to_vec2(floor);
	t.x = (int)(mlx->textures.floor.texture_width * (floor.x - cell.x));
	t.y = (int)(mlx->textures.floor.texture_height * (floor.y - cell.y));
	t.x &= (mlx->textures.floor.texture_width - 1);
	t.y &= (mlx->textures.floor.texture_height - 1);
	return (mlx_get_image_pixel(
			mlx->mlx,
			mlx->textures.floor.texture,
			t.x,
			t.y));
}

mlx_color	get_floor(t_mlx *mlx, int x, int y)
{
	t_dvec2	ray_dir1;
	t_dvec2	ray_dir2;
	t_dvec2	floor_s;
	t_dvec2	floor;
	double	row_distance;

	ray_dir1.x = mlx->player.rot.x - mlx->player.plane.x;
	ray_dir1.y = mlx->player.rot.y - mlx->player.plane.y;
	ray_dir2.x = mlx->player.rot.x + mlx->player.plane.x;
	ray_dir2.y = mlx->player.rot.y + mlx->player.plane.y;
	row_distance = (0.5 * mlx->window_size.y) / (y - mlx->window_size.y / 2);
	floor_s.x = row_distance * (ray_dir2.x - ray_dir1.x) / mlx->window_size.x;
	floor_s.y = row_distance * (ray_dir2.y - ray_dir1.y) / mlx->window_size.x;
	floor.x = mlx->player.pos.x + row_distance * ray_dir1.x;
	floor.y = mlx->player.pos.y + row_distance * ray_dir1.y;
	floor.x += floor_s.x * x;
	floor.y += floor_s.y * x;
	return (get_floor_cell(mlx, floor));
}
