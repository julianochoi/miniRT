/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_exits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:49:40 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/05 00:49:42 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(char *err_msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", err_msg);
	exit(EXIT_FAILURE);
}

void	exit_error(t_main *env, char *err_msg)
{
	quit_minirt(env);
	print_error(err_msg);
}

int		exit_success(t_main *env)
{
	quit_minirt(env);
	exit(EXIT_SUCCESS);
	return (0);
}
