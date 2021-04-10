/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:55:10 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/06 22:57:42 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

typedef enum		e_objid
{
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	TRIANGLE
}					t_objid;

typedef struct		s_obj
{
	t_objid			id;
	void			*data;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_sph
{
	t_v3			c;
	double			r;
	t_rgb			color;
}					t_sph;

typedef struct		s_pl
{
	t_v3			c;
	t_v3			n;
	t_rgb			color;
}					t_pl;

typedef struct		s_sq
{
	t_v3			c;
	t_v3			n;
	double			side;
	t_rgb			color;
}					t_sq;

typedef struct		s_cy
{
	t_v3			b1;
	t_v3			b2;
	t_v3			d;
	double			r;
	double			h;
	t_rgb			color;
}					t_cy;

typedef struct		s_tr
{
	t_v3			p1;
	t_v3			p2;
	t_v3			p3;
	t_v3			n;
	t_rgb			color;
}					t_tr;

void				ray_sph_int(t_ray r, t_sph *sph, double *t);
t_obj				*create_obj(void *shape_data, t_objid shape_id);
void				del_objs(t_obj **objs);

#endif
