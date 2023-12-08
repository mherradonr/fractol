/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:12:22 by marherra          #+#    #+#             */
/*   Updated: 2023/12/08 16:42:42 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	offset = (y * img->line_len) + (x * (img-> bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int i;
	int color;

	//primera iteracion
	i = 0;
	z.x = 0.0;
	z.y = 0.0;

	// coordenada de los pixeles y la escala mapa mandel
	c.x = map(x, -2, 2, 0, WIDTH);
	c.y = map(y, 2, -2, 0, HEIGHT);

	//cuantas veces tengo que iterar z^2 + c
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		//si la hipotenusa > 2 se escapa el punto
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, Rosa, Rubí, 0, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	//estamos dentro de mandelbrot
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void fractal_render(t_fractal *fractal)
{
	int x;
	int y;


	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}
