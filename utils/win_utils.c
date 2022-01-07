/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:28:18 by jobject           #+#    #+#             */
/*   Updated: 2022/01/07 15:18:00 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	make_color(t_rgb	rgb, int	*color)
{
	*color = rgb.r << 16 | rgb.g << 8 | rgb.b;
}

int	get_ambient_color(t_rgb	rgb, float ratio)
{
	rgb.r *= ratio;
	rgb.g *= ratio;
	rgb.b *= ratio;
	make_color(rgb, &rgb.color);
	return (rgb.color);
}

void	my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->size_line + x * (win->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

void	do_init_image(t_window *win)
{
	if (win->image)
		mlx_destroy_image(win->mlx, win->image);
	win->image = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->addr = mlx_get_data_addr(win->image, &win->pixel_bits,
			&win->size_line, &win->endian);
}
