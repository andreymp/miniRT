/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:13:04 by jobject           #+#    #+#             */
/*   Updated: 2022/01/12 15:26:32 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/miniRT.h"

t_coo	calc(t_coo ray, float f)
{
	t_coo	c;

	c = vec_mul(ray, f);
	c = vec_add(ray, c);
	return (c);
}

t_roots	find_root(t_minirt *rt, t_coo ray, t_coo oc)
{
	t_coeff	c;
	t_roots	r;
	float	disc;

	r.exist = true;
	c.a = vec_dot_product(ray, ray) - vec_dot_product(rt->cylinder->vector, ray)
		* vec_dot_product(rt->cylinder->vector, ray);
	c.b = 2 * (vec_dot_product(oc, ray)
			- vec_dot_product(rt->cylinder->vector, oc)
			* vec_dot_product(rt->cylinder->vector, ray));
	c.c = vec_dot_product(oc, oc) - vec_dot_product(rt->cylinder->vector, oc)
		* vec_dot_product(rt->cylinder->vector, oc) - (rt->cylinder->diameter
			* rt->cylinder->diameter / 4);
	disc = dis(c.a, c.b, c.c);
	if (disc < 0)
	{
		r.exist = false;
		return (r);
	}
	r.t1 = (-c.b + sqrtf(disc)) / (2 * c.a);
	r.t2 = (-c.b - sqrtf(disc)) / (2 * c.a);
	return (r);
}

bool	cylinder_intersection(t_minirt *rt, t_cylinder	*cy, t_coo ray, int *color)
{
	t_roots	roots;
	t_coo	oc;
	t_coo	inter[2];
	float	h;

	vec_sub(cy->coo, rt->camera->coo, &oc);
	roots = find_root(rt, ray, oc);
	if (roots.exist == false)
		return (false);
	vec_sub(calc(ray, roots.t1), cy->coo, &inter[0]);
	vec_sub(calc(ray, roots.t2), cy->coo, &inter[1]);
	h = vec_dot_product(inter[0], cy->vector);
	if (h > cy->height / 2 || h < -cy->height / 2)
		roots.t1 = 0;
	h = vec_dot_product(inter[1], cy->vector);
	if (h > cy->height / 2 || h < -cy->height / 2)
		roots.t2 = 0;
	roots.t1 = ft_min(roots.t1, roots.t2);
	if (roots.t1 > 0)
		make_color(cy->rgb, color);
	return (roots.t1 > 0);
}
