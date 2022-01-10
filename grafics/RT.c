/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:48:02 by jobject           #+#    #+#             */
/*   Updated: 2022/01/07 19:55:34 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float	compute_light(t_minirt	*minirt, t_coo	vec)
{
	float	i;
	t_coo	light;

	vec_sub(vec, minirt->light->coo, &light);
	i = vec_dot_product(vec, light) / (vec_length(vec) * vec_length(light) * minirt->light->bright);
	if (i && fabsf(i) <= 1 / minirt->light->bright)
		return (i);
	return (1);
}

int	make_shadow(t_minirt	*minirt, t_coo	vec)
{
	float	color;
	float	i;
	t_coo	ray;

	color = 1;
	i = compute_light(minirt, vec);
	if (i == 1)
		return (i);
	vec_sub(vec, minirt->light->coo, &ray);
	vec_normalized(&ray);
	if (plane_intersection(minirt, ray))
		color = i;
	return (color);
}

void	ray_tracing(t_minirt	*minirt)
{
	t_vplane	*vplane;
	t_coo		coo;
	int			color;

	vplane = get_view_plane((float) WIDTH, (float) HEIGHT, minirt->camera->fov);
	if (!vplane)
		exit_fatal(minirt, "Allocation failed");
	make_color(minirt->plane->rgb, &minirt->plane->rgb.color);
	// make_color(minirt->cylinder->rgb, &minirt->cylinder->rgb.color);
	make_color(minirt->sphere->rgb, &minirt->sphere->rgb.color);
	minirt->y_angle = (float) HEIGHT / 2;
	coo.y = 0;
	while (minirt->y_angle >= (float) -HEIGHT / 2)
	{
		minirt->y_ray = minirt->y_angle * vplane->y_pixel;
		minirt->x_angle = (float) -WIDTH / 2;
		coo.x = 0;
		while (minirt->x_angle <= (float) WIDTH / 2)
		{
			minirt->x_ray = minirt->x_angle * vplane->x_pixel;
			new_vector(minirt->x_ray, minirt->y_ray, -1.0, &minirt->ray);
			vec_normalized(&minirt->ray);
			color = 0; // get_ambient_color(minirt->ambient->rgb, minirt->ambient->ratio);
			if (plane_intersection(minirt, minirt->ray))
                color = minirt->plane->rgb.color * compute_light(minirt, minirt->ray);// * acosf(compute_light(minirt, minirt->ray)) * 180 / M_PI; // * make_shadow(minirt, minirt->ray); // * minirt->ambient->ratio;
			// if (cylinder_intersection(minirt, minirt->ray))
			//     color = minirt->cylinder->rgb.color; // * compute_light(minirt, minirt->ray); // * minirt->ambient->ratio;
			if (sphere_intersection(minirt->ray, minirt))
                color = minirt->sphere->rgb.color * compute_light(minirt, minirt->ray);
			mlx_pixel_put(minirt->window->mlx ,minirt->window->win, coo.x, coo.y, color);
			coo.x++;
			minirt->x_angle++;
		}
		coo.y++;
		minirt->y_angle--;
	}
}