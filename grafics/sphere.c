/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:33:31 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 20:06:45 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	sphere_intersection(t_minirt	*minirt, t_coo	vec)
{
    float	b;
    float	c;
    float	discr;
    float	dist1;
	float	dist2;
    t_coo	cam_sph;

    vec_sub(minirt->camera->coo, minirt->sphere->coo, &cam_sph);
    b = 2 * vec_dot_product(cam_sph, vec);
    c = vec_dot_product(cam_sph, cam_sph) - powf(minirt->sphere->diameter / 2, 2);
    discr = powf(b, 2) - 4 * c;
	printf("%.2f %.2f %.2f\n", b, c, discr);
    if (discr < 0)
        return (false);
    dist1 = ((b * (-1.0)) - sqrtf(discr)) / 2;
	if (dist1 > 0.0)
		return (true);
	dist2 = ((b * (-1.0)) + sqrtf(discr)) / 2;
    return(false);
}
