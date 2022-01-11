/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:12:30 by jobject           #+#    #+#             */
/*   Updated: 2022/01/11 20:30:35 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static float	count_diffuse(t_minirt	*minirt, t_coo vec)
{
	t_coo	nl;
	float	acos_angle;
	float	diffuse;
	
	vec_sub(minirt->light->coo, vec, &nl);
	acos_angle = acosf(vec_dot_product(nl, vec) / (vec_length(vec) * vec_length(nl)));
	diffuse = 0;
	if (acos_angle > 0)
		diffuse = cosf(M_PI - acos_angle) * minirt->light->bright;
	return (diffuse);
}

static t_coo	reflection(t_coo i, t_coo n)
{
	float	prod;

	prod = -2.0 * vec_dot_product(i, n);
	return  (vec_add(i, vec_mul(n, prod)));
} 

float	count_specular(t_minirt	*minirt, t_coo vec)
{
	t_coo	nc;
	t_coo	reflect;
	float	acos_angle;
	float	specularity;

	vec_sub(minirt->camera->coo, vec, &nc);
	reflect = vec_mul(reflection(vec_mul(nc, -1.0), vec), -1);
	acos_angle = acosf(vec_dot_product(nc, reflect) / (vec_length(reflect) * vec_length(nc)));
	specularity = 0;
	if (acos_angle > 0)
		specularity = powf(cosf(M_PI - acos_angle), 32);
	return (specularity * 0.5);
}

float	compute_light(t_minirt	*minirt, t_coo	vec, int color)
{
	int	diff;
	int	spec;

	vec.x *= vec.len;
	vec.y *= vec.len;
	vec.z *= vec.len;
	diff = scale_int(color, count_diffuse(minirt, vec));
	spec = scale_int(color, prod_colors(0x0ffffff, count_specular(minirt, vec)));
	return (c_add(diff, spec));
}