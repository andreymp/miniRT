/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:10:52 by jobject           #+#    #+#             */
/*   Updated: 2022/01/10 21:36:17 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int			c_add(int c1, int c2)
{
	int		r;
	int		g;
	int		b;

	r = (c1 >> 16) + (c2 >> 16);
	g = (c1 >> 8 & 255) + (c2 >> 8 & 255);
	b = (c1 & 255) + (c2 & 255);
	return ((r << 16) | (g << 8) | b);
}

int	scale_colors(t_rgb	rgb, float	f)
{
	return ((int) (rgb.r * f) << 16 | (int) (rgb.g * f) << 8 | (int) (rgb.b * f));
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
