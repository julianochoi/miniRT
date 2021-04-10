/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:25:13 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/04 22:32:21 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_res(t_main *env)
{
	printf("\nResolution:\n");
	printf("\tis_declared:\t[%d]\n", env->res.is_declared);
	printf("\tsize_x:\t\t[%d]\n", env->res.size_x);
	printf("\tsize_y:\t\t[%d]\n", env->res.size_y);
}

void	print_amb(t_main *env)
{
	printf("\nAmbient:\n");
	printf("\tis_declared:\t[%d]\n", env->amb.is_declared);
	printf("\tratio:\t\t[%.1lf]\n", env->amb.ratio);
	print_col("\tcolor", 3, env->amb.color);
}

void	print_cams(t_main *env)
{
	void	*cursor;

	printf("\nCameras:\n");
	printf("cam_count:\t\t[%u]\n", (env->cam_count));
	cursor = (t_cam *)env->cams;
	while (cursor)
	{
		print_v3("\tcam.o", 1, ((t_cam *)cursor)->o);
		print_v3("\tcam.d", 1, ((t_cam *)cursor)->d);
		printf("\tfov:\t\t[%.1lf]\n", ((t_cam *)cursor)->fov);
		print_m3(1, ((t_cam *)cursor)->cam_to_world);
		printf("\tnext cam ptr:\t[%p]\n\n", ((t_cam *)cursor)->next);
		cursor = ((t_cam *)cursor)->next;
	}
}

void	print_lights(t_main *env)
{
	void *cursor;

	printf("Lights:\n");
	cursor = (t_light *)env->lights;
	while (cursor)
	{
		print_v3("\tlight.o", 1, ((t_light *)cursor)->o);
		printf("\tlight ratio:\t[%.1lf]\n", ((t_light *)cursor)->ratio);
		print_col("\tcolor", 3, ((t_light *)cursor)->color);
		printf("\tnext light ptr:\t[%p]\n\n", ((t_light *)cursor)->next);
		cursor = ((t_light *)cursor)->next;
	}
}

void	print_images(t_main *env)
{
	t_img		*current;
	uint32_t	counter;

	printf("\nImages:\n");
	counter = env->cam_count;
	current = env->imgs;
	while (counter > 0)
	{
		printf("\tcurrent img:\t[%p]\n", current);
		printf("\tsize_x:\t\t[%d]\n", current->size_x);
		printf("\tsize_y:\t\t[%d]\n", current->size_y);
		printf("\timg ptr:\t[%p]\n", current->img_ptr);
		printf("\tbpp:\t\t[%d]\n", current->bpp);
		printf("\tsize_line:\t[%d]\n", current->size_line);
		printf("\tendian:\t\t[%d]\n", current->endian);
		printf("\tnext img:\t[%p]\n\n", current->next);
		current = current->next;
		counter--;
	}
}
