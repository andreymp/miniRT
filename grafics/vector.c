/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:32:31 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 13:36:07 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_coo	*new_vector(float x, float y, float z)
{
    t_coo	*vec;

    vec = (t_coo *)malloc(sizeof(t_coo));
    if (!vec)
        return (NULL);
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return (vec);
}

t_coo	*vec_sub(t_coo	*vec1, t_coo	*vec2)
{
    return (new_vector(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z));
}

float	vec_length(t_coo	*vec)
{
    return (sqrtf((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z)));
}

void    vec_normalized(t_coo	*vec)
{
    float	length;

    length = vec_length(vec);
    vec->x /= length;
    vec->y /= length;
    vec->z /= length;
}

float	vec_dot_product(t_coo	*vec1, t_coo	*vec2)
{
    return ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
}
