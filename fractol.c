/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:57 by marherra          #+#    #+#             */
/*   Updated: 2023/12/08 16:22:10 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_fractal fractal;
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || \
				(ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
//		data_init(&fractal);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

