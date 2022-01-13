/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:08:56 by jobject           #+#    #+#             */
/*   Updated: 2022/01/13 20:10:54 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	button_press(int button, t_minirt *rt)
{
	if (button == ESC)
	{
		mlx_destroy_window(rt->window->mlx, rt->window->win);
		exit(EXIT_FAILURE);
	}
	if (button == UP || button == DOWN)
		scale_diam_rad (button, rt);
	return (1);
}

void	scale_diam_rad(int button, t_minirt *rt)
{
	if (button == UP)
	{
		if (rt->sphere)
			rt->sphere->diameter *= 1.1;
		if (rt->cylinder)
		{
			rt->cylinder->diameter *= 1.1;
			rt->cylinder->height *= 1.1;
		}
	}
	if (button == DOWN)
	{
		if (rt->sphere)
			rt->sphere->diameter /= 1.1;
		if (rt->cylinder)
		{
			rt->cylinder->diameter /= 1.1;
			rt->cylinder->height /= 1.1;
		}
	}
	ray_tracing(rt);
}

static int	close_win(t_window	*window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_FAILURE);
	return (1);
}

void	setup_control(t_minirt *rt)
{
	mlx_hook(rt->window->win, 17, 0, close_win, rt->window);
	mlx_hook(rt->window->win, 2, 1L << 0, button_press, rt);
}

t_window	*win_init(void)
{
	t_window	*window;

	window = (t_window *) malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "./miniRT");
	window->image = NULL;
	return (window);
}
