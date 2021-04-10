/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 01:28:49 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/04/07 16:56:18 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	create_bmpfileheader(t_bmp_h *header, int size)
{
	ft_bzero(header, sizeof(t_bmp_h));
	header->bmp_type[0] = 'B';
	header->bmp_type[1] = 'M';
	header->file_size = 54 + size;
	header->reserved1 = 0;
	header->reserved2 = 0;
	header->offset = 54;
}

static void	create_bmpdibheader(t_main *env, t_dib_h *header, int size)
{
	ft_bzero(header, sizeof(t_dib_h));
	header->size_header = sizeof(t_dib_h);
	header->width = env->res.size_x;
	header->height = env->res.size_y;
	header->planes = 1;
	header->bit_count = 24;
	header->compr = 0;
	header->img_size = size;
	header->ppm_x = 3780;
	header->ppm_y = 3780;
	header->clr_used = 0;
	header->clr_important = 0;
}

static void	write_bmpheaders(t_main *env, int fd)
{
	t_bmp_h	file_header;
	t_dib_h	dib_header;
	int		size;

	size = env->res.size_x * env->res.size_y * 4;
	create_bmpfileheader(&file_header, size);
	create_bmpdibheader(env, &dib_header, size);
	write(fd, &(file_header.bmp_type), 2);
	write(fd, &(file_header.file_size), 4);
	write(fd, &(file_header.reserved1), 2);
	write(fd, &(file_header.reserved2), 2);
	write(fd, &(file_header.offset), 4);
	write(fd, &(dib_header.size_header), 4);
	write(fd, &(dib_header.width), 4);
	write(fd, &(dib_header.height), 4);
	write(fd, &(dib_header.planes), 2);
	write(fd, &(dib_header.bit_count), 2);
	write(fd, &(dib_header.compr), 4);
	write(fd, &(dib_header.img_size), 4);
	write(fd, &(dib_header.ppm_x), 4);
	write(fd, &(dib_header.ppm_y), 4);
	write(fd, &(dib_header.clr_used), 4);
	write(fd, &(dib_header.clr_important), 4);
}

static void	write_bmpdata(t_main *env, int fd, t_img *img)
{
	int		x;
	int		y;
	int		*pixel;
	int		i;
	int		progress;

	y = env->res.size_y - 1;
	while (y > -1)
	{
		x = 0;
		while (x < env->res.size_x)
		{
			i = (x + env->res.size_x * y) * 4;
			pixel = (int *)(img->pixels + i);
			if (write(fd, pixel, 3) < 0)
				exit_error(env, (char *)strerror(errno));
			x++;
		}
		bmp_padding(env, fd);
		progress = ft_percent((env->res.size_y - y), env->res.size_y);
		ft_printf("\rSaving rendered image in BMP format... %d%%", progress);
		y--;
	}
}

void		save_bmp(t_main *env)
{
	int			fd;
	uint32_t	i;
	t_img		*current;
	char		*filepath;

	i = 1;
	current = env->imgs;
	while (i <= env->cam_count)
	{
		filepath = change_filepath(i);
		fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 00644);
		if (!fd)
			exit_error(env, (char *)strerror(errno));
		write_bmpheaders(env, fd);
		write_bmpdata(env, fd, current);
		close(fd);
		ft_printf("\nImage saved as '%s' in working dir.\n", filepath);
		free_and_null(filepath);
		current = current->next;
		i++;
	}
	exit_success(env);
}
