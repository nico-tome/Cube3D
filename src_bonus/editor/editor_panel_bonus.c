/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_panel_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:35:18 by ntome             #+#    #+#             */
/*   Updated: 2026/02/19 16:54:54 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d_bonus.h"
#include "vector2_bonus.h"

int	is_a_panel_button(t_mlx *mlx, t_vec2 tile)
{
	mlx->editor.brush_hover = '\0';
	if (tile.x == 38 && tile.y == 1)
		mlx->editor.brush_hover = '1';
	else if (tile.x == 36 && tile.y == 1)
		mlx->editor.brush_hover = '0';
	else if (tile.x == 38 && tile.y == 3)
		mlx->editor.brush_hover = 'N';
	else if (tile.x == 36 && tile.y == 3)
		mlx->editor.brush_hover = 'S';
	else if (tile.x == 34 && tile.y == 3)
		mlx->editor.brush_hover = 'E';
	else if (tile.x == 32 && tile.y == 3)
		mlx->editor.brush_hover = 'W';
	return (mlx->editor.brush_hover != '\0');
}
