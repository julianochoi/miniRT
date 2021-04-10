/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 01:30:25 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/07 16:25:00 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# define BMP_FILENAME "minirt"

typedef struct	s_bmp_h
{
	uint8_t		bmp_type[2];
	int			file_size;
	int16_t		reserved1;
	int16_t		reserved2;
	uint32_t	offset;
}				t_bmp_h;

typedef struct	s_dib_h
{
	uint32_t	size_header;
	uint32_t	width;
	uint32_t	height;
	int16_t		planes;
	int16_t		bit_count;
	uint32_t	compr;
	uint32_t	img_size;
	uint32_t	ppm_x;
	uint32_t	ppm_y;
	uint32_t	clr_used;
	uint32_t	clr_important;
}				t_dib_h;

char			*change_filepath(uint32_t i);
void			save_bmp(t_main *env);
void			bmp_padding(t_main *env, int fd);

#endif
