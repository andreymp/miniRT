/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:32:31 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 19:52:57 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	new_vector(float x, float y, float z, t_coo	*vec)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

void	vec_sub(t_coo	vec1, t_coo	vec2, t_coo	*vec)
{
	vec->x = vec1.x - vec2.x;
    vec->y = vec1.y - vec2.y;
    vec->z = vec1.z - vec2.z;
}

float	vec_length(t_coo	vec)
{
    return (sqrtf(powf(vec.x, 2) + powf(vec.y, 2) + powf(vec.z, 2)));
}

void    vec_normalized(t_coo	*vec)
{
    float	length;

    length = vec_length(*vec);
    vec->x /= length;
    vec->y /= length;
    vec->z /= length;
}

float	vec_dot_product(t_coo	vec1, t_coo	vec2)
{
    return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}
