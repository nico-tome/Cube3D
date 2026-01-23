/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:22:41 by ntome             #+#    #+#             */
/*   Updated: 2026/01/23 14:54:13 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "../lib/libft/libft.h"
#include "parsing.h"
# include "vector2.h"

typedef struct	s_game_infos
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	mlx_color	*floor;
	mlx_color	*ceiling;
}				t_game_infos;

typedef struct	s_player
{
	t_dvec2	pos;
	t_dvec2	rot;
	t_dvec2	plane;
	int		vel;
}				t_player;

typedef struct s_mlx
{
	mlx_context		mlx;
	mlx_window		win;
	t_vec2			window_size;
	t_game_infos	game_infos;
	t_player		player;
	t_map			map;
	mlx_color		*floor;
	mlx_color		*ceiling;
	double			time;
	double			old_time;
}				t_mlx;

void	init_player(t_mlx *mlx, t_parsing_infos *parsing);
void	key_hook(int key, void *param);
void	mouse_hook(int button, void *param);
void	window_hook(int event, void *param);
void	free_game(t_mlx *mlx);
void	render_floor_ceiling(t_mlx *mlx, int w, int h);

#endif
