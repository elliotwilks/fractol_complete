/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <elwilks@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:31:01 by elwilks           #+#    #+#             */
/*   Updated: 2026/03/12 12:05:24 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0xFF000000);
	t = (double)iter / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

static int	get_iter(t_fractol *f, t_complex c)
{
	t_complex	julia_c;

	if (f->fractal_type == 0)
		return (mandelbrot(c, MAX_ITER));
	julia_c.r = f->julia_r;
	julia_c.i = f->julia_i;
	return (julia(c, julia_c, MAX_ITER));
}

static void	render_row(t_fractol *f, int y)
{
	t_complex	c;
	int			x;
	int			iter;

	x = 0;
	while (x < WIDTH)
	{
		c.r = (x - WIDTH / 2.0) * f->zoom + f->offset_x;
		c.i = (y - HEIGHT / 2.0) * f->zoom + f->offset_y;
		iter = get_iter(f, c);
		mlx_put_pixel(f->img, x, y, get_color(iter, MAX_ITER));
		x++;
	}
}

void	render(t_fractol *f)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		render_row(f, y);
		y++;
	}
}
