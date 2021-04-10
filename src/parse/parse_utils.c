/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 01:04:02 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/03 23:02:39 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	skip_blank(t_main *env, char **s)
{
	if (!ft_isblank(**s))
	{
		exit_error(env, "Spacing badly formatted.");
		return (0);
	}
	while (ft_isblank(**s))
		(*s)++;
	return (1);
}

bool	skip_char(char **s, int c)
{
	if ((**s) == c)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

void	skip_digits(char **s)
{
	while (ft_isdigit(**s))
		(*s)++;
}
