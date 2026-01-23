/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <nicolas@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 20:33:47 by ntome             #+#    #+#             */
/*   Updated: 2026/01/23 13:49:12 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "cube3d.h"

static void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

int	is_correct_color(char *color)
{
	char	**rgb;
	t_vec2	vec2;
	int		is_correct;

	is_correct = 1;
	vec2.x = 0;
	rgb = ft_split(color, ',');
	while (rgb[vec2.x])
	{
		vec2.y = 0;
		while (rgb[vec2.x][vec2.y])
		{
			if (!ft_isdigit(rgb[vec2.x][vec2.y]))
				is_correct = 0;
			vec2.y++;
		}
		vec2.x++;
	}
	free_list(rgb);
	return (is_correct);
}

mlx_color	get_color(char *str)
{
	char		**rgb;
	mlx_color	color;

	rgb = ft_split(str, ',');
	color.a = (uint8_t)255;
	color.r = (uint8_t)ft_atoi(rgb[0]);
	color.g = (uint8_t)ft_atoi(rgb[1]);
	color.b = (uint8_t)ft_atoi(rgb[2]);
	free_list(rgb);
	return (color);
}

void	new_texture(mlx_context mlx, t_texture *texture, char *path)
{
	texture->texture = mlx_new_image_from_file(mlx,
			path,
			&texture->texture_width,
			&texture->texture_height);
}
