/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:30:18 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/04 20:01:55 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_sphere(t_obj *obj)
{
	printf("\tid:[SPHERE]\n");
	print_v3("\tsph.c", 1, ((t_sph *)obj->data)->c);
	printf("\tsph.r:\t\t[%.1lf]\n", ((t_sph *)obj->data)->r);
	print_col("\tcolor", 3, ((t_sph *)obj->data)->color);
}

void	print_plane(t_obj *obj)
{
	printf("\tid:[PLANE]\n");
	print_v3("\tplane.c", 1, ((t_pl *)obj->data)->c);
	print_v3("\tplane.n", 1, ((t_pl *)obj->data)->n);
	print_col("\tcolor", 3, ((t_pl *)obj->data)->color);
}

void	print_square(t_obj *obj)
{
	printf("\tid:[SQUARE]\n");
	print_v3("\tsquare.c", 1, ((t_sq *)obj->data)->c);
	print_v3("\tsquare.n", 1, ((t_sq *)obj->data)->n);
	printf("\tsq.side:\t[%.1lf]\n", ((t_sq *)obj->data)->side);
	print_col("\tcolor", 3, ((t_sq *)obj->data)->color);
}

void	print_cylinder(t_obj *obj)
{
	printf("\tid:[CYLINDER]\n");
	print_v3("\tcylinder.b1", 1, ((t_cy *)obj->data)->b1);
	print_v3("\tcylinder.d", 1, ((t_cy *)obj->data)->d);
	printf("\tradius:\t\t[%.1lf]\n", ((t_cy *)obj->data)->r);
	printf("\theight:\t\t[%.1lf]\n", ((t_cy *)obj->data)->h);
	print_col("\tcolor", 3, ((t_cy *)obj->data)->color);
}

void	print_triangle(t_obj *obj)
{
	printf("\tid:[TRIANGLE]\n");
	print_v3("\ttriangle.p1", 1, ((t_tr *)obj->data)->p1);
	print_v3("\ttriangle.p2", 1, ((t_tr *)obj->data)->p2);
	print_v3("\ttriangle.p3", 1, ((t_tr *)obj->data)->p3);
	print_v3("\ttriangle.n", 1, ((t_tr *)obj->data)->n);
	print_col("\tcolor", 3, ((t_tr *)obj->data)->color);
}
