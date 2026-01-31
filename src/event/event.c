/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:10:11 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 14:39:27 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "keys.h"

void	key_hook(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == KEY_ESC)
		mlx_loop_end(mlx->mlx);
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
	(void)mlx;
	(void)button;
}

void	window_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
}
