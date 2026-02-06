/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_button.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <nicolas@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:54:30 by ntome             #+#    #+#             */
/*   Updated: 2026/01/28 18:59:29 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BUTTON_H
# define MLX_BUTTON_H

# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/MacroLibX/includes/mlx_extended.h"
# include "vector2.h"
# include <stdlib.h>
# include <string.h>

typedef struct	s_button_theme
{
	mlx_color	core_color;
	mlx_color	border_color;
	int			border_size;
	char		*text;
	mlx_color	text_color;
	t_vec2		font_scale;
}				t_button_theme;

typedef struct	s_macro_button
{
	int			hide;
	int			disabled;
	int			hover;
	int			clicked;
	char		*id;
	t_vec2		pos;
	t_vec2		size;
	t_button_theme	*normal_theme;
	t_button_theme	*hover_theme;
	t_button_theme	*pressed_theme;
	t_button_theme	*hover_pressed_theme;
	t_button_theme	*disabled_theme;
}				t_macro_button;

void			render_button(mlx_context mlx, mlx_window win, t_macro_button button);
int				is_hover(mlx_context mlx, t_macro_button *button);
int				is_clicked(mlx_context mlx, t_macro_button *button);
t_button_theme	*get_theme_to_use(t_macro_button button);

#endif
