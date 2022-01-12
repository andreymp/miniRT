/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:48:02 by jobject           #+#    #+#             */
/*   Updated: 2022/01/12 19:51:58 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	inter(t_minirt	*minirt, t_coo	vec, int	*color)
{
	bool		flag;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;


	pl = minirt->plane;
	sp = minirt->sphere;
	cy = minirt->cylinder;
	flag = false;
	while (pl)
	{
		flag |= plane_intersection(minirt, pl, vec, color);
		pl = pl->next;		
	}
	while (sp)
	{
		flag |= sphere_intersection(vec, minirt, sp, color);
		sp = sp->next;
	}
	while (cy)
	{
		flag |= cylinder_intersection(minirt, cy, vec, color);
		cy = cy->next;
	}
	return (flag);
}

bool	in_shadow(t_minirt	*minirt, int	*color)
{
	t_coo	shadow;

	vec_sub(minirt->light->coo, vec_mul(minirt->ray, minirt->ray.len), &shadow);
	vec_normalized(&shadow);
	return (inter(minirt, shadow, color));
}


void	ray_tracing(t_minirt	*minirt)
{
	t_vplane	*vplane;
	t_scene		*scene;
	t_coo		coo;
	int			color;

	scene = init_scene(minirt);
	if (!scene)
		exit_fatal(minirt, "Allocation failed");
	vplane = get_view_plane(scene->width, scene->height, minirt->camera->fov);
	if (!vplane)
		exit_fatal(minirt, "Allocation failed");
	make_color(minirt->ambient->rgb, &minirt->ambient->rgb.color);
	minirt->y_angle = scene->height / 2;
	coo.y = 0;
	while (minirt->y_angle >= -scene->height / 2)
	{
		minirt->y_ray = minirt->y_angle * vplane->y_pixel;
		minirt->x_angle = -scene->width / 2;
		coo.x = 0;
		while (minirt->x_angle <= scene->width / 2)
		{
			minirt->x_ray = minirt->x_angle * vplane->x_pixel;
			new_vector(minirt->x_ray, minirt->y_ray, -1.0, &minirt->ray);
			minirt->ray.len = vec_length(minirt->ray);
			vec_normalized(&minirt->ray);
			color = 0;
			if (inter(minirt, minirt->ray, &scene->color))
			{
				color = prod_colors(scale_int(minirt->ambient->rgb.color, minirt->ambient->ratio), scene->color);
				color = c_add(color, compute_light(minirt, minirt->ray, scene->color));
			}
			mlx_pixel_put(minirt->window->mlx ,minirt->window->win, coo.x, coo.y, color);
			coo.x++;
			minirt->x_angle++;
		}
		coo.y++;
		minirt->y_angle--;
	}
}