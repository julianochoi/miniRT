/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:04:40 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 22:58:14 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	parse(t_main *env, const char *filepath);
void	check_max_display(t_main *env);
void	parse_resolution(t_main *env, char **line);
void	parse_ambient(t_main *env, char **line);
void	parse_camera(t_main *env, char **line);
void	parse_light(t_main *env, char **line);

void	parse_sphere(t_main *env, char **line);
void	parse_plane(t_main *env, char **line);
void	parse_square(t_main *env, char **line);
void	parse_cylinder(t_main *env, char **line);
void	parse_triangle(t_main *env, char **line);

bool	skip_blank(t_main *env, char **s);
bool	skip_char(char **s, int c);
void	skip_digits(char **s);

int		parse_integer(t_main *env, char **line);
double	parse_double(t_main *env, char **line);
t_rgb	parse_color(t_main *env, char **line);
t_v3	parse_v3(t_main *env, char **line);

#endif
