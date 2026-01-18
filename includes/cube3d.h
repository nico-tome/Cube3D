/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:22:41 by ntome             #+#    #+#             */
/*   Updated: 2026/01/17 20:49:57 by ntome            ###   ########.fr       */
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
# include "vector2.h"

typedef struct	s_game_infos
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	mlx_color	floor;
	mlx_color	ceiling;
}				t_game_infos;

typedef struct s_mlx
{
	mlx_context		mlx;
	mlx_window		win;
	t_vec2			window_size;
}				t_mlx;

#endif
