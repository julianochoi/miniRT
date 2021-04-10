/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:24:42 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/04 19:42:00 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

void	print_res(t_main *env);
void	print_amb(t_main *env);
void	print_cams(t_main *env);
void	print_lights(t_main *env);
void	print_images(t_main *env);

void	print_v3(char *str, int precision, t_v3 v);
void	print_ray(int precision, t_ray ray);
void	print_v4(char *str, int precision, t_v4 v);
void	print_m3(int prec, t_m3 m);
void	print_m4(int prec, t_m4 m);

void	print_sphere(t_obj *obj);
void	print_plane(t_obj *obj);
void	print_square(t_obj *obj);
void	print_cylinder(t_obj *obj);
void	print_triangle(t_obj *obj);

void	print_col(char *str, int precision, t_rgb tuple);
void	print_objs(t_main *env);
void	print_main(t_main *env);

#endif
