/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:16:22 by jobject           #+#    #+#             */
/*   Updated: 2022/01/11 13:17:14 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_coo vec_mul(t_coo v, float t)
{
    t_coo sum;

    sum.x = v.x * t;
    sum.y = v.y * t;
    sum.z = v.z * t;
    return (sum);
}

t_coo vec_add(t_coo v1, t_coo v2)
{
    t_coo res;

    res.x = v1.x + v2.x;
    res.y = v1.y + v2.y;
    res.z = v1.z + v2.z;
    return (res);
}

t_coo   v_scale(t_coo v, float f)
{
    t_coo   res;

    new_vector(f * v.x, f * v.y, f * v.z, &res);
    return (res);
}
