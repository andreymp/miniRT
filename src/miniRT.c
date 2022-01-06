/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:19:14 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 12:38:29 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	mini_rt(t_minirt	*minirt)
{
	mlx_put_image_to_window(minirt->window->mlx, minirt->window->win,
		minirt->window->image, 0, 0);
	mlx_loop(minirt->window->mlx);
}
