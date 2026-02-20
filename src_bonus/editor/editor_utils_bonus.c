/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   editor_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:39:59 by ntome             #+#    #+#             */
/*   Updated: 2026/02/18 16:53:54 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "keys_bonus.h"

void	move_editor_camera(t_mlx *mlx)
{
	if (mlx->keys[KEY_W] && mlx->editor.camera.y > 0)
		mlx->editor.camera.y--;
	if (mlx->keys[KEY_S] && mlx->editor.camera.y < mlx->map.size - 11)
		mlx->editor.camera.y++;
	if (mlx->keys[KEY_A] && mlx->editor.camera.x > 0)
		mlx->editor.camera.x--;
	if (mlx->keys[KEY_D] && mlx->editor.camera.x < mlx->editor.max_len - 30)
		mlx->editor.camera.x++;
}

mlx_color	get_color_for_tile(char tile)
{
	mlx_color	color;

	color = get_color("0,0,0");
	if (tile == '1')
		color = get_color("64,64,64");
	if (tile == '0')
		color = get_color("192,192,192");
	if (tile == 'D')
		color = get_color("0,255,0");
	if (tile == 'N')
		color = get_color("153,0,0");
	if (tile == 'S')
		color = get_color("153,76,0");
	if (tile == 'E')
		color = get_color("153,153,0");
	if (tile == 'W')
		color = get_color("0,153,76");
	return (color);
}

int	is_in_map(t_mlx *mlx, t_vec2 pos)
{
	t_vec2	real_pos;

	if (pos.y >= mlx->map.size)
		return (0);
	if (!(mlx->mouse.x > 6 && mlx->mouse.x < 32 * 30 + 6
			&& mlx->mouse.y > mlx->window_size.y / 2 + 3
			&& mlx->mouse.y < mlx->window_size.y - 6))
		return (0);
	real_pos.x = pos.x + mlx->editor.camera.x;
	real_pos.y = pos.y + mlx->editor.camera.y;
	if (real_pos.x < (int)ft_strlen(mlx->map.map[real_pos.y]))
		return (1);
	return (0);
}

void	editor_mouse_click(t_mlx *mlx)
{
	t_vec2	mouse_tile;
	char	tile;

	mouse_tile.x = (mlx->mouse.x - 6) / 32;
	mouse_tile.y = (mlx->mouse.y - ((mlx->window_size.y / 2) + 3)) / 32;
	if (is_in_map(mlx, mouse_tile))
	{
		mouse_tile = vec2_add(mouse_tile, mlx->editor.camera);
		tile = mlx->map.map[mouse_tile.y][mouse_tile.x];
		if (tile != mlx->editor.brush)
		{
			mlx->map.map[mouse_tile.y][mouse_tile.x] = mlx->editor.brush;
			evaluate_changement(mlx, mlx->editor.brush, tile);
		}
	}
	else if (mlx->editor.brush_hover != '\0')
		mlx->editor.brush = mlx->editor.brush_hover;
}

void	print_help_editor(t_mlx *mlx)
{
	editor_fill_tile(mlx, (t_vec2){.x = 38, .y = 1}, get_color("64,64,64"));
	editor_fill_tile(mlx, (t_vec2){.x = 36, .y = 1}, get_color("192,192,192"));
	editor_fill_tile(mlx, (t_vec2){.x = 38, .y = 3}, get_color("153,0,0"));
	editor_fill_tile(mlx, (t_vec2){.x = 36, .y = 3}, get_color("153,76,0"));
	editor_fill_tile(mlx, (t_vec2){.x = 34, .y = 3}, get_color("153,153,0"));
	editor_fill_tile(mlx, (t_vec2){.x = 32, .y = 3}, get_color("0,153,76"));
}
