/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_evaluation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:30:49 by ntome             #+#    #+#             */
/*   Updated: 2026/02/19 13:48:36 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"

int	is_spawn_tile(char tile)
{
	if (tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W')
		return (1);
	return (0);
}

void	evaluate_changement(t_mlx *mlx, char tile, char old_tile)
{
	mlx->editor.broken = 0;
	if (!check_close(mlx->map.map))
		mlx->editor.broken = 1;
	if (is_spawn_tile(tile) && !is_spawn_tile(old_tile))
		mlx->editor.spawn++;
	if (!is_spawn_tile(tile) && is_spawn_tile(old_tile))
		mlx->editor.spawn--;
	if (mlx->editor.spawn != 1)
		mlx->editor.broken = 2;
}
