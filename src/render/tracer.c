/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 04:27:44 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/04 23:46:05 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	trace_ray(t_main *env, t_cam *cam, t_img *img)
{
	t_ray	ray;
	t_v3	pixel;
	int		x;
	int		y;
	int		progress;

	cam->cam_to_world = cam_matrix(cam);
	ray.o = cam->o;
	y = 0;
	while (y < env->res.size_y)
	{
		x = 0;
		while (x < env->res.size_x)
		{
			pixel = pixel_pos(cam->fov, env->res, x, y);
			init_ray(cam, &ray, pixel);
			shader(env, &ray);
			fill_pixel_array(img, ray.color, x, y);
			x++;
		}
		y++;
		progress = ft_percent(y, env->res.size_y);
		ft_printf("\rRendering image... %d%%", progress);
	}
	ft_printf("\n");
}
