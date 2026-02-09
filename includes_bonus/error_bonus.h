/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:50:38 by ntome             #+#    #+#             */
/*   Updated: 2026/02/09 14:30:58 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_BONUS_H
# define ERROR_BONUS_H

# include <stdio.h>
# include "vector2_bonus.h"

void	print_error(void);
void	error_file_not_found(char *path);
void	error_load_file(char *path);
void	error_invalid_extension(char *extension);
void	error_invalid_color(char *color);
void	error_invalid_tile(char tile, t_vec2 pos);

#endif