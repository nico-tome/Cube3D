/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_convert_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:29:02 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 12:38:37 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2_bonus.h"

t_vec2	dvec2_to_vec2(t_dvec2 dvec2)
{
	t_vec2	vec;

	vec.x = (int)dvec2.x;
	vec.y = (int)dvec2.y;
	return (vec);
}

t_dvec2	vec2_to_dvec2(t_vec2 vec2)
{
	t_dvec2	vec;

	vec.x = (double)vec2.x;
	vec.y = (double)vec2.y;
	return (vec);
}
