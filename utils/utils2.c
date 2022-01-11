/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:10:52 by jobject           #+#    #+#             */
/*   Updated: 2022/01/11 17:21:07 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	check_color(int	*portion)
{
	if (*portion < 0)
		*portion = 0;
	else if (*portion > 255)
		*portion = 255;
}

int			c_add(int c1, int c2)
{
	int		r;
	int		g;
	int		b;

	r = (c1 >> 16) + (c2 >> 16);
	check_color(&r);
	g = (c1 >> 8 & 255) + (c2 >> 8 & 255);
	check_color(&g);
	b = (c1 & 255) + (c2 & 255);
	check_color(&b);
	return ((r << 16) | (g << 8) | b);
}

int	scale_int(int color, float f)
{
	int	r;
	int	g;
	int	b;

	r = f * (color >> 16);
	check_color(&r);
	g = f * ((color >> 8) & 255);
	check_color(&g);
	b = f * (color & 255);
	check_color(&b);
	return (r << 16 | g << 8 | b);
}

int	scale_colors(t_rgb	rgb, float	f)
{
	int	color;

	make_color(rgb, &color);
	return (scale_int(color, f));
}

int	prod_colors(int color1, int color2)
{
	int	r;
	int	g;
	int	b;

	r = ((float) (color1 >> 16) / 255) * ((float) (color2 >> 16) / 255) * 255;
	g = ((float)( (color1 >> 8) & 255) / 255) * ((float) ((color2 >> 8) & 255) / 255) * 255;
	b = ((float) (color1 & 255) / 255) * ((float) (color2 & 255) / 255) * 255;
	return ((r << 16) | (g << 8) | b);
}
