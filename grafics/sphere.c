/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:33:31 by jobject           #+#    #+#             */
/*   Updated: 2022/01/07 15:52:23 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

float dis (float a, float b, float c)
{
    return (b * b - 4 * a * c);
}

float ft_min(float t1, float t2)
{
    if (t1 > E && t2 > E)
    {
        if (t1 > t2)
            return (t2);
        else
            return(t1);
    }
    else if (t1 > E)
        return (t1);
    else if (t2 > E)
        return (t2);
    return (0);
}

bool	sphere_intersection(t_coo vec, t_minirt *rt)
{
    t_coo oc;
    t_coeff c;
    float disc;
    float t1;
    float t2;

    vec_sub(rt->camera->coo, rt->sphere->coo ,&oc);
    c.a = vec_dot_product(vec, vec);
    c.b = 2 * (vec_dot_product(oc, vec));
    c.c = vec_dot_product(oc, oc) - (rt->sphere->diameter/2 * rt->sphere->diameter/2);
    disc = dis(c.a, c.b, c.c);
    // printf("disc = %f\n", disc);
    // printf("a = %f b = %f c = %f\n", c.a, c.b, c.c);
    if (disc < 0)
        return (false);
    t1 = (-c.b + sqrtf(disc)) / (2 * c.a);
    // printf("t1 = %f\n", t1);
    t2 = (-c.b - sqrtf(disc)) / (2 * c.a);
    t1 = ft_min(t1, t2);
    return (t1 >= 0);
}
