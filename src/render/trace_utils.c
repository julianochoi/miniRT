/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:04:44 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 20:04:14 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3	pixel_pos(double fov, t_res res, int x, int y)
{
	t_v3	pos;
	double	scale;
	double	pixel_x;
	double	pixel_y;
	double	ratio;

	ratio = (double)res.size_x / (double)res.size_y;
	scale = tan(fov * M_PI / 360.);
	pixel_x = ((2.0 * (x + 0.5) / (double)res.size_x) - 1.) * ratio * scale;
	pixel_y = (1. - (2.0 * (y + 0.5) / (double)res.size_y)) * scale;
	pos = gen_v3(pixel_x, pixel_y, 1.);
	return (pos);
}

void	init_ray(t_cam *cam, t_ray *ray, t_v3 pixel_coord)
{
	ray->d = v3_mat_mult(cam->cam_to_world, pixel_coord);
	ray->d = v3_norm(ray->d);
	ray->t_nearest = INFINITY;
	ray->color = gen_color(0, 0, 0);
	ray->hit_p = gen_v3(0, 0, 0);
	ray->n = gen_v3(0, 0, 0);
}

void	fill_pixel_array(t_img *img, t_rgb color, int x, int y)
{
	int		i;

	i = (x + img->size_x * y) * 4;
	color = color_scalar(255.0, color);
	color = rescale_color(color, 0., 255.);
	img->pixels[i + 2] = (uint8_t)color.r;
	img->pixels[i + 1] = (uint8_t)color.g;
	img->pixels[i + 0] = (uint8_t)color.b;
	img->pixels[i + 3] = 0;
}
