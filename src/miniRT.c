/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:19:14 by jobject           #+#    #+#             */
/*   Updated: 2022/01/13 19:10:28 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	check_float(char	*str)
{
	int	i;

	i = 0;
	if (*(str + i) == '-')
		i++;
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

void	mini_rt(t_minirt	*minirt)
{
	ray_tracing(minirt);
	mlx_loop(minirt->window->mlx);
}
