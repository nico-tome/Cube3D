/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:01:08 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 10:20:43 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parsing.h"
#include "texture.h"

void	init_color_list(int size, mlx_color **list, char *color)
{
	int	i;

	*list = malloc(sizeof(mlx_color) * size);
	if (!*list)
	{
		printf("Malloc Error in init_textures.c at line 20.\n");
		return ;
	}
	i = 0;
	while (i < size)
	{
		(*list)[i] = get_color(color);
		i++;
	}
}

void	init_textures(t_mlx *mlx, t_parsing_infos *parsing)
{
	mlx->floor = get_color(parsing->floor_color);
	mlx->ceiling = get_color(parsing->ceiling_color);
	init_color_list(mlx->window_size.y, &(mlx->drawing_line), "0,0,0");
}
