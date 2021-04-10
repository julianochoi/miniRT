/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:22:57 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 23:05:22 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_integer(t_main *env, char **line)
{
	int			num;

	if ((**line) == '-' || ft_isdigit(**line))
	{
		num = ft_atoi(*line);
		skip_char(line, '-');
		skip_digits(line);
	}
	else
		exit_error(env, "Integer badly formatted.");
	return (num);
}

double	parse_double(t_main *env, char **line)
{
	double		num;

	if (!ft_isdigit(**line) && **line != '+' && **line != '-')
		exit_error(env, ERR_BAD_COORD);
	num = ft_atof(*line, line);
	return (num);
}

t_rgb	parse_color(t_main *env, char **line)
{
	t_rgb	color;

	color.r = (double)parse_integer(env, line);
	if (!skip_char(line, ','))
		exit_error(env, ERR_NO_SEP);
	color.g = (double)parse_integer(env, line);
	if (!skip_char(line, ','))
		exit_error(env, ERR_NO_SEP);
	color.b = (double)parse_integer(env, line);
	if ((color.r < 0) || (color.g < 0) || (color.b < 0)
	|| (color.r > 255) || (color.g > 255) || (color.b > 255))
		exit_error(env, "Color out of range [0,255].");
	color = color_scalar((1.0 / 255.0), color);
	return (color);
}

t_v3	parse_v3(t_main *env, char **line)
{
	t_v3		vec;

	vec.x = parse_double(env, line);
	if (!skip_char(line, ','))
		exit_error(env, ERR_NO_SEP);
	vec.y = parse_double(env, line);
	if (!skip_char(line, ','))
		exit_error(env, ERR_NO_SEP);
	vec.z = parse_double(env, line);
	return (vec);
}
