/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:50:41 by ntome             #+#    #+#             */
/*   Updated: 2026/01/23 14:52:56 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	render_floor_ceiling(t_mlx *mlx, int w, int h)
{
	mlx_pixel_put_region(mlx->mlx, mlx->win, 0, 0, w, h, mlx->ceiling);
	mlx_pixel_put_region(mlx->mlx, mlx->win, 0, h, w, h, mlx->floor);
}
