/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:12:41 by ntome             #+#    #+#             */
/*   Updated: 2026/01/23 13:22:03 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include <stdio.h>

typedef struct	s_vec2
{
	int	x;
	int	y;
}				t_vec2;

typedef struct	s_dvec2
{
	double	x;
	double	y;
}				t_dvec2;

void	set_vec2(t_vec2 *vec2, int x, int y);
t_vec2	vec2_add(t_vec2 v_1, t_vec2 v_2);
t_vec2	vec2_sub(t_vec2 v_1, t_vec2 v_2);
t_vec2	vec2_mul(t_vec2 v_1, t_vec2 v_2);
t_vec2	vec2_div(t_vec2 v_1, t_vec2 v_2);
int		vec2_is_higher(t_vec2 v_1, t_vec2 v_2);
int		vec2_is_lower(t_vec2 v_1, t_vec2 v_2);
int		vec2_is_left(t_vec2 v_1, t_vec2 v_2);
int		vec2_is_right(t_vec2 v_1, t_vec2 v_2);
void	vec2_print(t_vec2 vec2);

t_dvec2	vec2_to_dvec2(t_vec2 vec2);
t_vec2	dvec2_to_vec2(t_dvec2 dvec2);

void	set_dvec2(t_dvec2 *dvec2, double x, double y);
t_dvec2	dvec2_add(t_dvec2 v_1, t_dvec2 v_2);
t_dvec2	dvec2_sub(t_dvec2 v_1, t_dvec2 v_2);
t_dvec2	dvec2_mul(t_dvec2 v_1, t_dvec2 v_2);
t_dvec2	dvec2_div(t_dvec2 v_1, t_dvec2 v_2);
int		dvec2_is_higher(t_dvec2 v_1, t_dvec2 v_2);
int		dvec2_is_lower(t_dvec2 v_1, t_dvec2 v_2);
int		dvec2_is_left(t_dvec2 v_1, t_dvec2 v_2);
int		dvec2_is_right(t_dvec2 v_1, t_dvec2 v_2);

#endif
