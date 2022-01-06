/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:48:02 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 20:48:42 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ray_tracing(t_minirt	*minirt)
{
	t_vplane	*vplane;
	t_coo		coo;
	int			color;

	vplane = get_view_plane((float) WIDTH, (float) HEIGHT, minirt->camera->fov);
	if (!vplane)
		exit_fatal(minirt, "Allocation failed");
	minirt->y_angle = (float) HEIGHT / 2;
	// minirt->y_ray = minirt->y_angle * vplane->y_pixel;
	coo.y = 0;
	while (minirt->y_angle >= (float) -HEIGHT / 2)
	{
		minirt->y_ray = minirt->y_angle * vplane->y_pixel;
		minirt->x_angle = (float) -WIDTH / 2;
		// minirt->x_ray = minirt->x_angle * vplane->x_pixel;
		coo.x = 0;
		while (minirt->x_angle <= (float) WIDTH / 2)
		{
			minirt->x_ray = minirt->x_angle * vplane->x_pixel;
			new_vector(minirt->x_ray, minirt->y_ray, -1.0, &minirt->ray);
			vec_normalized(&minirt->ray);
			color = 0;
			if (plane_intersection(minirt, minirt->ray))
                color = /* rgb_to_hex(minirt->plane->rgb); */ 0x0ff160C;
			mlx_pixel_put(minirt->window->mlx ,minirt->window->win, coo.x, coo.y, color);
			coo.x++;
			minirt->x_angle++;
		}
		coo.y++;
		minirt->y_angle--;
	}
}