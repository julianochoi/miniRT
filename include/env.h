/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:03:18 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 16:19:07 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct		s_res
{
	bool			is_declared;
	int				size_x;
	int				size_y;
}					t_res;

typedef struct		s_amb
{
	bool			is_declared;
	double			ratio;
	t_rgb			color;
}					t_amb;

typedef struct		s_cam
{
	t_v3			o;
	t_v3			d;
	double			fov;
	t_m3			cam_to_world;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_v3			o;
	double			ratio;
	t_rgb			color;
	struct s_light	*next;
}					t_light;

typedef struct		s_img
{
	int				size_x;
	int				size_y;
	void			*img_ptr;
	char			*pixels;
	int				bpp;
	int				size_line;
	int				endian;
	struct s_img	*next;
}					t_img;

typedef struct		s_main
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*title;
	t_img			*imgs;
	t_res			res;
	t_amb			amb;
	uint32_t		cam_count;
	t_cam			*cams;
	t_light			*lights;
	t_obj			*objs;
}					t_main;

t_cam				*malloc_cam(t_main *env);
void				add_cam(t_cam **cams, t_cam *new_cam);
void				del_cams(t_cam **cams);
t_m3				cam_matrix(t_cam *cam);

void				add_img(t_img **imgs, t_img *new_img);
void				del_imgs(void *mlx_ptr, t_img **imgs);
void				loop_img_list(t_img *imgs);
t_img				create_img(t_main *env);
t_img				*malloc_img(t_main *env);
void				free_img(void *mlx_ptr, t_img *to_free);

void				init_amb(t_amb *amb);
void				init_res(t_res *res);
void				init_minirt(t_main *env);
void				quit_minirt(t_main *env);

t_light				*malloc_light(t_main *env);
void				add_light(t_light **lights, t_light *new_light);
void				del_lights(t_light **lights);

void				add_obj_to_render(t_main *env, void *to_add, t_objid objid);

#endif
