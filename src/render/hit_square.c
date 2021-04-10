/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 01:00:47 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/05 15:46:09 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_in_square(t_sq *square, t_v3 hit_p)
{
	t_v3	dist;
	double	border;

	dist = v3_sub(hit_p, square->c);
	border = square->side / 2.0;
	return (
		(fabs(dist.x) <= border)
		&& (fabs(dist.y) <= border)
		&& (fabs(dist.z) <= border));
}

bool		hit_square(t_sq *sq, t_ray *ray, double *t)
{
	t_v3	hit_p;

	hit_p = gen_v3(0.0, 0.0, 0.0);
	if (hit_plane(sq->c, sq->n, ray, t))
	{
		hit_p = ray_position(*ray, *t);
		return (is_in_square(sq, hit_p));
	}
	return (false);
}
