/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:56:27 by marherra          #+#    #+#             */
/*   Updated: 2023/12/08 16:43:00 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void data_init(t_fractal *fractal)
{
// 	printf("2 --- %p\n" , &fractal);
	fractal->escape_value = 4;
	fractal->iterations_definition = 300;
}

void fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection	= mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										WIDTH,
										HEIGHT,
										fractal->name);
	if (NULL == fractal ->mlx_window)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		//mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
		//free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (NULL ==  fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	//	mlx_clear_window(fractal->mlx_connection, fractal->mlx_window);
	//	free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
												&fractal->img.bpp,
												&fractal->img.line_len,
												&fractal->img.endian);
	data_init(fractal);
}
