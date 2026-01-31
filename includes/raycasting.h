/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:03:39 by ntome             #+#    #+#             */
/*   Updated: 2026/01/30 15:21:55 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "vector2.h"
# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"

typedef struct	s_ray
{
	double	cameraX;
	double	perpWallDist;
	t_dvec2	rayDir;
	t_vec2	mapPos;
	t_dvec2	sideDist;
	t_dvec2	deltaDist;
	t_vec2	step;
	int		hit;
	int		side;
	int		draw;
}				t_ray;

typedef struct	s_drawing
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
}				t_drawing;

#endif
