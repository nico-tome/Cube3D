/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <nicolas@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:01:20 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 10:20:56 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "parsing.h"
# include "cube3d.h"

typedef struct	s_texture
{
	mlx_image	texture;
	int			texture_width;
	int			texture_height;
}				t_texture;

typedef struct	s_textures
{
	t_texture	wall_no;
	t_texture	wall_so;
	t_texture	wall_ea;
	t_texture	wall_we;
	mlx_color	floor_color;
	mlx_color	ceiling_color;
}				t_textures;

int			is_correct_color(char *color);
mlx_color	get_color(char *color);
void		new_texture(mlx_context mlx, t_texture *texture, char *path);
void		free_texture(t_texture *texture);
void		init_textures(t_mlx *mlx, t_parsing_infos *parsing);

#endif
