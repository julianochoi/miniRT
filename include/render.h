/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:42:41 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 22:13:14 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define SPECULAR_COEF 200

void	render(t_main *env, bool save);

void	trace_ray(t_main *env, t_cam *cam, t_img *img);
t_v3	pixel_pos(double fov, t_res res, int x, int y);
void	init_ray(t_cam *cam, t_ray *ray, t_v3 pixel_coord);
void	fill_pixel_array(t_img *img, t_rgb color, int x, int y);

void	shader(t_main *env, t_ray *ray);
t_obj	*trace_objs(t_obj *objs, t_ray *ray);
void	trace_lights(t_main *env, t_ray *ray);

bool	hit(t_obj *objs, t_ray *ray, double *t);
bool	hit_plane(t_v3 plane_point, t_v3 normal, t_ray *r, double *t);
bool	hit_sphere(t_sph *sp, t_ray *r, double *t);
bool	hit_square(t_sq *square, t_ray *ray, double *t);
bool	hit_triangle(t_tr *tr, t_ray *ray, double *t);
bool	hit_cylinder(t_cy *cy, t_ray *ray, double *t);

#endif
