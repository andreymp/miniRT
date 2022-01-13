/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:43:06 by jobject           #+#    #+#             */
/*   Updated: 2022/01/13 17:44:02 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	push_plane(t_plane	**plane, t_plane	*new)
{
	t_plane	*tmp;

	if (!*plane)
		*plane = new;
	else
	{
		tmp = *plane;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	push_cylinder(t_cylinder	**cylinder, t_cylinder	*new)
{
	t_cylinder	*tmp;

	if (!*cylinder)
		*cylinder = new;
	else
	{
		tmp = *cylinder;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	push_sphere(t_sphere	**sphere, t_sphere	*new)
{
	t_sphere	*tmp;

	if (!*sphere)
		*sphere = new;
	else
	{
		tmp = *sphere;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static float	ret_value(float value, char min)
{
	if (min == '-')
		return (-value);
	return (value);
}

float	ft_atof(char	*str)
{
	int		integral;
	float	fraction;
	float	value;
	int		i;

	i = 0;
	if (*str == '-')
		i++;
	integral = ft_atoi(str + i);
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;
	if (*(str + i) == ' ' || *(str + i) == ',')
		return (ret_value((float) integral, *str));
	value = (float) integral;
	fraction = 0.1;
	i++;
	while (*(str + i) && ft_isdigit(*(str + i)))
	{
		value += (*(str + i++) - '0') * fraction;
		fraction *= 0.1;
	}
	if (*str == '-')
		value *= -1.0;
	return (value);
}
