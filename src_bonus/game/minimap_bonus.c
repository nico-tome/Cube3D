/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouton <ccouton@42angouleme.fr>          +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:00:00 by ccouton         #+#    #+#               */
/*   Updated: 2026/02/15 00:00:00 by ccouton        ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "raycasting_bonus.h"

static void	draw_cell(t_mlx *mlx, int row, int col, int block_size)
{
	int			x;
	int			y;
	mlx_color	c;

	if (mlx->map.map[row][col] == '1')
		c.rgba = 0x555555FF;
	else if (mlx->map.map[row][col] == '0')
		c.rgba = 0xDDDDDDFF;
	else
		c.rgba = 0xFFFFFFFF;
	x = 0;
	while (x < block_size)
	{
		y = 0;
		while (y < block_size)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, col * block_size + x,
				row * block_size + y, c);
			y++;
		}
		x++;
	}
}

static void	draw_grid(t_mlx *mlx, int width, int height, int block_size)
{
	int	row;
	int	col;

	row = 0;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			draw_cell(mlx, row, col, block_size);
			col++;
		}
		row++;
	}
}

static void	draw_player(t_mlx *mlx, t_player *p, int block_size)
{
	int			x;
	int			y;
	int			px;
	int			py;
	mlx_color	c;

	px = p->pos.x * block_size;
	py = p->pos.y * block_size;
	c.rgba = 0xFF0000FF;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, px + x, py + y, c);
			y++;
		}
		x++;
	}
}

void	draw_minimap(t_mlx *mlx, t_game_infos *game, t_player *player)
{
	int	map_width;
	int	map_height;
	int	block_size;

	(void)game;
	if (!mlx->map.map || !mlx->map.map[0])
		return ;
	map_width = 0;
	map_height = 0;
	while (mlx->map.map[0][map_width])
		map_width++;
	while (mlx->map.map[map_height])
		map_height++;
	block_size = 8;
	draw_grid(mlx, map_width, map_height, block_size);
	if (player)
		draw_player(mlx, player, block_size);
}
