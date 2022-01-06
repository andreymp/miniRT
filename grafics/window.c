/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:08:56 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 16:44:46 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int key_hook(int code)
{
    printf("code is %d\n", code);
    return (0);
}

static int button_press(int button, t_window	*window)
{
    if (button == ESC)
    {
        mlx_destroy_window(window->mlx, window->win);
        exit(EXIT_FAILURE);
    }
	return (1);
}

static int close_win(t_window	*window)
{
    mlx_destroy_window(window->mlx, window->win);
    exit(EXIT_FAILURE);
	return (1);
}

static void setup_control(t_window	*window)
{
    mlx_hook(window->win, 17, 0, close_win, window);
    mlx_hook(window->win, 2, 1L << 0, button_press, window);
    mlx_key_hook(window->win, key_hook, NULL);
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
	window->addr = NULL;
	// do_init_image(window);
	setup_control(window);
	return (window);
}
