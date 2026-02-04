/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <nicolas@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:25:30 by ntome             #+#    #+#             */
/*   Updated: 2026/01/28 19:10:02 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_button.h"

t_button_theme	*get_theme_to_use(t_macro_button button)
{
	if (button.disabled)
		return (button.disabled_theme);
	else if (button.hover && button.clicked)
		return (button.hover_pressed_theme);
	else if (button.hover && !button.clicked)
		return (button.hover_theme);
	else if (!button.hover && button.clicked)
		return (button.pressed_theme);
	else
		return (button.normal_theme);
}

void	put_string_on_button(mlx_context mlx, mlx_window win,
	t_macro_button button, t_button_theme *theme)
{
	t_vec2		center_pos;
	t_vec2		size;
	t_vec2		text_size;

	text_size.x = (theme->font_scale.x
			* strlen(theme->text) + 3 * (strlen(theme->text) - 1));
	text_size.y = theme->font_scale.y;
	center_pos.x = button.pos.x + theme->border_size;
	center_pos.y = button.pos.y + theme->border_size;
	size.x = button.size.x - theme->border_size * 2;
	size.y = button.size.y - theme->border_size * 2;
	mlx_string_put(mlx, win,
		center_pos.x + size.x / 2 - text_size.x / 2,
		center_pos.y + size.y / 2 + text_size.y / 2,
		theme->text_color, theme->text);
}

void	render_button(mlx_context mlx, mlx_window win, t_macro_button button)
{
	t_button_theme	*theme;
	mlx_color		*background;
	int				i;

	theme = get_theme_to_use(button);
	if (!theme || button.hide)
		return ;
	background = malloc(sizeof(mlx_color) * (button.size.x * button.size.y));
	if (!background)
		return ;
	i = -1;
	while (++i < button.size.x * button.size.y)
		background[i] = theme->border_color;
	mlx_pixel_put_region(mlx, win, button.pos.x, button.pos.y, button.size.x,
		button.size.y, background);
	i = -1;
	while (++i < button.size.x * button.size.y)
		background[i] = theme->core_color;
	mlx_pixel_put_region(mlx, win, button.pos.x + theme->border_size,
		button.pos.y + theme->border_size,
		button.size.x - theme->border_size * 2,
		button.size.y - theme->border_size * 2, background);
	if (theme->text)
		put_string_on_button(mlx, win, button, theme);
	free(background);
}

int	is_hover(mlx_context mlx, t_macro_button *button)
{
	t_vec2	mouse_pos;

	mlx_mouse_get_pos(mlx, &mouse_pos.x, &mouse_pos.y);
	if (mouse_pos.x >= button->pos.x
		&& mouse_pos.x <= button->pos.x + button->size.x)
	{
		if (mouse_pos.y >= button->pos.y
			&& mouse_pos.y <= button->pos.y + button->size.y)
		{
			button->hover = 1;
			return (1);
		}
		else
		{
			button->hover = 0;
			return (0);
		}
	}
	button->hover = 0;
	return (0);
}
