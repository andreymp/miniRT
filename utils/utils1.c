/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:43:06 by jobject           #+#    #+#             */
/*   Updated: 2022/01/06 16:14:21 by jobject          ###   ########.fr       */
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

bool	check_float(char	*str)
{
	int	i;

	i = 0;
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;
	if (!*(str + i))
		return (false);
	if (*(str + i) == ' ' || *(str + i) == ',')
		return (true);
	if (*(str + i++) == '.')
	{
		while (*(str + i) && ft_isdigit(*(str + i)))
			i++;
		if (!*(str + i))
			return (false);
		if (*(str + i) == ' ' || *(str + i) == ',')
			return (true);
	}
	return (false);
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
		return ((float) integral);
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
