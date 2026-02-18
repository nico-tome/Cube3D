/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:10:11 by ntome             #+#    #+#             */
/*   Updated: 2026/02/18 21:19:39 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "keys_bonus.h"

void	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == KEY_ESC)
		mlx_loop_end(mlx->mlx);
	if (key == KEY_E)
		toggle_door(mlx);
	if (key == KEY_TAB)
	{
		mlx->window_draw_size = mlx->window_size;
		if (mlx->page == GAME)
			mlx->page = EDITOR;
		else
			mlx->page = GAME;
		if (mlx->page == EDITOR)
			mlx->window_draw_size.y = mlx->window_size.y / 2;
		else
			mlx->editor.focus = 0;
	}
	mlx->keys[key] = 1;
}

void	key_up_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	mlx->keys[key] = 0;
}

void	mouse_hook(int button, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->page == EDITOR && mlx->editor.focus && button == 1)
		editor_mouse_click(mlx);
}

void	window_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
}
