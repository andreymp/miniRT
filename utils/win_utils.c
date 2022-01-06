/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:28:18 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 20:48:19 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static char	*to_hex(int	digit, char	*set)
{
	char	*hex;

	hex = (char *) malloc(2 * sizeof(char));
	if (!hex)
		return (NULL);
	if (digit < 16)
	{
		*hex = '0';
		*(hex + 1) = *(set + digit); 
	}
	else
	{
		*hex = *(set + digit % 16);
		digit /= 16;
		*(hex + 1) = *(set + digit);
	}
	return (hex);
}

int	rgb_to_hex(t_rgb	rgb)
{
	char	*r;
	char	*g;
	char	*b;
	char	*res;
	int		hex;

	res = NULL;
	r = to_hex(rgb.r, "0123456789abcdef");
	g = to_hex(rgb.g, "0123456789abcdef");
	b = to_hex(rgb.b, "0123456789abcdef");
	res = ft_strjoingnl(res, "0x0");
	res = ft_strjoingnl(res, r);
	free(r);
	res = ft_strjoingnl(res, g);
	free(g);
	res = ft_strjoingnl(res, b);
	free(b);
	hex = (int) res;
	free(res);
	return (hex);
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
