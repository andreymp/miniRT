/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:21:40 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 20:43:03 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	plane_intersection(t_minirt	*minirt, t_coo	vec)
{
	float	denom;
	float	t;
	t_coo	cam_pl;

	vec_sub(minirt->camera->coo, minirt->plane->coo, &cam_pl);
	denom = vec_dot_product(cam_pl, vec);
	if (fabsf(denom) > 1e-6)
	{
		vec_sub(minirt->plane->coo, minirt->ray, &vec);
		t = vec_dot_product(vec, cam_pl);
		return (t >= 0);
	}
	return (false);
}
