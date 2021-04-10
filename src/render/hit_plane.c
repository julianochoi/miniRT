/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 01:05:39 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/05 01:05:59 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_plane(t_v3 plane_point, t_v3 normal, t_ray *r, double *t)
{
	double	t1;
	t_v3	x;

	x = v3_sub(plane_point, r->o);
	if (!fp_is_equal(v3_dot(r->d, normal), 0.0))
	{
		t1 = (v3_dot(x, normal) / v3_dot(r->d, normal));
		if (t1 > 0)
		{
			*t = t1;
			return (true);
		}
	}
	return (false);
}
