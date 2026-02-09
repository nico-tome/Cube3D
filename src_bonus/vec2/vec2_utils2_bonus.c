/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:42:38 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 12:38:31 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2_bonus.h"

int	vec2_is_higher(t_vec2 v_1, t_vec2 v_2)
{
	return (v_1.y > v_2.y);
}

int	vec2_is_lower(t_vec2 v_1, t_vec2 v_2)
{
	return (v_1.y < v_2.y);
}

int	vec2_is_left(t_vec2 v_1, t_vec2 v_2)
{
	return (v_1.x < v_2.x);
}

int	vec2_is_right(t_vec2 v_1, t_vec2 v_2)
{
	return (v_1.x > v_2.x);
}

void	vec2_print(t_vec2 vec2)
{
	printf("Vec2: x: %d, y: %d, adress: %p\n", vec2.x, vec2.y, &vec2);
}
