/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:12:30 by jobject           #+#    #+#             */
/*   Updated: 2022/01/13 18:09:55 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static float	count_diffuse(t_minirt	*minirt, t_coo vec)
{
	t_coo	nl;
	float	acos_angle;
	float	diffuse;

	vec_sub(minirt->light->coo, vec_mul(vec, vec.len), &nl);
	vec_normalized(&nl);
	acos_angle = vec_dot_product(nl, vec);
	diffuse = 0;
	if (acos_angle > 0.0)
		diffuse = acos_angle * minirt->light->bright / minirt->ambient->ratio;
	return (diffuse);
}

static t_coo	reflection(t_coo i, t_coo n)
{
	float	prod;

	prod = -2.0 * vec_dot_product(i, n);
	return (vec_add(i, vec_mul(n, prod)));
}

float	count_specular(t_minirt	*minirt, t_coo vec)
{
	t_coo	nc;
	t_coo	reflect;
	float	acos_angle;
	float	specularity;

	vec_sub(minirt->light->coo, vec_mul(vec, vec.len), &nc);
	vec_normalized(&nc);
	reflect = vec_mul(reflection(vec_mul(nc, -1.0), vec), -1.0);
	acos_angle = vec_dot_product(nc, reflect);
	specularity = 0;
	if (acos_angle > 0.0)
		specularity = pow(acos_angle, 32) * minirt->light->bright;
	return (specularity * 0.5);
}

float	compute_light(t_minirt	*minirt, t_coo	vec, int color)
{
	int	diff;
	int	spec;
	int	tmp;

	diff = scale_int(color, count_diffuse(minirt, vec));
	tmp = count_specular(minirt, vec);
	spec = c_add(scale_int(0x0ffffff, count_specular(minirt, vec)), color);
	return (diff);
}
