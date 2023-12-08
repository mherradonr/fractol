/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:11:20 by marherra          #+#    #+#             */
/*   Updated: 2023/12/08 16:38:08 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include "mlx/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fracol julia <value_1> <value_2>\"\n"

#define WIDTH 800
#define HEIGHT 800
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define Rojo 0xFF0000
#define Verde 0x00FF00
#define Azul 0x0000FF
#define Amarillo 0xFFFF00
#define Rosa 0xFFC0CB
#define Morado 0x800080
#define Naranja 0xFFA500
#define Marrón 0xA52A2A
#define Gris 0x808080
#define Púrpura 0xB10DC9
#define Turquesa 0x00CED1
#define Verdel 0x00FF00
#define Rubí 0xE0115F
#define Coral 0xFF6F61

typedef struct s_complex
{
	double x;
	double y;
}		t_complex;

typedef struct s_img
{
	void *img_ptr;
	char *pixels_ptr;
	int	bpp;
	int endian;
	int line_len;
}		t_img;

typedef struct s_fractal
{
	char *name;
	void *mlx_connection;
	void *mlx_window;
	t_img img;
	double escape_value;
	int iterations_definition;
}			t_fractal;

void fractal_init(t_fractal *fractal);
int	ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex square_complex(t_complex z);
t_complex sum_complex(t_complex z1, t_complex z2);
void fractal_render(t_fractal *fractal);
int	ft_strlen(const char *str);
void data_init(t_fractal *fractal);

#endif
