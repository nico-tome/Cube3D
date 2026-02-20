/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:51:06 by ntome             #+#    #+#             */
/*   Updated: 2026/02/20 19:39:57 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

void	init_editor(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->editor.max_len = 0;
	while (mlx->map.map[i])
	{
		if ((int)ft_strlen(mlx->map.map[i]) > mlx->editor.max_len)
			mlx->editor.max_len = (int)ft_strlen(mlx->map.map[i]);
		i++;
	}
	init_color_list(mlx->window_size.x * ((mlx->window_size.y / 2) + 1),
		&(mlx->editor.part), "0,0,0");
	mlx->editor.brush = '1';
	mlx->editor.brush_hover = '\0';
	mlx->editor.spawn = 1;
	mlx->editor.broken = 0;
	mlx->editor.camera = (t_vec2){.x = 0, .y = 0};
	mlx->editor.focus = 0;
}

void	editor_fill_tile(t_mlx *mlx, t_vec2 pos, mlx_color color)
{
	t_vec2	fill;
	int		tot;

	pos.y *= (mlx->window_size.x * 32);
	pos.y += mlx->window_size.x * 6;
	pos.x *= 32;
	pos.x += 6;
	fill.y = 0;
	while (fill.y < 32)
	{
		fill.x = 0;
		while (fill.x < 32)
		{
			tot = pos.y + pos.x + (fill.y * mlx->window_size.x) + fill.x;
			mlx->editor.part[tot] = color;
			fill.x++;
		}
		fill.y++;
	}
}

void	draw_map(t_mlx *mlx)
{
	t_vec2	read;
	t_vec2	pos;
	char	tile;

	read.y = 0;
	while (read.y < 11 && read.y < mlx->map.size)
	{
		read.x = 0;
		while (read.x < 30)
		{
			pos.x = mlx->editor.camera.x + read.x;
			pos.y = mlx->editor.camera.y + read.y;
			tile = '\0';
			if (pos.x < (int)ft_strlen(mlx->map.map[pos.y]))
				tile = mlx->map.map[pos.y][pos.x];
			editor_fill_tile(mlx, read, get_color_for_tile(tile));
			read.x++;
		}
		read.y++;
	}
}

void	draw_cursor(t_mlx *mlx)
{
	t_vec2	mouse_tile;

	if (mlx->mouse.x > 6 && mlx->mouse.x < 32 * 30 + 6
		&& mlx->mouse.y > mlx->window_size.y / 2 + 3
		&& mlx->mouse.y < mlx->window_size.y - 6)
	{
		mouse_tile.x = (mlx->mouse.x - 6) / 32;
		mouse_tile.y = (mlx->mouse.y - ((mlx->window_size.y / 2) + 3)) / 32;
		if (is_in_map(mlx, mouse_tile))
			editor_fill_tile(mlx, mouse_tile, get_color("204,153,255"));
	}
	else
	{
		mouse_tile.x = (mlx->mouse.x - 6) / 32;
		mouse_tile.y = (mlx->mouse.y - ((mlx->window_size.y / 2) + 3)) / 32;
		is_a_panel_button(mlx, mouse_tile);
	}
}

void	draw_editor(t_mlx *mlx)
{
	char	*txt;
	char	tmp[2];

	draw_map(mlx);
	print_help_editor(mlx);
	draw_cursor(mlx);
	tmp[0] = mlx->editor.brush_hover;
	tmp[1] = '\0';
	txt = ft_strjoin("Brush hover: ", tmp);
	mlx_pixel_put_region(mlx->mlx, mlx->win, 0, (mlx->window_size.y / 2) - 1,
		mlx->window_size.x, (mlx->window_size.y / 2) + 1, mlx->editor.part);
	mlx_string_put(mlx->mlx, mlx->win, mlx->window_size.x - 250,
		mlx->window_size.y - 50, (mlx_color){.rgba = 0x00FF00FF}, txt);
	free(txt);
	tmp[0] = mlx->editor.brush;
	txt = ft_strjoin("Brush selected: ", tmp);
	mlx_string_put(mlx->mlx, mlx->win, mlx->window_size.x - 250,
		mlx->window_size.y - 30, (mlx_color){.rgba = 0x00FF00FF}, txt);
	animate_sprite(mlx);
}
