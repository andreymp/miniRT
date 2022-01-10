/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:48:02 by jobject           #+#    #+#             */
/*   Updated: 2022/01/10 21:33:50 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	inter(t_minirt	*minirt, t_coo	vec, int	*color)
{
	bool		flag;
	t_plane		*pl;
	t_sphere	*sp;
	// t_cylinder	*cy;


	pl = minirt->plane;
	sp = minirt->sphere;
	// cy = minirt->cylinder;
	flag = false;
	// while (sp)
	// {
	// 	flag |= sphere_intersection(vec, minirt, color);
	// 	sp = sp->next;
	// }
	while (pl)
	{
		flag |= plane_intersection(minirt, vec, color);
		pl = pl->next;		
	}
	while (sp)
	{
		flag |= sphere_intersection(vec, minirt, color);
		sp = sp->next;
	}
	return (flag);
}

bool	is_shadow(t_minirt	*minirt)
{
 	t_coo	ori;
	t_coo	dir;
	t_coo	shadow;
	int		timmy;

 	new_vector(minirt->ray.x * minirt->ray.len * minirt->ray.x * 1e-4
	 	, minirt->ray.y * minirt->ray.len * minirt->ray.y * 1e-4
		, minirt->ray.z * minirt->ray.len * minirt->ray.z * 1e-4, &ori);
	vec_sub(minirt->light->coo, ori, &dir);
	vec_normalized(&dir);
	vec_sub(dir, ori, &shadow);
 	return (inter(minirt, shadow, &timmy));
}

float	compute_light(t_minirt	*minirt, t_coo	vec, int color)
{
	t_coo	nl;
	float	len;
	float	gain;
	float	coeff;

	vec.x *= vec.len;
	vec.y *= vec.len;
	vec.z *= vec.len;
	vec_sub(minirt->light->coo, vec, &nl);
	len = powf(vec_length(nl), 2);
	vec_normalized(&nl);
	vec_normalized(&vec);
	gain = vec_dot_product(nl, vec);
	// printf("%f\n", gain);
	coeff = 0;
	if (gain > 0)
		coeff = minirt->light->bright * fabsf(gain) * 1000 / (4.0 * M_PI * len);
	return (color * coeff);
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
	// make_color(minirt->plane->rgb, &minirt->plane->rgb.color);
	// make_color(minirt->cylinder->rgb, &minirt->cylinder->rgb.color);
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
			color = 0; // get_ambient_color(minirt->ambient->rgb, minirt->ambient->ratio);
			if (inter(minirt, minirt->ray, &scene->color))
			{
				color = prod_colors(scale_colors(minirt->ambient->rgb, minirt->ambient->ratio), scene->color);
				color = c_add(color, !is_shadow(minirt) * compute_light(minirt, minirt->ray, scene->color));
				// printf("%d\n", color);
				// color = scene->color;
			}
			mlx_pixel_put(minirt->window->mlx ,minirt->window->win, coo.x, coo.y, color);
			coo.x++;
			minirt->x_angle++;
		}
		coo.y++;
		minirt->y_angle--;
	}
}