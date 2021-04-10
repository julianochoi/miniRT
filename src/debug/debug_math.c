/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:05:49 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/03 23:36:47 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_v3(char *str, int precision, t_v3 v)
{
	printf("%s.x:\t[%.*lf]\n", str, precision, v.x);
	printf("%s.y:\t[%.*lf]\n", str, precision, v.y);
	printf("%s.z:\t[%.*lf]\n", str, precision, v.z);
}

void	print_ray(int precision, t_ray ray)
{
	print_v3("ray.o", precision, ray.o);
	print_v3("ray.d", precision, ray.d);
}

void	print_v4(char *str, int precision, t_v4 v)
{
	printf("%s.x:\t[%.*lf]\n", str, precision, v.x);
	printf("%s.y:\t[%.*lf]\n", str, precision, v.y);
	printf("%s.z:\t[%.*lf]\n", str, precision, v.z);
	printf("%s.w:\t[%.*lf]\n", str, precision, v.w);
}

void	print_m3(int prec, t_m3 m)
{
	printf("|%1$.*4$f\t%2$.*4$f\t%3$.*4$f|\n", m.c1.x, m.c2.x, m.c3.x, prec);
	printf("|%1$.*4$f\t%2$.*4$f\t%3$.*4$f|\n", m.c1.y, m.c2.y, m.c3.y, prec);
	printf("|%1$.*4$f\t%2$.*4$f\t%3$.*4$f|\n", m.c1.z, m.c2.z, m.c3.z, prec);
}

void	print_m4(int prec, t_m4 m)
{
	printf("|%1$.*3$f\t%2$.*3$f\t", m.c1.x, m.c2.x, prec);
	printf("%1$.*3$f\t%2$.*3$f|\n", m.c3.x, m.c4.x, prec);
	printf("|%1$.*3$f\t%2$.*3$f\t", m.c1.y, m.c2.y, prec);
	printf("%1$.*3$f\t%2$.*3$f|\n", m.c3.y, m.c4.y, prec);
	printf("|%1$.*3$f\t%2$.*3$f\t", m.c1.z, m.c2.z, prec);
	printf("%1$.*3$f\t%2$.*3$f|\n", m.c3.z, m.c4.z, prec);
	printf("|%1$.*3$f\t%2$.*3$f\t", m.c1.w, m.c2.w, prec);
	printf("%1$.*3$f\t%2$.*3$f|\n", m.c3.w, m.c4.w, prec);
}
