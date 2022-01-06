/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:19:14 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 18:00:25 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	mini_rt(t_minirt	*minirt)
{
	// t_coo	coo;

	// coo.x = 0;
	// while (coo.x < WIDTH)
	// {
	// 	coo.y = 0;
	// 	while (coo.y < HEIGHT)
	// 	{
	// 		draw_sphere(minirt, coo);
	// 		draw_plane(minirt, coo);
	// 		coo.y++;
	// 	}
	// 	coo.x++;
	// }
	ray_tracing(minirt);
	// mlx_put_image_to_window(minirt->window->mlx, minirt->window->win,
	// 	minirt->window->image, 0, 0);
	mlx_loop(minirt->window->mlx);
}
