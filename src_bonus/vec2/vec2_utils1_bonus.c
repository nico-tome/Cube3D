/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_utils1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:33:58 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 12:38:17 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2_bonus.h"

void	set_vec2(t_vec2 *vec2, int x, int y)
{
	vec2->x = x;
	vec2->y = y;
}

t_vec2	vec2_add(t_vec2 v_1, t_vec2 v_2)
{
	t_vec2	result;

	result.x = v_1.x + v_2.x;
	result.y = v_1.y + v_2.y;
	return (result);
}

t_vec2	vec2_sub(t_vec2 v_1, t_vec2 v_2)
{
	t_vec2	result;

	result.x = v_1.x - v_2.x;
	result.y = v_1.y - v_2.y;
	return (result);
}

t_vec2	vec2_mul(t_vec2 v_1, t_vec2 v_2)
{
	t_vec2	result;

	result.x = v_1.x * v_2.x;
	result.y = v_1.y * v_2.y;
	return (result);
}

t_vec2	vec2_div(t_vec2 v_1, t_vec2 v_2)
{
	t_vec2	result;

	if (v_2.x == 0 || v_2.y == 0)
	{
		printf("Vector2, try a division by 0. Return v_1.\n");
		return (v_1);
	}
	result.x = v_1.x / v_2.x;
	result.y = v_1.y / v_2.y;
	return (result);
}
