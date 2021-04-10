/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_prints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:22:07 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/04 20:00:31 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_col(char *str, int precision, t_rgb tuple)
{
	printf("%s.r:\t[%.*lf]\n", str, precision, tuple.r);
	printf("%s.g:\t[%.*lf]\n", str, precision, tuple.g);
	printf("%s.b:\t[%.*lf]\n", str, precision, tuple.b);
}

void	print_objs(t_main *env)
{
	void			*cursor;
	unsigned int	id;

	printf("Objects:\n");
	cursor = (t_obj *)env->objs;
	while (cursor)
	{
		id = ((t_obj *)cursor)->id;
		if (id == SPHERE)
			print_sphere((t_obj *)cursor);
		if (id == PLANE)
			print_plane((t_obj *)cursor);
		if (id == SQUARE)
			print_square((t_obj *)cursor);
		if (id == CYLINDER)
			print_cylinder((t_obj *)cursor);
		if (id == TRIANGLE)
			print_triangle((t_obj *)cursor);
		printf("\tnext obj ptr:\t[%p]\n\n", ((t_obj *)cursor)->next);
		cursor = ((t_obj *)cursor)->next;
	}
}

void	print_main(t_main *env)
{
	printf("title:[%s]\n", env->title);
	print_res(env);
	print_amb(env);
	print_cams(env);
	print_lights(env);
	print_objs(env);
	printf("mlx_ptr:[%p]\n", env->mlx_ptr);
	printf("win_ptr:[%p]\n", env->win_ptr);
	print_images(env);
}
