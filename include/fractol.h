/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <elwilks@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:32:24 by elwilks           #+#    #+#             */
/*   Updated: 2026/03/15 18:49:45 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>

# define WIDTH  800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_complex
{
	double		r;
	double		i;
}	t_complex;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			fractal_type;
	double		julia_r;
	double		julia_i;
}	t_fractol;

/* render.c */
void	render(t_fractol *f);
int		get_color(int iter, int max_iter);

/* mandelbrot.c */
int		mandelbrot(t_complex c, int max_iter);

/* julia.c */
int		julia(t_complex z, t_complex c, int max_iter);

/* hooks.c */
void	setup_hooks(t_fractol *f);

/* utils.c */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str);
double	ft_atof(const char *str);

#endif
