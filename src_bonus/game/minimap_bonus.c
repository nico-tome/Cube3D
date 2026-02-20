/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:00:00 by ccouton           #+#    #+#             */
/*   Updated: 2026/02/20 20:05:19 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "raycasting_bonus.h"

void	fill_tile(t_mlx *mlx, int pos, mlx_color color, int tile_num)
{
	t_vec2	vec;

	vec.y = 0;
	while (vec.y < 16)
	{
		vec.x = 0;
		while (vec.x < 16)
		{
			mlx->minimap[pos + (vec.y * (tile_num * 16)) + vec.x] = color;
			vec.x++;
		}
		vec.y++;
	}
}

int	is_empty(char c)
{
	if (ft_strchr("0NSEW", c))
		return (1);
	return (0);
}

mlx_color	get_color_tile(char tile)
{
	mlx_color	color;

	if (tile == 'D')
		color.rgba = 0x00FF55FF;
	if (tile == '1')
		color.rgba = 0x555555FF;
	if (is_empty(tile))
		color.rgba = 0xDDDDDDFF;
	return (color);
}

void	fill_buffer(t_mlx *mlx, t_vec2 camera, int tile_num)
{
	t_vec2		r;
	t_vec2		pos;
	char		tile;
	int			size;
	mlx_color	color;

	r.y = 0;
	pos = dvec2_to_vec2(mlx->player.pos);
	while (r.y < tile_num && r.y < mlx->map.size)
	{
		r.x = 0;
		while (r.x < tile_num)
		{
			size = (int)ft_strlen(mlx->map.map[r.y + camera.y]);
			tile = mlx->map.map[r.y + camera.y][(r.x + camera.x) % size];
			if (r.y + camera.y == (int)pos.y && r.x + camera.x == (int)pos.x)
				color.rgba = 0xFF0000FF;
			else if (r.x + camera.x < size)
				color = get_color_for_tile(tile);
			fill_tile(mlx, r.x * 16 + r.y * ((tile_num * 16) * 16),
				color, tile_num);
			r.x++;
		}
		r.y++;
	}
}

void	draw_minimap(t_mlx *mlx)
{
	int		tile_num;
	int		len;
	t_vec2	camera_pos;

	tile_num = 17;
	len = ft_strlen(mlx->map.map[(int)mlx->player.pos.y]);
	init_minimap(mlx);
	if (mlx->player.pos.x < tile_num / 2)
		camera_pos.x = 0;
	else if (mlx->player.pos.x >= len - tile_num / 2)
		camera_pos.x = len - tile_num;
	else
		camera_pos.x = mlx->player.pos.x - tile_num / 2;
	if (mlx->player.pos.y < tile_num / 2)
		camera_pos.y = 0;
	else if (mlx->player.pos.y >= mlx->map.size - tile_num / 2)
		camera_pos.y = mlx->map.size - tile_num;
	else
		camera_pos.y = mlx->player.pos.y - tile_num / 2;
	fill_buffer(mlx, camera_pos, tile_num);
	mlx_pixel_put_region(mlx->mlx, mlx->win, 0, 0, tile_num * 16,
		tile_num * 16, mlx->minimap);
}
