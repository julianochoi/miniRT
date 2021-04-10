/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:12:03 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 21:57:36 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_filename(const char *filepath)
{
	size_t	fname_len;

	fname_len = ft_strlen(filepath);
	filepath += fname_len - 3;
	if (fname_len < 4 || ft_strncmp(filepath, ".rt", 3))
		print_error("File required to be .rt extension: <name.rt>");
}

static void	check_input(int ac, char **av, bool *save)
{
	if ((ac < 2) || (ac > 3))
	{
		ft_dprintf(
		STDERR_FILENO,
		"Usage: ./miniRT scene.rt [--save]\n");
		exit(EXIT_FAILURE);
	}
	check_filename(av[1]);
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save"))
			print_error("Invalid parameter: Try '--save'.");
		*save = true;
	}
}

static int	run_loop(t_main *env)
{
	mlx_loop(env->mlx_ptr);
	return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
	t_main	env;
	bool	save;

	save = false;
	check_input(ac, av, &save);
	init_minirt(&env);
	parse(&env, av[1]);
	render(&env, save);
	display(&env);
	return (run_loop(&env));
}
