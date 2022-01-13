/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:34:07 by jobject           #+#    #+#             */
/*   Updated: 2022/01/13 18:00:10 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	check_input(int argc, char	**argv)
{
	int	len;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments", 2);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 't' || argv[1][len - 2] != 'r'
		|| argv[1][len - 3] != '.')
	{
		ft_putendl_fd("File should have format \'.rt\'", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char	**argv)
{
	t_minirt	*minirt;

	check_input(argc, argv);
	minirt = minirt_init();
	parse_file(argv[1], &minirt);
	if (!total_check(minirt))
		exit_fatal(minirt, "Error");
	minirt->window = win_init();
	if (!minirt->window)
		exit_fatal(minirt, "Allocation failed");
	mini_rt(minirt);
	return (0);
}
