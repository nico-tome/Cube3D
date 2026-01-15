/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:19:31 by ntome             #+#    #+#             */
/*   Updated: 2026/01/15 18:51:38 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	main(int ac, char **av)
{
	t_game_infos	game_i;

	if (ac != 2)
	{
		printf("ARGS ERROR !\n");
		exit(EXIT_FAILURE);
	}
	if (!parsing(&game_i, av[1]))
	{
		printf("PARSING ERROR !\n");
		exit(EXIT_FAILURE);
	}
}
