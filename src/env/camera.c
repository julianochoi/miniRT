/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:44:05 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/08 18:39:18 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*malloc_cam(t_main *env)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		exit_error(env, (char *)strerror(errno));
	cam->o = gen_v3(0.0, 0.0, 0.0);
	cam->d = gen_v3(0.0, 0.0, 0.0);
	cam->fov = 0.0;
	cam->cam_to_world = m3_id();
	cam->next = NULL;
	return (cam);
}

void	add_cam(t_cam **cams, t_cam *new_cam)
{
	t_cam	*cursor;

	if (!cams || !new_cam)
		return ;
	if (*cams)
	{
		cursor = *cams;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_cam;
	}
	else
		*cams = new_cam;
}

void	del_cams(t_cam **cams)
{
	t_cam	*cursor;
	t_cam	*next_node;

	if (!cams)
		return ;
	if (*cams)
	{
		cursor = *cams;
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor);
			cursor = next_node;
		}
		*cams = NULL;
	}
}

t_m3	cam_matrix(t_cam *cam)
{
	t_m3	mat;
	t_v3	up;
	t_v3	left;

	if (cam->d.y == 1.0 || cam->d.y == -1.0)
		left = gen_v3(-1.0, 0.0, 0.0);
	else
		left = v3_cross(gen_v3(0.0, 1.0, 0.0), cam->d);
	up = v3_cross(cam->d, left);
	mat.c1 = v3_scalar(-1.0, left);
	mat.c2 = gen_v3(up.x, up.y, up.z);
	mat.c3 = gen_v3(cam->d.x, cam->d.y, cam->d.z);
	return (m3_inverse(mat));
}
