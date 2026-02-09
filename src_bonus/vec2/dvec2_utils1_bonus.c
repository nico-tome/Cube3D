/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec2_utils1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:13:57 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 12:38:04 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2_bonus.h"

void	set_dvec2(t_dvec2 *dvec2, double x, double y)
{
	dvec2->x = x;
	dvec2->y = y;
}

t_dvec2	dvec2_add(t_dvec2 v_1, t_dvec2 v_2)
{
	t_dvec2	result;

	result.x = v_1.x + v_2.x;
	result.y = v_1.y + v_2.y;
	return (result);
}

t_dvec2	dvec2_sub(t_dvec2 v_1, t_dvec2 v_2)
{
	t_dvec2	result;

	result.x = v_1.x - v_2.x;
	result.y = v_1.y - v_2.y;
	return (result);
}

t_dvec2	dvec2_mul(t_dvec2 v_1, t_dvec2 v_2)
{
	t_dvec2	result;

	result.x = v_1.x * v_2.x;
	result.y = v_1.y * v_2.y;
	return (result);
}

t_dvec2	dvec2_div(t_dvec2 v_1, t_dvec2 v_2)
{
	t_dvec2	result;

	if (v_2.x == 0 || v_2.y == 0)
	{
		printf("Vector 2, try a division by 0, return v_1.\n");
		return (v_1);
	}
	result.x = v_1.x / v_2.x;
	result.y = v_1.y / v_2.y;
	return (result);
}
