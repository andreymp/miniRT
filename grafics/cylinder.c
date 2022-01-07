/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:13:04 by jobject           #+#    #+#             */
/*   Updated: 2022/01/07 15:04:40 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/miniRT.h"

static bool	disk_intersection(t_minirt	*minirt, t_coo	vec, bool	upper)
{
	t_coo	cam_cy;
    t_coeff coeff;
	float	discr;
	float	t[3];
	t_coo	copy;
	
	new_vector(minirt->cylinder->coo.x, minirt->cylinder->coo.y, minirt->cylinder->coo.z, &copy);
	if (upper)
		copy.y -= minirt->cylinder->height;
	vec_sub(minirt->camera->coo, copy, &cam_cy);
	coeff.a = vec_dot_product(vec, vec);
	coeff.b = 2 * vec_dot_product(cam_cy, vec);
	coeff.c = vec_dot_product(cam_cy, cam_cy) - powf(minirt->cylinder->diameter / 2, 2);
	discr = powf(coeff.b, 2) - 4 * coeff.a * coeff.c;
	if (discr < 0)
		return (false);
	t[0] = (-coeff.b - sqrtf(discr)) / (2 * coeff.a);
	t[1] = (-coeff.b + sqrtf(discr)) / (2 * coeff.a);
	t[2] = ft_min(t[0], t[1]);
	if (!upper)
		return (t[2] >= 0 && t[2] <= minirt->cylinder->height);
	return (t[2] >= 0);
}

bool	cylinder_intersection(t_minirt	*minirt, t_coo	vec)
{
	
	return (disk_intersection(minirt, vec, false) || disk_intersection(minirt, vec, true));
}